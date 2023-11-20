#include "pch.h"
#include "Room.h"

Room::Room(std::string name, size_t maxConnections)
	: m_RoomName(name), m_MaxConnections(maxConnections) { }

bool Room::IsClientConnected(Networking::Client client)
{
	return std::find(m_ConnectedClients.begin(), m_ConnectedClients.end(), client) != m_ConnectedClients.end();
}

bool Room::AddClient(Networking::Client client)
{
	if (m_ConnectedClients.size() >= m_MaxConnections) {
		TWONET_WARN("Failed to add '{0}' to room '{1}'. Room is full.", client.Name, m_RoomName);
		return false;
	}

	m_ConnectedClients.push_back(client);

	// Hardcoded welcome message
	std::string message = client.Name + " joined the room!";
	m_Messages.push_back(message);

	return true;
}

bool Room::RemoveClient(Networking::Client client)
{
	using vecIt = std::vector<Networking::Client>::iterator;
	vecIt it = std::find(m_ConnectedClients.begin(), m_ConnectedClients.end(), client);

	if (it == m_ConnectedClients.end()) {
		TWONET_WARN("Failed to remove {0} from room {1}. Client is not connected to this room.", client.Name, m_RoomName);
			return false;
	}

	// Hardcoded leave message
	std::string message = client.Name + " left the room.";
	m_Messages.push_back(message);

	m_ConnectedClients.erase(it);
	return true;
}

std::vector<std::string> Room::GetMessages()
{
	std::vector<std::string> messages;
	for (std::string message : m_Messages)
		messages.push_back(message);
	return messages;
}

void Room::SendChatMessage(std::string& text)
{
	m_Messages.push_back(text);
}

