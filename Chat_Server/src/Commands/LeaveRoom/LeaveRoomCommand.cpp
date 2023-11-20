#include "pch.h"
#include "LeaveRoomCommand.h"


Networking::Response::ServerResponse Commands::LeaveRoomCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client)
{
    Networking::Response::ServerResponse response;

    Room* room = m_RoomManager.GetRoomWithClient(client);
    if (!room) {
        response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
        return response;
    }
    
    if (!room->RemoveClient(client)) {
        response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
        return response;
    }

    response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::SUCCESS) });
    return response;
}
