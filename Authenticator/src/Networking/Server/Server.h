#pragma once
#include <TwoNet/Buffer/Buffer.h>

namespace Networking {

	using DataFunction = std::function<void(TwoNet::Buffer& buffer)>;

	class Server
	{
	public:
		Server();
		~Server();

		bool Intialize(const char* ip, const char* port);
		void Terminate();

		void ListenForConnections();
		void CheckForIncomingData(std::vector<SOCKET> sockets);

		void SetOnConnectionDataReceived(DataFunction function);
		void SetOnDataReceived(DataFunction function);

		bool SendData(SOCKET socket, const TwoNet::Buffer& buffer);
	private:
		class Impl;
		std::unique_ptr<Impl> impl;
	};
}
