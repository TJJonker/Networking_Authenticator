#include "TwoNet/tpch.h"
#include "TwoNet/Networking/Server/Server.h"

namespace TwoNet::Networking {

#define TERMINATE(message) { TWONET_ERROR(message); Terminate(); return false; }

	class Server::Impl {
	public:
		bool Initialize(const char* ip, const char* port) {
			int result;

			result = WSAStartup(MAKEWORD(2, 2), &m_WsaData);
			if (result)
				TERMINATE("WSA startup failed.");

			// Configuring
			addrinfo hints;
			ZeroMemory(&hints, sizeof(hints));
			hints.ai_family = AF_INET;
			hints.ai_socktype = SOCK_STREAM;
			hints.ai_protocol = IPPROTO_TCP;
			hints.ai_flags = AI_PASSIVE;

			// Retrieving
			result = getaddrinfo(ip, port, &hints, &m_ServerInfo);
			if (result)
				TERMINATE("Retrieving server info failed.");

			// Creating
			m_ListenSocket = socket(m_ServerInfo->ai_family, m_ServerInfo->ai_socktype, m_ServerInfo->ai_protocol);
			if (m_ListenSocket == INVALID_SOCKET)
				TERMINATE("Socket Creation failed.");

			// Binding
			result = bind(m_ListenSocket, m_ServerInfo->ai_addr, (int)m_ServerInfo->ai_addrlen);
			if (result == SOCKET_ERROR)
				TERMINATE("Socket Creation failed.");

			// Listening
			result = listen(m_ListenSocket, SOMAXCONN);
			if (result == SOCKET_ERROR)
				TERMINATE("Socket listening failed.");

			FD_ZERO(&m_Readfds);
			FD_SET(m_ListenSocket, &m_Readfds);

			return true;
		}

		void ListenForConnections() {
			// Make a copy of the fd_set
			fd_set temp = m_Readfds;
			int result;
			
			// Listen for new connection requests.
			result = select((int)m_ListenSocket, &temp, NULL, NULL, &m_Timeout);
			if (result == SOCKET_ERROR) {
				TWONET_ERROR("Select error... (ERROR: {0})", WSAGetLastError());
				return;
			}

			// If there is a connectionm request
			if (FD_ISSET(m_ListenSocket, &temp)) {
				HandleConnectionRequest();
			}

		}

		void CheckForIncomingData(std::vector<SOCKET> sockets) {
			int result;
			fd_set temp = m_Readfds;

			for (SOCKET socket : sockets) {
				result = select((int)socket, &temp, NULL, NULL, &m_Timeout);

				if (FD_ISSET(socket, &temp) && socket == m_ListenSocket)
					continue;

				TwoNet::Buffer buffer;
				if (m_OnDataReceived && ReceiveData(buffer, socket))
					m_OnDataReceived(buffer, socket);
			}
		}

		void Terminate() {
			if (m_ListenSocket != INVALID_SOCKET)
				closesocket(m_ListenSocket);

			if (m_ServerInfo)
				freeaddrinfo(m_ServerInfo);

			WSACleanup();
		}

		void SetOnHandshake(DataFunction function)
		{ 
			m_OnHandShake = function; 
		}
		void SetOnDataReceived(DataFunction function) {
			m_OnDataReceived = function;
		}

		bool SendData(SOCKET socket, const TwoNet::Buffer& buffer) {
			int result;

			result = send(socket, buffer.GetBufferData(), (int)buffer.GetSize(), 0);
			if (result == SOCKET_ERROR) {
				TWONET_WARN("Error while sending data.");
				return false;
			}

			return true;
		}

	private:
		SOCKET m_ListenSocket = INVALID_SOCKET;
		addrinfo* m_ServerInfo = nullptr;
		WSADATA m_WsaData { };
		fd_set m_Readfds { };
		timeval m_Timeout { };

		DataFunction m_OnHandShake;
		DataFunction m_OnDataReceived;

		void HandleConnectionRequest() {
			// Incoming address info
			sockaddr_in remoteAddress = {};
			int remoteAddressLength = sizeof(remoteAddress);

			// Accept request
			SOCKET newfd = accept(m_ListenSocket, (sockaddr*)&remoteAddress, &remoteAddressLength);

			// Check if request is valid
			if (newfd == INVALID_SOCKET) {
				TWONET_ERROR("Socket acceptance failed... (Error: {0})", WSAGetLastError());
				return;
			}

			// Set new File Descriptor
			FD_SET(newfd, &m_Readfds);

			// Check for additional data
			TwoNet::Buffer buffer;
			if (m_OnHandShake && ReceiveData(buffer, newfd))
				m_OnHandShake(buffer, newfd);

			TWONET_TRACE("Connection made.");
		}

		bool ReceiveData(TwoNet::Buffer& receivedDataBuffer, SOCKET clientSocket) {
			const unsigned int maxBufferSize = 1024;
			char buffer[maxBufferSize];
			int totalBytesRead = 0;

			while (true) {
				int bytesRead = recv(clientSocket, buffer, maxBufferSize, 0);

				if (bytesRead > 0) {
					// If there is data to be read.
					receivedDataBuffer.WriteBuffer(buffer, bytesRead);
					totalBytesRead += bytesRead;

					// If all the data is read.
					if (bytesRead < maxBufferSize)
						break;
				}
				else if (bytesRead == 0) {
					// Clean disconnection
					CloseConnection(clientSocket);
					return false;
				}
				else {
					// Error or disconnection
					return false;
				}
			}

			return true;
		}

		bool CloseConnection(SOCKET socket) {
			if (socket != INVALID_SOCKET) {
				closesocket(socket);
				return true;
			}

			return false;
		}
	};


	bool Server::Initialize(const char* ip, const char* port) 
	{ 
		return impl->Initialize(ip, port); 
	}

	void Server::Terminate() 
	{ 
		impl->Terminate(); 
	}

	void Server::ListenForConnections() {
		impl->ListenForConnections();
	}

	void Server::CheckForIncomingData(std::vector<SOCKET> sockets)
	{
		impl->CheckForIncomingData(sockets);
	}

	void Server::SetOnHandshake(DataFunction function) 
	{ 
		impl->SetOnHandshake(function); 
	}

	void Server::SetOnDataReceived(DataFunction function) 
	{ 
		impl->SetOnDataReceived(function); 
	}

	bool Server::SendData(SOCKET socket, const TwoNet::Buffer& buffer)
	{
		return impl->SendData(socket, buffer);
	}

	Server::Server()
		: impl(std::make_unique<Impl>()) { }

	Server::~Server() = default;
}