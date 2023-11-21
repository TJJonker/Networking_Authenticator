#include "pch.h"
#include "AuthenticateUserCommand.h"

void Commands::AuthenticateUserCommand::Execute(TwoNet::Buffer& buffer, const Networking::Client& client, callback callback)
{
    m_DatabaseClient.AuthenticateUser(TwoNet::TwoProt::DeserializeData(buffer),
        [&, callback](TwoNet::Networking::NetworkResponse& response) {
            Networking::Response::ServerResponse newResponse;
            newResponse.SetData({ response.string });
            callback(newResponse);
        });
}
