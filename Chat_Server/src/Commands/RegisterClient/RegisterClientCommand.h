#pragma once
#include "Commands/ICommand.h"
#include "Networking/DatabaseAPI/DatabaseClient.h"

namespace Commands {
	class RegisterClientCommand : public ICommand
	{
	public:
		RegisterClientCommand(DatabaseClient& databaseClient)
			: m_DatabaseClient(databaseClient) { }

		void Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback) override;

	private:
		DatabaseClient& m_DatabaseClient;
	};
}
