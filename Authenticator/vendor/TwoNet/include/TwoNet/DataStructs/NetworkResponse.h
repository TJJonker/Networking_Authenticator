#pragma once
#include <string>
#include <vector>

namespace TwoNet::Networking {
	struct NetworkResponse {
		std::string string;
		std::vector<std::string> List;
	};
}