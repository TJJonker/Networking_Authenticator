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
	m_Driver = sql::mysql::get_mysql_driver_instance();
	m_Connection = m_Driver->connect(host, username, password);
}

void MySQLUtils::Disconnect()
{
	if(m_Connection)
		delete m_Connection;
}
