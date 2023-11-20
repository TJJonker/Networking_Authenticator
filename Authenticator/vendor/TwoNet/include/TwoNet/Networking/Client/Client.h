#pragma once
#include <functional>
#include <memory>
#include <WinSock2.h>
#include <TwoNet/Buffer/Buffer.h>

namespace TwoNet::Networking {
	using HandshakeFunction = std::function<void()>;
	using DataFunction = std::function<void(Buffer& buffer)>;
	
	class Client
	{
	public:
		Client();
		~Client();

		bool Initialize(const char* ip, const char* port);
		void Terminate();

		bool Connect();
		void CloseConnection();

		bool SendData(Buffer& buffer);
		void CheckForIncomingData();

		void SetOnHandshake(HandshakeFunction function);
		void SetOnDataReceived(DataFunction function);

	private:
		class Impl;
		std::unique_ptr<Impl> impl;
	};
}
