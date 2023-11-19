#pragma once
#include "IDatabaseCommand.h"
#include "Database/API/AuthenticatorAPI.h"

namespace Database {
	class CreateUserCommand : public IDatabaseCommand {
	public:
		CreateUserCommand(AuthenticatorAPI& api)
			:m_API(api) { }

		Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) override {
			TWONET_CORE_ASSERT(false, "Not implemented.");
			return {};
		}

	private:
		AuthenticatorAPI& m_API;

	};
}