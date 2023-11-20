#pragma once
#include "Database/Response/DatabaseResponse.h"
#include <TwoNet/Buffer/Buffer.h>
#include <TwoNet/Protocols/TwoProt.h>

namespace Database {
	struct IDatabaseCommand {
		virtual Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) = 0;
	};

	template<typename T>
	static Response::DatabaseResponse ParseTo(const char* data, T& object) {
		Response::DatabaseResponse response;
		bool success = object.ParseFromString(data);
		if (!success) {
			response.SetFailureReason(Response::FailureReason::PARSING_ERROR);
			return response;
		}

		return response;
	}
}