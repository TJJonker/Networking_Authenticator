#pragma once
#include <MySQL/jdbc.h>

namespace Database {
	class Database
	{
	public:
		Database();
		~Database();

		void ConnectToDatabase(const char* host, const char* username, const char* password);
		void Disconnect();

		bool IsConnected() const;

		sql::PreparedStatement* PrepareStatement(const char* query);

		sql::ResultSet* Select(const char* query);
		int Update(const char* query);
		int Insert(const char* query);

	private:
		sql::mysql::MySQL_Driver* m_Driver = nullptr;
		sql::Connection* m_Connection = nullptr;
		sql::Statement* m_Statement = nullptr;
		sql::ResultSet* m_ResultSet = nullptr;
		sql::PreparedStatement* m_PreparedStatement = nullptr;
	};
}