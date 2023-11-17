#include "pch.h"
#include "MySQLUtils.h"

MySQLUtils::MySQLUtils()
	: m_Connection(nullptr), m_Driver(nullptr), m_ResultSet(nullptr), m_Statement(nullptr)
{
}

MySQLUtils::~MySQLUtils()
{
	if (m_Connection)
		delete m_Connection;
	if (m_ResultSet)
		delete m_ResultSet;
	if (m_Statement)
		delete m_Statement;
}

void MySQLUtils::ConnectToDatabase(const char* host, const char* username, const char* password)
{
	TWONET_ASSERT(!m_Connection, "Connection with the database is already established.");

	try {
		m_Driver = sql::mysql::get_mysql_driver_instance();
		m_Connection = m_Driver->connect(host, username, password);
		m_Statement = m_Connection->createStatement();
		TWONET_CORE_INFO("Succesfully connected to the database.");
		m_Connection->setSchema("gdp");
		TWONET_CORE_INFO("Succesfully set schema");

	}
	catch (sql::SQLException& e) {
		TWONET_CORE_ERROR("Could not establish connection with the database: {0}", e.what());
		return;
	}
}

void MySQLUtils::Disconnect()
{
	TWONET_CORE_ASSERT(m_Connection, "No connection to disconnect.");
	m_Connection->close();
}

bool MySQLUtils::IsConnected() const
{
	return m_Connection;
}

sql::ResultSet* MySQLUtils::Select(const char* query)
{
	return m_Statement->executeQuery(query);
}