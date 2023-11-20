#pragma once
#include <TwoNet/Buffer/Buffer.h>

class Client
{


public:
	bool Initialize(const char* ip, const char* port);
	void Terminate();
	
	bool CheckForIncomingData(TwoNet::Buffer& receivedDataBuffer);

	void SendData(TwoNet::Buffer& buffer, std::function<void(TwoNet::Buffer)>);

private:
	WSADATA m_WsaData = { };
	SOCKET m_ClientSocket = INVALID_SOCKET;
	addrinfo* m_ServerInfo = nullptr;
};

