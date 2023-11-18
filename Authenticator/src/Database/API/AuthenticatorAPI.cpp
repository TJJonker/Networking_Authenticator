#include "pch.h"
#include "AuthenticatorAPI.h"
#include "Database/Database/Database.h"

namespace Database {
	AuthenticatorAPI::AuthenticatorAPI(const ConnectionInfo& info)
		: m_Database(new Database())
	{
		m_Database->Connect(info);
	}

	Response::DatabaseResponse AuthenticatorAPI::CreateUser(const CreateUserData& processedData)
	{
		Response::DatabaseResponse response;
		sql::PreparedStatement* statement;

		static std::string insert1 = "INSERT INTO user (last_login, creation_date) VALUES (CURRENT_TIMESTAMP, CURRENT_TIMESTAMP); ";
		statement = m_Database->PrepareStatement(insert1.c_str());
		response = Update(statement);
		if (response.GetStatus() == Response::Status::Failed)
			return response;

		static std::string retrieve = "SELECT LAST_INSERT_ID(); ";
		statement = m_Database->PrepareStatement(retrieve.c_str());
		response = Select(statement);
		if (response.GetStatus() == Response::Status::Failed)
			return response;

		static std::string insert2 = "INSERT INTO web_auth(email, salt, hashed_password, userID) VALUES(?, ?, ?, ?);";
		statement = m_Database->PrepareStatement(insert2.c_str());
		statement->setString(1, processedData.Email);
		statement->setString(2, processedData.Salt);
		statement->setString(3, processedData.HashedPassword);
		sql::ResultSet* result = response.GetResult();
		result->next();
		int i = result->getInt(1);
		statement->setInt(4, result->getInt(1));

		return Update(statement);
	}

	Response::DatabaseResponse AuthenticatorAPI::AuthenticateUser(const AuthenticateUserData& processedData)
	{
		TWONET_ASSERT(false, "Not implemented");
		sql::PreparedStatement* statement = m_Database->PrepareStatement("");
		return {};
	}

	Response::DatabaseResponse AuthenticatorAPI::GetUserWithEmail(const GetUserWithEmailData& processedData)
	{
		TWONET_ASSERT(false, "Not implemented");
		sql::PreparedStatement* statement = m_Database->PrepareStatement("");
		return {};
	}

	Response::DatabaseResponse AuthenticatorAPI::Select(sql::PreparedStatement* statement)
	{
		Response::DatabaseResponse response = DatabaseCheck();
		if (response.GetStatus() != Response::Status::OK)
			return response;

		response.SetResult(statement->executeQuery());
		return response;
	}

	Response::DatabaseResponse AuthenticatorAPI::Update(sql::PreparedStatement* statement)
	{
		Response::DatabaseResponse response = DatabaseCheck();
		if (response.GetStatus() != Response::Status::OK)
			return response;

		(void)statement->executeUpdate();
		return response;
	}

	Response::DatabaseResponse AuthenticatorAPI::DatabaseCheck()
	{
		Response::DatabaseResponse response = {};
		
		if (!m_Database->IsConnected()) {
			response.SetFailureReason(Response::FailureReason::NO_CONNECTION);
			return response;
		}

		return response;
	}
}