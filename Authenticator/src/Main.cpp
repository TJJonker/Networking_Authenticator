#include "pch.h"
#include <MySQL/MySQLUtils.h>

int main() {
#ifdef TWONET_DEBUG
	TwoNet::Log::Init();
#endif
	MySQLUtils db;
	db.ConnectToDatabase("127.0.0.1:3306", "root", "root");
}