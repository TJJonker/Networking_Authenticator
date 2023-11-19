#pragma once

namespace Database::Response {
	enum class FailureReason {
		NONE,
		NO_CONNECTION,
		PARSING_ERROR,
		INVALID_CREDENTIALS,
		EMAIL_ALREADY_EXISTS
	};
}