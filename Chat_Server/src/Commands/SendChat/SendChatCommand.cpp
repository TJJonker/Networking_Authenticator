#include "pch.h"
#include "SendChatCommand.h"


Networking::Response::ServerResponse Commands::SendChatCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client)
{
	Networking::Response::ServerResponse response;

	Room* room = m_RoomManager.GetRoomWithClient(client);
	if (!room) {
		response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
		return response;
	}

	std::string message = TwoNet::TwoProt::DeserializeData(buffer);
	room->SendChatMessage(message);

	response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::SUCCESS) });
	return response;
}
