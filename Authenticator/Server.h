#pragma once

namespace Networking {
	class Server
	{
	public:
		bool Intialize(const char* ip, const char* port);
		void Terminate();



	private:
		class Impl;
		std::unique_ptr<Impl> impl;

		Server();
		~Server();
	};
}
