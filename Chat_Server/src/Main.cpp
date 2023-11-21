#include "pch.h"


#include <Rooms/RoomManager.h>
#include <Networking/ServerManager/ServerManager.h>

#include "Commands/GetRooms/GetRoomsCommand.h"
#include "Commands/JoinRoom/JoinRoomCommand.h"
#include "Commands/LeaveRoom/LeaveRoomCommand.h"
#include "Commands/SendChat/SendChatCommand.h"
#include "Commands/GetMessages/GetMessagesCommand.h"
#include "Commands/AuthenticateUser/AuthenticateUserCommand.h"
#include "Commands/RegisterClient/RegisterClientCommand.h"

#include <Networking/DatabaseAPI/DatabaseClient.h>


Networking::ServerManager serverManager("127.0.0.1", "8412");
RoomManager roomManager;
DatabaseClient client;

int main() {
	TwoNet::Log::Init();

	client.Initialize("127.0.0.1", "8413");
	client.Connect();

	serverManager.AddCommand("LIST_ROOMS", new Commands::GetRoomsCommand(roomManager));
	serverManager.AddCommand("JOIN_ROOM", new Commands::JoinRoomCommand(roomManager));
	serverManager.AddCommand("LEAVE_ROOM", new Commands::LeaveRoomCommand(roomManager));
	serverManager.AddCommand("SEND_MESSAGE", new Commands::SendChatCommand(roomManager));
	serverManager.AddCommand("GET_MESSAGES", new Commands::GetMessagesCommand(roomManager));
	serverManager.AddCommand("AUTHENTICATE", new Commands::AuthenticateUserCommand(client));
	serverManager.AddCommand("CREATE_USER", new Commands::RegisterClientCommand(client));

	roomManager.AddRoom("R1");
	roomManager.AddRoom("R2");
	roomManager.AddRoom("R3");

	while (true) {
		serverManager.Update();
		client.Update();
	}
}

