#include "pch.h"
#include "ServerManager.h"

Networking::ServerManager::ServerManager(const char* ip, const char* port)
{
	m_Server.Initialize(ip, port);
	m_Server.SetOnHandshake(std::bind(&Networking::ServerManager::OnHandshake, this, std::placeholders::_1, std::placeholders::_2));
	m_Server.SetOnDataReceived(std::bind(&Networking::ServerManager::OnDataReceived, this, std::placeholders::_1, std::placeholders::_2));
}

void Networking::ServerManager::Update()
{
	m_Server.ListenForConnections();
	
	// Could be optimized, but works for now
	std::vector<SOCKET> sockets;
	for (auto& socket : m_Clients)
		sockets.push_back(socket.first);

	m_Server.CheckForIncomingData(sockets);
}

void Networking::ServerManager::AddCommand(std::string name, Commands::ICommand* command)
{
	TWONET_ASSERT(!m_Commands.count(name), "Command name already exists.");
	m_Commands[name] = command;
}

void Networking::ServerManager::OnHandshake(TwoNet::Buffer& buffer, SOCKET socket)
{
	m_Clients[socket] = { "Somebody", socket };
	std::string requestID = TwoNet::TwoProt::DeserializeData(buffer);

	buffer.Clear();
	std::string welcomeMessage = "Welcome to the Void";
	TwoNet::TwoProt::SerializeData(buffer, requestID.c_str(), requestID.length());
	TwoNet::TwoProt::SerializeData(buffer, welcomeMessage.c_str(), welcomeMessage.length());
	int result = m_Server.SendData(socket, buffer);
	if (!result) {
		TWONET_WARN("Failed to send handshake.");
		return;
	}
}

void Networking::ServerManager::OnDataReceived(TwoNet::Buffer& buffer, SOCKET socket)
{
	std::string requestID = TwoNet::TwoProt::DeserializeData(buffer);
	std::string command = TwoNet::TwoProt::DeserializeData(buffer);

	m_Commands[command]->Execute(buffer, m_Clients[socket], 
		[&](Networking::Response::ServerResponse& response) {
			buffer.Clear();

			TwoNet::TwoProt::SerializeData(buffer, requestID.c_str(), requestID.length());
			//TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
			for (std::string data : response.GetData())
				TwoNet::TwoProt::SerializeData(buffer, data.c_str(), data.length());

			int result = m_Server.SendData(socket, buffer);
			if (!result) {
				TWONET_WARN("Failed to send handshake.");
				return;
			}
		});
	
}
