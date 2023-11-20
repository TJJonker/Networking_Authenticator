#pragma once
#include "Networking/Response/ServerResponse.h"
#include <TwoNet/Buffer/Buffer.h>
#include "Networking/Client/Client.h"

namespace Commands {
	struct ICommand {
		virtual Networking::Response::ServerResponse Execute(TwoNet::Buffer& buffer, const Networking::Client& client) = 0;
	};

	template<typename T>
	static Networking::Response::ServerResponse ParseTo(const char* data, T& object) {
		Response::DatabaseResponse response;
		bool success = object.ParseFromString(data);
		if (!success) {
			response.SetFailureReason(Response::FailureReason::PARSING_ERROR);
			return response;
		}

		return response;
	}
}