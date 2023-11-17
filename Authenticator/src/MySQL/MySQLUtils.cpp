#include "pch.h"
#include "MySQLUtils.h"

MySQLUtils::MySQLUtils()
{
}

MySQLUtils::~MySQLUtils()
{
	Disconnect();
}

void MySQLUtils::ConnectToDatabase(const char* host, const char* username, const char* password)
{
	TWONET_ASSERT(!m_Connection, "Connection with the database is already established.");

	try {
		m_Driver = sql::mysql::get_mysql_driver_instance();
		m_Connection = m_Driver->connect(host, username, password);
	}
	catch (sql::SQLException& e) {
		TWONET_ERROR("Could not establish connection with the database: {0}", e.what());
		return;
	}
}

void MySQLUtils::Disconnect()
{
	TWONET_ASSERT(m_Connection, "No connection to disconnect.");
	delete m_Connection;
}

bool MySQLUtils::IsConnected() const
{
	return m_Connection;
}
