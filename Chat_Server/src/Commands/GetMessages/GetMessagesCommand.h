#pragma once
#include "Commands/ICommand.h"
#include "Rooms/RoomManager.h"

namespace Commands {
	class GetMessagesCommand : public ICommand
	{
	public:
		GetMessagesCommand(RoomManager& roomManager)
			: m_RoomManager(roomManager) { }

		void Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback) override;

	private:
		RoomManager& m_RoomManager;
	};
}

