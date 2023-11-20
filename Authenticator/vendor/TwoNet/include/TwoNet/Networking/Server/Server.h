#pragma once
#include <functional>
#include <memory>
#include <WinSock2.h>
#include <TwoNet/Buffer/Buffer.h>

namespace TwoNet::Networking {

	using DataFunction = std::function<void(Buffer& buffer, SOCKET socket)>;

	class Server
	{
	public:
		Server();
		~Server();

		bool Initialize(const char* ip, const char* port);
		void Terminate();

		void ListenForConnections();
		void CheckForIncomingData(std::vector<SOCKET> sockets);

		void SetOnHandshake(DataFunction function);
		void SetOnDataReceived(DataFunction function);

		bool SendData(SOCKET socket, const TwoNet::Buffer& buffer);

	private:
		class Impl;
		std::unique_ptr<Impl> impl;
	};
}
