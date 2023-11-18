#pragma once
#include <string>
#include <MySQL/jdbc.h>
#include "Database/DataStructs/ConnectionInfo.h"

namespace Database {
	class IDatabase {
	public:
		virtual ~IDatabase() = default;
		virtual void Connect(const ConnectionInfo& info) = 0;
		virtual void Disconnect() = 0;
		
		virtual bool IsConnected() const = 0;
		virtual void SetSchema(const char* schema) = 0;

		virtual sql::PreparedStatement* PrepareStatement(const char* query) = 0;
	};
}