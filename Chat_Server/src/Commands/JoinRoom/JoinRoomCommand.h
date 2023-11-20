#pragma once
#include "Commands/ICommand.h"
#include <Rooms/RoomManager.h>

namespace Commands {
	class JoinRoomCommand : public ICommand
	{
	public:
		JoinRoomCommand(RoomManager& roomManager)
			: m_RoomManager(roomManager) { }

		Networking::Response::ServerResponse Execute(TwoNet::Buffer& buffer, const Networking::Client& client) override;

	private:
		RoomManager& m_RoomManager;
	};
}