#include "pch.h"
#include "Networking.h"
#include <TwoNet/Protocols/TwoProt.h>


Networking::Networking()
	:m_Client(nullptr) { }

Networking::~Networking() 
{ 
	Destroy();
}

bool Networking::Initialize(const char* ip, const char* port)
{
	m_Client = new TwoNet::Networking::Client();
    m_Client->SetOnDataReceived(std::bind(&Networking::OnDataReceipt, this, std::placeholders::_1));
    m_Client->SetOnHandshake(std::bind(&Networking::OnHandshake, this));
    return m_Client->Initialize(ip, port);
}

void Networking::Destroy()
{
	delete m_Client;
}

bool Networking::Connect(ResultCallback callback)
{
    int result = m_Client->Connect();

    std::string randomFillement = "Random";
    TwoNet::Buffer buffer;
    TwoNet::TwoProt::SerializeData(buffer, randomFillement.c_str(), randomFillement.length());
    TwoNet::TwoProt::SerializeData(buffer, randomFillement.c_str(), randomFillement.length());
    Submit(buffer, 
        [callback](TwoNet::Buffer& buffer) {
            TwoNet::Networking::NetworkResponse response;
            callback(response);
        });

    return result;
}

void Networking::Update()
{
    m_Client->CheckForIncomingData();
}

bool Networking::RequestRooms(ResultCallback callback)
{
	TwoNet::Buffer buffer;
	std::string command = "LIST_ROOMS";

	TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    // Second time for hacky reasons
	TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    Submit(buffer, 
        [&, callback](TwoNet::Buffer buffer) {
            TwoNet::Networking::NetworkResponse response;
            while (true) {
                const char* data = TwoNet::TwoProt::DeserializeData(buffer);
                if (data == nullptr)
                    break;
                response.List.push_back(data);
            }
            callback(response);
        });

	return true;
}

bool Networking::JoinRoom(std::string roomName, ResultCallback callback)
{
    TwoNet::Buffer buffer;
    std::string command = "JOIN_ROOM";
    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length()); 
    TwoNet::TwoProt::SerializeData(buffer, roomName.c_str(), roomName.length());

    Submit(buffer, 
        [&, callback](TwoNet::Buffer localBuffer) {
            TwoNet::Networking::NetworkResponse response;
            response.string = TwoNet::TwoProt::DeserializeData(localBuffer);
            if (response.string != "")
                callback(response);
        }
    );

    return true;
}

bool Networking::LeaveRoom(ResultCallback callback)
{
    TwoNet::Buffer buffer; 
    std::string command = "LEAVE_ROOM"; 

    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    // Second time for hacky reasons
    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    Submit(buffer, 
        [&, callback](TwoNet::Buffer localBuffer) {
            TwoNet::Networking::NetworkResponse response;
            response.string = TwoNet::TwoProt::DeserializeData(localBuffer);
            if (response.string != "")
                callback(response);
        }
    );

    return true;
}

bool Networking::SendChat(std::string message, ResultCallback callback)
{
    TwoNet::Buffer buffer;
    std::string command = "SEND_MESSAGE";

    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length()); 
    TwoNet::TwoProt::SerializeData(buffer, message.c_str(), message.length());

    Submit(buffer, 
        [&, callback](TwoNet::Buffer localBuffer) {
            TwoNet::Networking::NetworkResponse response;
            response.string = TwoNet::TwoProt::DeserializeData(localBuffer);
            if (response.string != "")
                callback(response);
        }
    );

    return true;
}

bool Networking::RequestMessages(ResultCallback callback)
{
    TwoNet::Buffer buffer; 
    std::string command = "GET_MESSAGES";

    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());
    // Second time for hacky reasons
    TwoNet::TwoProt::SerializeData(buffer, command.c_str(), command.length());

    Submit(buffer, 
        [&, callback](TwoNet::Buffer& localBuffer) {
            TwoNet::Networking::NetworkResponse response;
            while (true) {
                const char* data = TwoNet::TwoProt::DeserializeData(localBuffer);
                if (data == nullptr)
                    break;
                response.List.push_back(data);
            }
            callback(response);
        }
    );

    return true;
}


void Networking::Submit(TwoNet::Buffer& buffer, BufferCallback callback)
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

void Networking::OnDataReceipt(TwoNet::Buffer& buffer)
{
    std::string data = TwoNet::TwoProt::DeserializeData(buffer);
    long requestID = std::stol(data);
    m_Submissions[requestID](buffer);
}

void Networking::OnHandshake()
{
    //std::string randomFillement = "Random";
    //TwoNet::Buffer buffer;
    //TwoNet::TwoProt::SerializeData(buffer, randomFillement.c_str(), randomFillement.length());
    //TwoNet::TwoProt::SerializeData(buffer, randomFillement.c_str(), randomFillement.length());
    //Submit(buffer, [](TwoNet::Buffer& buffer) {});
}

