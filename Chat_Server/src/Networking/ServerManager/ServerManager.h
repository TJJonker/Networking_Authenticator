#pragma once
#include <TwoNet/Networking/Server/Server.h>
#include "Commands/ICommand.h"
#include <Networking/Client/Client.h>

namespace Networking {
	class ServerManager
	{
	public:
		ServerManager(const char* ip, const char* port);
		void Update();

		void AddCommand(std::string name, Commands::ICommand* command);

	private:
		void OnHandshake(TwoNet::Buffer& buffer, SOCKET socket);
		void OnDataReceived(TwoNet::Buffer& buffer, SOCKET socket);

	private:
		TwoNet::Networking::Server m_Server;
		std::map<SOCKET, Networking::Client> m_Clients;
		std::map<std::string, Commands::ICommand*> m_Commands;
	};
}

