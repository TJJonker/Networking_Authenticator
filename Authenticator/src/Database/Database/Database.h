#pragma once
#include "Database/Database/IDatabase.h"

namespace Database {
	class Database : public IDatabase
	{
	public:
		Database();
		virtual ~Database();

		void Connect(const ConnectionInfo& info) override;
		void Disconnect() override;

		bool IsConnected() const override;
		virtual void SetSchema(const char* schema) override;

		sql::PreparedStatement* PrepareStatement(const char* query) override;

	private:
		sql::mysql::MySQL_Driver* m_Driver = nullptr;
		sql::Connection* m_Connection = nullptr;
		sql::Statement* m_Statement = nullptr;
		sql::ResultSet* m_ResultSet = nullptr;
		sql::PreparedStatement* m_PreparedStatement = nullptr;
	};
}