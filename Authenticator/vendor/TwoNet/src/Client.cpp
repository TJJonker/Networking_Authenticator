#include "TwoNet/tpch.h"
#include "TwoNet/Networking/Client/Client.h"
#include "TwoNet/Protocols/TwoProt.h"

namespace TwoNet::Networking {
#define TERMINATE(message) { TWONET_ERROR(message); Terminate(); return false; }

	class Client::Impl {

	private:
		SOCKET m_ServerSocket = INVALID_SOCKET;
		addrinfo* m_ServerInfo = nullptr;
		WSADATA m_WsaData { };

		timeval m_Timeout { };
		fd_set m_Readfds { };

		HandshakeFunction m_OnHandShake;
		DataFunction m_OnDataReceived;

	public:

		bool Initialize(const char* ip, const char* port)
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

			m_ServerSocket = socket(hints.ai_family, hints.ai_socktype, hints.ai_protocol);
			if (m_ServerSocket == INVALID_SOCKET)
				TERMINATE("Error creating socket.");

			result = getaddrinfo(ip, port, &hints, &m_ServerInfo);
			if (result != 0)
				TERMINATE("Retrieving server info failed.");

			FD_ZERO(&m_Readfds);
			FD_SET(m_ServerSocket, &m_Readfds);

			return true;
		}

		void Terminate()
		{
			if (m_ServerSocket != INVALID_SOCKET)
				closesocket(m_ServerSocket);

			if (m_ServerInfo)
				freeaddrinfo(m_ServerInfo);

			WSACleanup();
		}

		bool Connect() {
			int result = connect(m_ServerSocket, m_ServerInfo->ai_addr, (int)m_ServerInfo->ai_addrlen);
			if (result == SOCKET_ERROR)
				TERMINATE("Connection failed");

			if(m_OnHandShake)
				m_OnHandShake();

			return true;
		}

		bool CloseConnection() {
			if (m_ServerSocket != INVALID_SOCKET) {
				closesocket(m_ServerSocket);
				return true;
			}

			return false;
		}

		bool SendData(Buffer& buffer) {
			int result;

			result = send(m_ServerSocket, buffer.GetBufferData(), (int)buffer.GetSize(), 0);
			if (result == SOCKET_ERROR) {
				TWONET_WARN("Error while sending data.");
				return false;
			}

			return true;
		}

		void CheckForIncomingData() {
			int result;
			fd_set temp = m_Readfds;

			while (true) {
				result = select((int)m_ServerSocket, &temp, NULL, NULL, &m_Timeout);

				if (!FD_ISSET(m_ServerSocket, &temp))
					break;

				TwoNet::Buffer buffer;
				if (m_OnDataReceived && ReceiveData(buffer, m_ServerSocket))
					m_OnDataReceived(buffer);
			}
		}

		void SetOnHandshake(HandshakeFunction function) {
			m_OnHandShake = function;
		}

		void SetOnDataReceived(DataFunction function) {
			m_OnDataReceived = function;
		}

	private:
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
					CloseConnection();
					return false;
				}
				else {
					// Error or disconnection
					return false;
				}
			}

			return true;
		}

	};
		

	bool Client::Initialize(const char* ip, const char* port)
	{
		return impl->Initialize(ip, port);
	}

	void Client::Terminate()
	{
		impl->Terminate();
	}

	bool Client::Connect() {
		return impl->Connect();
	}

	void Client::CloseConnection() {
		impl->CloseConnection();
	}

	bool Client::SendData(Buffer& buffer) {
		return impl->SendData(buffer);
	}

	void Client::CheckForIncomingData() {
		impl->CheckForIncomingData();
	}

	void Client::SetOnHandshake(HandshakeFunction function)
	{
		impl->SetOnHandshake(function);
	}

	void Client::SetOnDataReceived(DataFunction function)
	{
		impl->SetOnDataReceived(function);
	}

	Client::Client()
		: impl(std::make_unique<Impl>()) { }

	Client::~Client() = default;
}