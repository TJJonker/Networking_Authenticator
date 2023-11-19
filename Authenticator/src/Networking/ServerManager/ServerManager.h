#pragma once
#include <Networking/Server/Server.h>
#include <Commands/ICommand.h>

namespace Networking {
	class ServerManager
	{
	public:
		ServerManager(const char* ip, const char* port);
		void Update();

		void AddCommand(std::string name, ICommand* command);

	private:
		void OnHandshake(TwoNet::Buffer& buffer, SOCKET socket);
		void OnDataReceived(TwoNet::Buffer& buffer, SOCKET socket);

	private:
		Server m_Server;
		std::vector<SOCKET> m_Sockets;
		std::map<std::string, ICommand*> m_Commands;
	};
}

