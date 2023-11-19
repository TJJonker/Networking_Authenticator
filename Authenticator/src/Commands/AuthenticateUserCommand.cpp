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
		sql::ResultSet* result = response.GetResult();

		// Hash password


		// Compare password


		// Return data



		// Insert code here
		TWONET_CORE_ASSERT(false, "Not implemented.");
		return {};
	}

	Response::DatabaseResponse AuthenticateUserCommand::ParseToObject(Database::Authenticate authenticate, TwoNet::Buffer& buffer)
	{
		const char* rawData = TwoNet::TwoProt::DeserializeData(buffer);
		return ParseTo<Database::Authenticate>(rawData, authenticate);
	}

	Response::DatabaseResponse AuthenticateUserCommand::HashPassword(std::string rawPassword, std::string salt)
	{
		Response::DatabaseResponse response;

	}
}