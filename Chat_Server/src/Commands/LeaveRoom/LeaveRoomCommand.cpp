#include "pch.h"
#include "LeaveRoomCommand.h"


void Commands::LeaveRoomCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback)
{
    Networking::Response::ServerResponse response;

    Room* room = m_RoomManager.GetRoomWithClient(client);
    if (!room) {
        response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
        callback(response);
    }
    
    if (!room->RemoveClient(client)) {
        response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });
        callback(response);
    }

    response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::SUCCESS) });
    callback(response);
}
