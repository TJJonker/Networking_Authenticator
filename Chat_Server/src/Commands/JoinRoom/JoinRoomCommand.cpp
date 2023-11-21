#include "pch.h"
#include "JoinRoomCommand.h"

void Commands::JoinRoomCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback)
{
    Networking::Response::ServerResponse response;
    std::string roomName = TwoNet::TwoProt::DeserializeData(buffer);
    Room* room = m_RoomManager.GetRoom(roomName);

    if (room->AddClient(client)) 
        response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::SUCCESS) });
    else
        response.SetData({ TwoNet::Utils::ResponseToString(TwoNet::Utils::Response::FAILED) });

    callback(response);
}
