#pragma once
#include "Networking/Response/ServerResponse.h"
#include <TwoNet/Buffer/Buffer.h>
#include "Networking/Client/Client.h"

namespace Commands {
	struct ICommand {
		using callback = std::function<void(Networking::Response::ServerResponse& response)>;
		virtual void Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback) = 0;
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