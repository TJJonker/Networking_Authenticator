#include "pch.h"
#include "GetMessagesCommand.h"


Networking::Response::ServerResponse Commands::GetMessagesCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client)
{
	Networking::Response::ServerResponse response;
	
	Room* room = m_RoomManager.GetRoomWithClient(client);
	if (!room) {
		response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
		return response;
	}

	response.SetData(room->GetMessages());
	return response;
}
