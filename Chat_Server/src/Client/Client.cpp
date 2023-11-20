#include "pch.h"
#include "Client.h"
#include "TwoNet/Protocols/TwoProt.h"

#define TERMINATE(message) { TWONET_LOG_ERROR(message); Client::Terminate(); return false; }

bool Client::Initialize(const char* ip, const char* port)
{
	int result;

	result = WSAStartup(MAKEWORD(2, 2), &m_WsaData);
	if (result != 0)
		TERMINATE("WSAStartup failed.");

	// Configuring
	addrinfo hints; 
	ZeroMemory(&hints, sizeof(hints)); 
	hints.ai_family = AF_INET; 
	hints.ai_socktype = SOCK_STREAM; 
	hints.ai_protocol = IPPROTO_TCP; 
	hints.ai_flags = AI_PASSIVE; 
	 
	m_ClientSocket = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
	if (m_ClientSocket == INVALID_SOCKET)
		TERMINATE("Error creating socket.");

	result = getaddrinfo(ip, port, &hints, &m_ServerInfo);
	if (result != 0)
		TERMINATE("Retrieving server info failed.");

	return true;
}

void Client::Terminate()
{
	if (m_ClientSocket != INVALID_SOCKET)
		closesocket(m_ClientSocket);

	if (m_ServerInfo)
		freeaddrinfo(m_ServerInfo);

	WSACleanup();
}

void Client::SendData(TwoNet::Buffer& buffer, std::function<void(TwoNet::Buffer)> callback)
{
	
}

bool Client::CheckForIncomingData()
{
	const unsigned int maxBufferSize = 1024;
	char buffer[maxBufferSize];
	int totalBytesRead = 0;

	int bytesRead = recv(m_ClientSocket, buffer, maxBufferSize, 0);

	if (bytesRead > 0) {
		while (true) {
			// If there is data to be read.
			receivedDataBuffer.WriteBuffer(buffer, bytesRead);
			totalBytesRead += bytesRead;

			// If all the data is read.
			if (bytesRead < maxBufferSize)
				break;
		}
	}
	else if (bytesRead == 0) {
		// Clean disconnection
		CloseConnection();
		return false;
	}
	else {
		// Error or disconnection
		return false;
	}

	return true;
}
