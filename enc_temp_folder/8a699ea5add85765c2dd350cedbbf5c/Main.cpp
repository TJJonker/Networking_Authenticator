#include "pch.h"
#include "Database/API/AuthenticatorAPI.h"

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif

	Database::AuthenticatorAPI api({ "127.0.0.1:3306", "root", "root", "gdp"});
	api.CreateUser({ "tjj.jonker@gmail.com", "UniqueRandomSalt", "Secret01!" });

}

