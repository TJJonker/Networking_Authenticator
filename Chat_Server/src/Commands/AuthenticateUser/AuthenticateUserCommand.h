#pragma once
#include "Commands/ICommand.h"
#include "Networking/DatabaseAPI/DatabaseClient.h"

namespace Commands {
	class AuthenticateUserCommand : public ICommand
	{
	public:
		AuthenticateUserCommand(DatabaseClient& client)
			: m_DatabaseClient(client) {}

		void Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback) override;

	private:
		DatabaseClient& m_DatabaseClient;

	};
}
