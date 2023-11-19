#include "pch.h"
#include "AuthenticateUserCommand.h"

namespace Database {
	Response::DatabaseResponse Database::AuthenticateUserCommand::Execute(TwoNet::Buffer& buffer)
	{
		Response::DatabaseResponse response;

		// Parse to Authenticate object
		Database::Authenticate authenticate;
		response = ParseToObject(authenticate, buffer);
		CHECK(response);

		// Retrieve 
		GetUserWithEmailData userData{ authenticate.email() };
		response = m_API.GetUserWithEmail(userData);
		CHECK(response);

		// Check if row is found.
		if (!response.GetResult()->next()) {
			response.SetFailureReason(Response::FailureReason::INVALID_CREDENTIALS);
			return response;
		}

		// Save result
		sql::ResultSet* result = response.GetResult();

		// Hash password
		unsigned char* hashedPassword = HashPassword(authenticate.password(), result->getString(4).c_str());

		// Compare password
		int compareResult = hashedPassword == (unsigned char*) result->getString(5).c_str();

		// Return data
		if (!compareResult) {
			response.SetFailureReason(Response::FailureReason::INVALID_CREDENTIALS);
			return response;
		}

		response.SetResult(result);
		return response;
	}

	Response::DatabaseResponse AuthenticateUserCommand::ParseToObject(Database::Authenticate authenticate, TwoNet::Buffer& buffer)
	{
		const char* rawData = TwoNet::TwoProt::DeserializeData(buffer);
		return ParseTo<Database::Authenticate>(rawData, authenticate);
	}

	unsigned char* AuthenticateUserCommand::HashPassword(std::string rawPassword, std::string salt)
	{
		std::string saltedPassword = salt + rawPassword;
		unsigned char hashedPassword[SHA256_DIGEST_LENGTH];
		SHA256((unsigned char*)saltedPassword.c_str(), saltedPassword.length(), hashedPassword);
		return hashedPassword;
	}
}