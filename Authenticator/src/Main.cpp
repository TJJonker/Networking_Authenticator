#include "pch.h"
#include "Database/API/AuthenticatorAPI.h"

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif

	Database::AuthenticatorAPI api({ "127.0.0.1:3306", "root", "root", "gdp"});
	//api.CreateUser({ "tjj.jonker@gmail.com", "UniqueRandomSalt", "Secret01!" });
	Database::Response::DatabaseResponse response = api.GetUserWithEmail({ "tjj.jonker@gmail.com" });
	sql::ResultSet* result = response.GetResult();
	result->next();
	TWONET_INFO("Email: {0}\nSalt: {1}\nHashed password: {2}", result->getString(2).c_str(), result->getString(3).c_str(), result->getString(4).c_str());
}

