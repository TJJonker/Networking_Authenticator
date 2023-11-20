#pragma once
#include "IDatabaseCommand.h"
#include "Database/API/AuthenticatorAPI.h"
#include <CreateAccount/CreateAccount.pb.h>

namespace Database {
#define CHECK(response, requestID) { if (response.GetStatus() == Response::Status::Failed) { SetCreateUserFailData(response, requestID);  return response; }}

	class CreateUserCommand : public IDatabaseCommand {
	public:
		CreateUserCommand(AuthenticatorAPI& api)
			:m_API(api) { }

		Response::DatabaseResponse Execute(TwoNet::Buffer& buffer) override;

	private:
		Response::DatabaseResponse ParseToObject(Database::CreateAccount createAccount, TwoNet::Buffer& buffer);
		unsigned char* HashPassword(std::string rawPassword, std::string salt);
		std::string GetRandomString(unsigned int length);
		void SetCreateUserFailData(Response::DatabaseResponse& response, long requestID);

	private:
		AuthenticatorAPI& m_API;

	};
}