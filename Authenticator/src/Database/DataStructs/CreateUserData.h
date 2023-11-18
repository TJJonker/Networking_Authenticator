#pragma once

namespace Database {
	struct CreateUserData {
		std::string Email;
		std::string Salt;
		std::string HashedPassword;
	};
}