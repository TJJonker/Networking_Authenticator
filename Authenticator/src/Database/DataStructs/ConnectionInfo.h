#pragma once
#include <string>

namespace Database {
	struct ConnectionInfo {
		std::string Host;
		std::string Username;
		std::string Password;
		std::string Schema;
	};
}