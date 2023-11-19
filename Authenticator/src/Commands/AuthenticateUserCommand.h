#pragma once
#include "Commands/IDatabaseCommand.h"
#include "Database/API/AuthenticatorAPI.h"
#include "Debug/Assertion.h"
#include <Authenticate/Authenticate.pb.h>

namespace Database {
#define CHECK(response) { if (response.GetStatus() == Response::Status::Failed) return response; }

	class AuthenticateUserCommand : public IDatabaseCommand {
	public:
		AuthenticateUserCommand(const AuthenticatorAPI& api)
		: m_API(api) { }

		Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) override;
		
	private:
		Response::DatabaseResponse ParseToObject(Database::Authenticate authenticate, TwoNet::Buffer& buffer);
		unsigned char* HashPassword(std::string rawPassword, std::string salt);

	private:
		const AuthenticatorAPI& m_API;
	};
}