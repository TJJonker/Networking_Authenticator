#pragma once
#include <string>
#include <MySQL/jdbc.h>

namespace Database {
	struct ConnectionInfo {
		std::string Host;
		std::string Username;
		std::string Password;
		std::string Schema;
	};

	class IDatabase {
	public:
		virtual ~IDatabase() = default;
		virtual void Connect(ConnectionInfo& info) = 0;
		virtual void Disconnect() = 0;
		
		virtual bool IsConnected() const = 0;
		virtual void SetSchema(const char* schema) = 0;

		virtual sql::PreparedStatement* PrepareStatement(const char* query) = 0;

		virtual sql::ResultSet* Select(const char* query) = 0;
		virtual int Update(const char* query) = 0;
		virtual int Insert(const char* query) = 0;
	};
}