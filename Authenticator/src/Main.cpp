#include "pch.h"
#include <MySQL/MySQLUtils.h>

MySQLUtils db;

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif

	db.ConnectToDatabase("127.0.0.1:3306", "root", "root");
	sql::ResultSet* result = db.Select("SELECT * FROM enemy");
	
	while (result->next()) {
		sql::SQLString name = result->getString("name");
	}
}

