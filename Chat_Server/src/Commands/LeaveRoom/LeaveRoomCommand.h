#pragma once
#include "Commands/ICommand.h"
#include <Networking/Client/Client.h>
#include <Rooms/RoomManager.h>

namespace Commands {
	class LeaveRoomCommand : public ICommand
	{
	public:
		LeaveRoomCommand(RoomManager& roomManager)
			:m_RoomManager(roomManager) { }

		Networking::Response::ServerResponse Execute(TwoNet::Buffer& buffer, const Networking::Client& client) override;

	private:
		RoomManager& m_RoomManager;
	};
}
