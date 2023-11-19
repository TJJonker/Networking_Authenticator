#pragma once
#include "Commands/IDatabaseCommand.h"
#include "Database/API/AuthenticatorAPI.h"
#include "Debug/Assertion.h"
#include <Authenticate/Authenticate.pb.h>

namespace Database {
	class AuthenticateUserCommand : public IDatabaseCommand {
	public:
		AuthenticateUserCommand(const AuthenticatorAPI& api)
		: m_API(api) { }

		Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) override {
			const char* data = TwoNet::TwoProt::DeserializeData(buffer);
			Database::Authenticate authenticate;
			// Insert code here
			TWONET_CORE_ASSERT(false, "Not implemented.");
			return {};
		}
		
	private:
		const AuthenticatorAPI& m_API;
	};
}