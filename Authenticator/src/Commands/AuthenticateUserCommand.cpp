#include "pch.h"
#include "AuthenticateUserCommand.h"
#include <AuthenticateResponse/AuthenticateResponse.pb.h>

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
		unsigned char* hashedPassword = HashPassword(authenticate.password(), result->getString(4).c_str()).data();

		// Compare password
		int compareResult = hashedPassword == (unsigned char*) result->getString(5).c_str();

		// Return data
		if (!compareResult) {
			response.SetFailureReason(Response::FailureReason::INVALID_CREDENTIALS);
			CHECK(response, authenticate.requestid());
		}

		Database::AuthenticateResponse authenticationResponse;
		authenticationResponse.set_requestid(authenticate.requestid());
		authenticationResponse.set_success(true);
		authenticationResponse.set_creationdate(result->getString(2));

		std::string data;
		authenticationResponse.SerializeToString(&data);
		response.SetData(data);

		return response;
	}

	Response::DatabaseResponse AuthenticateUserCommand::ParseToObject(Database::Authenticate authenticate, TwoNet::Buffer& buffer)
	{
		const char* rawData = TwoNet::TwoProt::DeserializeData(buffer);
		return ParseTo<Database::Authenticate>(rawData, authenticate);
	}

	std::vector<unsigned char> AuthenticateUserCommand::HashPassword(std::string rawPassword, std::string salt)
	{
		std::string saltedPassword = salt + rawPassword;
		std::vector<unsigned char> hashedPassword(SHA256_DIGEST_LENGTH);
		SHA256((unsigned char*)saltedPassword.c_str(), saltedPassword.length(), hashedPassword.data());
		return hashedPassword;
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
		responseData.set_requestid(requestID);
		responseData.set_success(false);
		responseData.set_failreason(reason);

		// Serialize it into data
		std::string serializedResponseData;
		responseData.SerializeToString(&serializedResponseData);

		// Put it into a response
		response.SetData(serializedResponseData);
	}
}