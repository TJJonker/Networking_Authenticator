#include "pch.h"
#include "Database/API/AuthenticatorAPI.h"
#include "Networking/ServerManager/ServerManager.h"
#include "Commands/CreatUserCommand.h"
#include "Commands/AuthenticateUserCommand.h"

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif
	Database::AuthenticatorAPI api({ "127.0.0.1:3306", "root", "root", "gdp"});
	Networking::ServerManager serverManager("127.0.0.1", "8413");

	serverManager.AddCommand("AUTHENTICATE", new Database::AuthenticateUserCommand(api));
	serverManager.AddCommand("CREATE_USER", new Database::CreateUserCommand(api));

	while (true) {
		serverManager.Update();
	}
}

