#include "pch.h"
#include "AuthenticateUserCommand.h"
#include <AuthenticateResponse/AuthenticateResponse.pb.h>
#include <sstream>
#include <iomanip>

namespace Database {
	Response::DatabaseResponse Database::AuthenticateUserCommand::Execute(TwoNet::Buffer& buffer)
	{
		Response::DatabaseResponse response;

		// Parse to Authenticate object
		Database::Authenticate authenticate;
		response = ParseToObject(authenticate, buffer);
		CHECK(response, authenticate.requestid());

		// Retrieve 
		GetUserWithEmailData userData { authenticate.email() };
		response = m_API.GetUserWithEmail(userData);
		CHECK(response, authenticate.requestid());

		// Check if row is found.
		if (!response.GetResult()->next()) {
			response.SetFailureReason(Response::FailureReason::INVALID_CREDENTIALS);
			CHECK(response, authenticate.requestid());
		}

		// Save result
		sql::ResultSet* result = response.GetResult();

		// Hash password
		std::string hashedPassword = HashPassword(authenticate.password(), result->getString(4).c_str()).data();
		std::string databasePassword = result->getString(5).c_str();
		// Compare password
		int compareResult = hashedPassword == databasePassword;

		// Return data
		if (!compareResult) {
			response.SetFailureReason(Response::FailureReason::INVALID_CREDENTIALS);
			CHECK(response, authenticate.requestid());
		}

		Database::AuthenticateResponse authenticationResponse;
		authenticationResponse.set_requestid(1);
		authenticationResponse.set_userid(1);
		authenticationResponse.set_success(true);
		authenticationResponse.set_creationdate(result->getString(2));
		authenticationResponse.set_failreason(AuthenticateResponse_FailReason_NONE);

		std::string data;
		authenticationResponse.SerializeToString(&data);
		response.SetData(data);

		return response;
	}

	Response::DatabaseResponse AuthenticateUserCommand::ParseToObject(Database::Authenticate& authenticate, TwoNet::Buffer& buffer)
	{
		const char* rawData = TwoNet::TwoProt::DeserializeData(buffer);
		return ParseTo<Database::Authenticate>(rawData, authenticate);
	}

	std::string AuthenticateUserCommand::HashPassword(std::string rawPassword, std::string salt)
	{
		std::string saltedPassword = salt + rawPassword;
		std::vector<unsigned char> hashedPassword(SHA256_DIGEST_LENGTH);

		SHA256((const unsigned char*)saltedPassword.c_str(), saltedPassword.length(), hashedPassword.data());

		std::stringstream ss;
		for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
			ss << std::hex << std::setw(2) << std::setfill('0') << (int)hashedPassword[i];
		}
		return ss.str();
	}

	void AuthenticateUserCommand::SetCreateUserFailData(Response::DatabaseResponse& response, long requestID)
	{
		// Check which error
		Database::AuthenticateResponse_FailReason reason = AuthenticateResponse_FailReason_NONE;

		switch (response.GetFailureReason()) {
			case Response::FailureReason::NO_CONNECTION: reason = AuthenticateResponse_FailReason_INTERNAL_SERVER_ERROR;  break;
			case Response::FailureReason::PARSING_ERROR: reason = AuthenticateResponse_FailReason_INTERNAL_SERVER_ERROR; break;
			case Response::FailureReason::INVALID_CREDENTIALS: reason = AuthenticateResponse_FailReason_INVALID_CREDENTIALS; break;
			case Response::FailureReason::EMAIL_ALREADY_EXISTS: reason = AuthenticateResponse_FailReason_INVALID_CREDENTIALS; break;
			default: TWONET_CORE_ASSERT(false, "Not implemented."); break;
		}

		// Create response object
		Database::AuthenticateResponse responseData;
		responseData.set_requestid(1);
		responseData.set_userid(1);
		responseData.set_success(false);
		responseData.set_failreason(reason);

		// Serialize it into data
		std::string serializedResponseData;
		responseData.SerializeToString(&serializedResponseData);

		// Put it into a response
		response.SetData(serializedResponseData);
	}
}