#pragma once
#include <TwoNet/DataStructs/NetworkResponse.h>
#include <TwoNet/Buffer/Buffer.h>
#include <TwoNet/Networking/Client/Client.h>
#include <map>
#include "Authenticate/Authenticate.pb.h"
#include "CreateAccount/CreateAccount.pb.h"

class DatabaseClient
{
private:
	using ResultCallback = std::function<void(TwoNet::Networking::NetworkResponse)>;
	using BufferCallback = std::function<void(TwoNet::Buffer& buffer)>;

	TwoNet::Networking::Client* m_Client = nullptr;
	std::map<long, BufferCallback> m_Submissions = {};

public:
	DatabaseClient();
	~DatabaseClient();

	bool Initialize(const char* ip, const char* port);
	void Destroy();

	bool Connect();

	void Update();

	bool AuthenticateUser(std::string authenticateData, ResultCallback callback);
	bool CreateUser(std::string authenticateData, ResultCallback callback);

private:
	void Submit(TwoNet::Buffer& buffer, BufferCallback callback);
	void OnDataReceipt(TwoNet::Buffer& buffer);
	void OnHandshake();
};

