#include "pch.h"
#include "Database.h"

namespace Database {
	Database::Database() { }

	Database::~Database()
	{
		if (m_Connection)
			delete m_Connection;
		if (m_ResultSet)
			delete m_ResultSet;
		if (m_Statement)
			delete m_Statement;
		if (m_Driver)
			delete m_Driver;
	}

	void Database::Connect(const ConnectionInfo& info)
	{
		TWONET_ASSERT(!m_Connection, "Connection with the database is already established.");

		try {
			m_Driver = sql::mysql::get_mysql_driver_instance();
			m_Connection = m_Driver->connect(info.Host, info.Username, info.Password);
			m_Statement = m_Connection->createStatement();
			TWONET_CORE_INFO("Succesfully connected to the database.");
			SetSchema(info.Schema.c_str());
			TWONET_CORE_INFO("Succesfully set schema");

		}
		catch (sql::SQLException& e) {
			TWONET_CORE_ERROR("Could not establish connection with the database: {0}", e.what());
			return;
		}
	}

	void Database::Disconnect()
	{
		TWONET_CORE_ASSERT(m_Connection, "No connection to disconnect.");
		m_Connection->close();
	}

	bool Database::IsConnected() const
	{
		return m_Connection;
	}

	sql::PreparedStatement* Database::PrepareStatement(const char* query)
	{
		try {
			return m_Connection->prepareStatement(query);
		}
		catch (sql::SQLException& e) {
			std::cerr << "SQLException: " << e.what() << std::endl;
			std::cerr << "SQLState: " << e.getSQLState() << std::endl;
			std::cerr << "VendorError: " << e.getErrorCode() << std::endl;
			// Handle the exception or rethrow it as needed.
			throw;
		}
	}

	void Database::SetSchema(const char* schema)
	{
		m_Connection->setSchema(schema);
	}
}