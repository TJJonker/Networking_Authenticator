#include "pch.h"
#include "GetRoomsCommand.h"

void Commands::GetRoomsCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback)
{
	Networking::Response::ServerResponse response;
	response.SetData(m_RoomManager.GetRoomNames());
	callback(response);
}
