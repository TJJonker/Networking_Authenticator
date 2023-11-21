#pragma once
#include "Commands/ICommand.h"
#include <Networking/Client/Client.h>
#include <Rooms/RoomManager.h>

namespace Commands {
	class SendChatCommand : public ICommand
	{
	public:
		SendChatCommand(RoomManager& roomManger) 
			:m_RoomManager(roomManger) { }

		void Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback) override;
	
	private:
		RoomManager& m_RoomManager;

	};
}
