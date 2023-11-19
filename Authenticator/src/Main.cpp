#include "pch.h"
#include "Database/API/AuthenticatorAPI.h"
#include "Networking/ServerManager/ServerManager.h"

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif
	Database::AuthenticatorAPI api({ "127.0.0.1:3306", "root", "root", "gdp"});
	Networking::ServerManager serverManager("127.0.0.1", "8412");

	
	while (true) {
		serverManager.Update();
	}

}

