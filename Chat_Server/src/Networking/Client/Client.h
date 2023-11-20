#pragma once
#include <string>
#include <WinSock2.h>

namespace Networking {
	struct Client {
		std::string Name;
		SOCKET Socket;

        bool operator==(const Client& other) const {
            return Socket == other.Socket;
        }

        bool operator!=(const Client& other) const {
            return !(*this == other);
        }
	};
}