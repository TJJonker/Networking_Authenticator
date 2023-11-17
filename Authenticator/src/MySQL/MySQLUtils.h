#pragma once
#include <MySQL/jdbc.h>

class MySQLUtils
{
public:
	MySQLUtils();
	~MySQLUtils();

	void ConnectToDatabase(const char* host, const char* username, const char* password);
	void Disconnect();

private:
	sql::mysql::MySQL_Driver* m_Driver;
	sql::Connection* m_Connection;
};

