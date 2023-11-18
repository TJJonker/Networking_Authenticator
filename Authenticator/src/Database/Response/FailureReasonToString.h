#pragma once
#include <string>
#include "FailureReason.h"

namespace Database::Response {
	static std::string FailureReasonToString(FailureReason reason) {
		switch (reason) {
		default: return "Invalid failure reason.";
		}
	}
}