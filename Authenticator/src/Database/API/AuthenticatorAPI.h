#pragma once
#include "Database/DataStructs/ConnectionInfo.h"
#include "Database/Response/DatabaseResponse.h"
#include <Database/DataStructs/CreateUserData.h>
#include <Database/DataStructs/AuthenticateUserData.h>
#include "Database/Database/IDatabase.h"
#include <Database/DataStructs/GetUserWithEmailData.h>

namespace Database {
	class AuthenticatorAPI
	{
	public:
		AuthenticatorAPI(const ConnectionInfo& info);

		Response::DatabaseResponse CreateUser(const CreateUserData& processedData) const;
		Response::DatabaseResponse GetUserWithEmail(const GetUserWithEmailData& processedData) const;
	
	private:
		Response::DatabaseResponse Select(sql::PreparedStatement* statement) const;
		Response::DatabaseResponse Update(sql::PreparedStatement* statement) const;

		Response::DatabaseResponse DatabaseCheck() const;
	private:
		IDatabase* m_Database = nullptr;
	};
}
