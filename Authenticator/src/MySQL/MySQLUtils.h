#pragma once
#include <MySQL/jdbc.h>

class MySQLUtils
{
public:
	MySQLUtils();
	~MySQLUtils();

	void ConnectToDatabase(const char* host, const char* username, const char* password);
	void Disconnect();

	bool IsConnected() const;

	sql::ResultSet* Select(const char* query);

private:
	sql::mysql::MySQL_Driver* m_Driver = nullptr;
	sql::Connection* m_Connection = nullptr;
	sql::Statement* m_Statement = nullptr;
	sql::ResultSet* m_ResultSet = nullptr;
};