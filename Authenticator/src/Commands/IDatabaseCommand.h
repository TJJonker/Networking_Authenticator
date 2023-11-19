#pragma once
#include "Database/Response/DatabaseResponse.h"
#include <TwoNet/Buffer/Buffer.h>
#include <TwoNet/Protocols/TwoProt.h>

namespace Database {
	struct IDatabaseCommand {
		virtual Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) = 0;
	};
}