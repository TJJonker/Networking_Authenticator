#include "pch.h"
#include "RegisterClientCommand.h"

void Commands::RegisterClientCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback)
{
    m_DatabaseClient.CreateUser(TwoNet::TwoProt::DeserializeData(buffer),
        [&, callback](TwoNet::Networking::NetworkResponse& response) {
            Networking::Response::ServerResponse newResponse;
            newResponse.SetData({ response.string });
            callback(newResponse);
        });
}
