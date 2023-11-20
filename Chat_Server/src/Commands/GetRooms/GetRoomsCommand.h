#pragma once
#include "Commands/ICommand.h"
#include <Rooms/RoomManager.h>

namespace Commands {
	class GetRoomsCommand : public ICommand
	{
	public:
		GetRoomsCommand(RoomManager& roomManager)
			: m_RoomManager(roomManager) { }

		virtual Networking::Response::ServerResponse Execute(TwoNet::Buffer& buffer, const Networking::Client& client) override;

	private:
		RoomManager& m_RoomManager;
	};
}


