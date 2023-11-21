#include "pch.h"
#include "ServerManager.h"
#include "Database/Response/DatabaseResponse.h"

Networking::ServerManager::ServerManager(const char* ip, const char* port)
{
	m_Server.Initialize(ip, port);
	m_Server.SetOnHandshake(std::bind(&Networking::ServerManager::OnHandshake, this, std::placeholders::_1, std::placeholders::_2));
	m_Server.SetOnDataReceived(std::bind(&Networking::ServerManager::OnDataReceived, this, std::placeholders::_1, std::placeholders::_2));
}

void Networking::ServerManager::Update()
{
	m_Server.ListenForConnections();
	m_Server.CheckForIncomingData(m_Sockets);
}

void Networking::ServerManager::AddCommand(std::string name, Database::IDatabaseCommand* command)
{
	TWONET_CORE_ASSERT(!m_Commands.count(name), "Command name already exists.");
	m_Commands[name] = command;
}

void Networking::ServerManager::OnHandshake(TwoNet::Buffer& buffer, SOCKET socket)
{
	m_Sockets.push_back(socket);
	std::string requestID = TwoNet::TwoProt::DeserializeData(buffer);

	buffer.Clear();
	std::string welcomeMessage = std::to_string(true);
	TwoNet::TwoProt::SerializeData(buffer, requestID.c_str(), requestID.length());
	TwoNet::TwoProt::SerializeData(buffer, welcomeMessage.c_str(), welcomeMessage.length());
	int result = m_Server.SendData(socket, buffer);
	if (!result) {
		TWONET_CORE_WARN("Failed to send handshake.");
		return;
	}
}

void Networking::ServerManager::OnDataReceived(TwoNet::Buffer& buffer, SOCKET socket)
{
	std::string requestID = TwoNet::TwoProt::DeserializeData(buffer);
	std::string command = TwoNet::TwoProt::DeserializeData(buffer);
	Database::Response::DatabaseResponse response = m_Commands[command]->Execute(buffer);
	buffer.Clear();

	TwoNet::TwoProt::SerializeData(buffer, requestID.c_str(), requestID.length());
	TwoNet::TwoProt::SerializeData(buffer, response.GetData().c_str(), response.GetData().length());

	int result = m_Server.SendData(socket, buffer);
	if (!result) {
		TWONET_CORE_WARN("Failed to send handshake.");
		return;
	}
}
