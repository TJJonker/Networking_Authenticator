#pragma once
#include "Database/Response/DatabaseResponse.h"
#include <TwoNet/Buffer/Buffer.h>
#include <TwoNet/Protocols/TwoProt.h>

struct ICommand {
	virtual Database::Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) = 0;
};