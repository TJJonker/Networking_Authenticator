#include "pch.h"
#include "GetMessagesCommand.h"


void Commands::GetMessagesCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback)
{
	Networking::Response::ServerResponse response;
	
	Room* room = m_RoomManager.GetRoomWithClient(client);
	if (!room) {
		response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
		callback(response);
		return;
	}

	response.SetData(room->GetMessages());
	callback(response);
}
