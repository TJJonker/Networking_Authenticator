#include "pch.h"
#include "GetRoomsCommand.h"

Networking::Response::ServerResponse Commands::GetRoomsCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client)
{
	Networking::Response::ServerResponse response;
	response.SetData(m_RoomManager.GetRoomNames());
	return response;
}
