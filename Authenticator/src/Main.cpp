#include "pch.h"
#include "Database/API/AuthenticatorAPI.h"
#include <Networking/Server/Server.h>

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif
	Database::AuthenticatorAPI api({ "127.0.0.1:3306", "root", "root", "gdp"});
	Networking::Server server;
	server.Intialize("127.0.0.1", "8412");
	
	while (true) {
		server.ListenForConnections();
		server.
	}

}

