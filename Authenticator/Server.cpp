#include "pch.h"
#include "Server.h"


namespace Networking {

#define TERMINATE(message) { TWONET_CORE_ERROR(message); Terminate(); return false; }

	class Server::Impl {
	public:
		bool Intialize(const char* ip, const char* port) {
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
			result = bind(m_ListenSocket, m_ServerInfo->ai_addr, m_ServerInfo->ai_addrlen);
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
			result = select(m_ListenSocket, &temp, NULL, NULL, &m_Timeout);
			if (result == SOCKET_ERROR) {
				TWONET_CORE_ERROR("Select error... (ERROR: {0})", WSAGetLastError());
				return;
			}

			// If there is a connectionm request
			if (FD_ISSET(m_ListenSocket, &temp)) {
				HandleConnectionRequest();
			}

		}

		void Terminate() {
			}

	private:
		SOCKET m_ListenSocket;
		addrinfo* m_ServerInfo;
		WSADATA m_WsaData;
		fd_set m_Readfds;
		timeval m_Timeout;

		void HandleConnectionRequest() {
			// Incoming address info
			sockaddr_in remoteAddress;
			int remoteAddressLength = sizeof(remoteAddress);

			// Accept request
			SOCKET newfd = accept(m_ListenSocket, (sockaddr*)&remoteAddress, &remoteAddressLength);

			// Check if request is valid
			if (newfd == INVALID_SOCKET) {
				TWONET_CORE_ERROR("Socket acceptance failed... (Error: {0})", WSAGetLastError());
				return;
			}

			// Set new File Descriptor
			FD_SET(newfd, &m_Readfds);

			// Check for additional data
			TwoNet::Buffer buffer;
			//if(Re)


		}
	};


	bool Server::Intialize(const char* ip, const char* port) { return impl->Intialize(ip, port); }

	void Server::Terminate() { impl->Terminate(); }

	Server::Server()
		: impl(std::make_unique<Impl>()) { }

	Server::~Server() = default;
}