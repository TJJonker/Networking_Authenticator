#pragma once
#include "Commands/ICommand.h"
#include "Rooms/RoomManager.h"

namespace Commands {
	class GetMessagesCommand : public ICommand
	{
	public:
		GetMessagesCommand(RoomManager& roomManager)
			: m_RoomManager(roomManager) { }

		virtual Networking::Response::ServerResponse Execute(TwoNet::Buffer& buffer, const Networking::Client& client) override;

	private:
		RoomManager& m_RoomManager;
	};
}

