#include "pch.h"
#include "DatabaseClient.h"

DatabaseClient::DatabaseClient() { }

DatabaseClient::~DatabaseClient()
{
    Destroy();
}

bool DatabaseClient::Initialize(const char* ip, const char* port)
{
    m_Client = new TwoNet::Networking::Client();
    m_Client->SetOnDataReceived(std::bind(&DatabaseClient::OnDataReceipt, this, std::placeholders::_1));
    m_Client->SetOnHandshake(std::bind(&DatabaseClient::OnHandshake, this));
    return m_Client->Initialize(ip, port);
}

void DatabaseClient::Destroy()
{
    delete m_Client;
}

bool DatabaseClient::Connect()
{
    int result = m_Client->Connect();

    std::string randomFillement = "Random";
    TwoNet::Buffer buffer;
    TwoNet::TwoProt::SerializeData(buffer, randomFillement.c_str(), randomFillement.length());
    TwoNet::TwoProt::SerializeData(buffer, randomFillement.c_str(), randomFillement.length());
    Submit(buffer, [](TwoNet::Buffer& buffer) {});

    return result;
}

void DatabaseClient::Update()
{
    m_Client->CheckForIncomingData();
}

bool DatabaseClient::AuthenticateUser(std::string authenticateData, ResultCallback callback)
{
    TwoNet::Buffer buffer;
    std::string command = "AUTHENTICATE";

    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    TwoNet::TwoProt::SerializeData(buffer, authenticateData.c_str(), authenticateData.length());    

    Submit(buffer,
        [&, callback](TwoNet::Buffer buffer) {
            TwoNet::Networking::NetworkResponse response;
            response.string = TwoNet::TwoProt::DeserializeData(buffer);
            callback(response);
        });

    return false;
}

bool DatabaseClient::CreateUser(std::string createUserData, ResultCallback callback)
{
    TwoNet::Buffer buffer;
    std::string command = "CREATE_USER";

    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    TwoNet::TwoProt::SerializeData(buffer, createUserData.c_str(), createUserData.length());

    Submit(buffer,
        [&, callback](TwoNet::Buffer buffer) {
            TwoNet::Networking::NetworkResponse response;
            response.string = TwoNet::TwoProt::DeserializeData(buffer);
            callback(response);
        });

    return false;
}

void DatabaseClient::Submit(TwoNet::Buffer& buffer, BufferCallback callback)
{
    static long index = 0;
    std::string stringedIndex = std::to_string(index);

    m_Submissions[index] = callback;
    index++;

    TwoNet::Buffer newBuffer;
    TwoNet::TwoProt::SerializeData(newBuffer, stringedIndex.c_str(), stringedIndex.length());

    std::string command = TwoNet::TwoProt::DeserializeData(buffer);
    TwoNet::TwoProt::SerializeData(newBuffer, command.c_str(), command.length());

    std::string data = TwoNet::TwoProt::DeserializeData(buffer);
    TwoNet::TwoProt::SerializeData(newBuffer, data.c_str(), data.length());

    m_Client->SendData(newBuffer);
}

void DatabaseClient::OnDataReceipt(TwoNet::Buffer& buffer)
{
    std::string data = TwoNet::TwoProt::DeserializeData(buffer);
    long requestID = std::stol(data);
    m_Submissions[requestID](buffer);
}

void DatabaseClient::OnHandshake()
{
}
