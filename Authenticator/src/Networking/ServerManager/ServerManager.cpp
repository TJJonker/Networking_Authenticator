#include "pch.h"
#include "ServerManager.h"

Networking::ServerManager::ServerManager(const char* ip, const char* port)
{
	m_Server.Intialize(ip, port);
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
	TWONET_CORE_ASSERT(m_Commands.count(name), "Command name already exists.");
	m_Commands[name] = command;
}

void Networking::ServerManager::OnHandshake(TwoNet::Buffer& buffer, SOCKET socket)
{
	m_Sockets.push_back(socket);
}

void Networking::ServerManager::OnDataReceived(TwoNet::Buffer& buffer, SOCKET socket)
{
}
