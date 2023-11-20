#pragma once
#include <TwoNet/Networking/Client/Client.h>
#include <TwoNet/DataStructs/NetworkResponse.h>

class Networking
{

private:
	using ResultCallback = std::function<void(TwoNet::Networking::NetworkResponse)>;
	using BufferCallback = std::function<void(TwoNet::Buffer& buffer)>;

	TwoNet::Networking::Client* m_Client;
	std::map<long, BufferCallback> m_Submissions;

public:
	Networking();
	~Networking();

	bool Initialize(const char* ip, const char* port);
	void Destroy();

	bool Connect();

	void Update();

	bool RequestRooms(ResultCallback callback);
	bool JoinRoom(std::string roomName, ResultCallback callback);
	bool LeaveRoom(ResultCallback callback);
	bool SendChat(std::string message, ResultCallback callback);
	bool RequestMessages(ResultCallback callback);

private:
	void Submit(TwoNet::Buffer& buffer, BufferCallback callback);
	void OnDataReceipt(TwoNet::Buffer& buffer);
	void OnHandshake();
};

