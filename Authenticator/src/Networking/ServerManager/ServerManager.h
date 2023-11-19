#pragma once
#include <Networking/Server/Server.h>
#include "Commands/IDatabaseCommand.h"

namespace Networking {
	class ServerManager
	{
	public:
		ServerManager(const char* ip, const char* port);
		void Update();

		void AddCommand(std::string name, Database::IDatabaseCommand* command);

	private:
		void OnHandshake(TwoNet::Buffer& buffer, SOCKET socket);
		void OnDataReceived(TwoNet::Buffer& buffer, SOCKET socket);

	private:
		Server m_Server;
		std::vector<SOCKET> m_Sockets;
		std::map<std::string, Database::IDatabaseCommand*> m_Commands;
	};
}

