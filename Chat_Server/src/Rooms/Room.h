#pragma once
#include <Networking/Client/Client.h>

class Room
{
public:
	Room(std::string name, size_t maxConnections = 10);

	std::string GetName() const { return m_RoomName; }
	bool IsClientConnected(Networking::Client client);
	bool AddClient(Networking::Client client);
	bool RemoveClient(Networking::Client client);
	std::vector<std::string> GetMessages();

	void SendChatMessage(std::string& message);

private:
	std::string m_RoomName;
	size_t m_MaxConnections;
	std::vector<Networking::Client> m_ConnectedClients;
	std::vector<std::string> m_Messages;
};

