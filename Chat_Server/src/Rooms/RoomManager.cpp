#include "pch.h"
#include "RoomManager.h"

RoomManager::RoomManager() { }

RoomManager::~RoomManager() 
{
	std::map<std::string, Room*>::iterator it;
	for (it = m_Rooms.begin(); it != m_Rooms.end(); it++)
		delete it->second;
}

bool RoomManager::AddRoom(std::string name)
{
	static unsigned int roomID = 1;
	name = name == "" ? "Room " + std::to_string(roomID++) : name;

	if (m_Rooms.count(name)) {
		TWONET_WARN("Failed to add room. Room name '{0}' already exists.", name);
		return false;
	}
	m_Rooms.insert({ name, new Room(name) });

	return true;
}

bool RoomManager::DeleteRoom(std::string name)
{
	if (!m_Rooms.count(name)) {
		TWONET_WARN("Failed to delete room. Room with name '{0}' does not exists.", name);
		return false;
	}

	m_Rooms.erase(name);
	return true;
}

std::vector<std::string> RoomManager::GetRoomNames()
{
	std::vector<std::string> roomNames;
	std::map<std::string, Room*>::iterator it;

	for (it = m_Rooms.begin(); it != m_Rooms.end(); it++)
		roomNames.push_back(it->second->GetName());

	return roomNames;
}

Room* RoomManager::GetRoom(std::string& name)
{
	if (!m_Rooms.count(name)) {
		TWONET_WARN("Failed returning room. Room with name {0} does not exist.", name);
		return nullptr;
	}

	return m_Rooms[name];
}

Room* RoomManager::GetRoomWithClient(const Networking::Client& client)
{
	for (auto room : m_Rooms)
		if (room.second->IsClientConnected(client))
			return room.second;

	return nullptr;
}
