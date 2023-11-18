#pragma once
#include "Response/DatabaseResponse.h"
#include "DataStructs/AuthenticateUserData.h"
#include "DataStructs/CreateUserData.h"

namespace Database {
	class AuthenticationDatabase
	{
		Response::DatabaseResponse& CreateUser(CreateUserData& data);
		Response::DatabaseResponse& AuthenticateUser(AuthenticateUserData& data);
	};
}
