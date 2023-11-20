#include "pch.h"
#include "CreatUserCommand.h"
#include "CreateAccountResponse/CreateAccountResponse.pb.h"

namespace Database {
    Response::DatabaseResponse Database::CreateUserCommand::Execute(TwoNet::Buffer& buffer)
    {
        Response::DatabaseResponse response;

        // Parse to CreateAccound object.
        Database::CreateAccount createAccount;
        response = ParseToObject(createAccount, buffer);
        CHECK(response, createAccount.requestid());

        // Check for existing account
        GetUserWithEmailData userData{ createAccount.email() };
        m_API.GetUserWithEmail(userData);
        CHECK(response, createAccount.requestid());

        if (response.GetResult()->next()) {
            response.SetFailureReason(Response::FailureReason::EMAIL_ALREADY_EXISTS);
            CHECK(response, createAccount.requestid());
        }

        // Hash password
        std::string salt = GetRandomString(8);
        std::string hashedPassword = (char*)HashPassword(createAccount.password(), salt);

        // Email, Salt, HashedPassword
        CreateUserData createUserData {createAccount.email(), salt, hashedPassword };
        response = m_API.CreateUser(createUserData);

        // Create response
        Database::CreateAccountResponse createUserResponse;
        createUserResponse.set_requestid(createAccount.requestid());
        createUserResponse.set_success(true);


        std::string data;
        createUserResponse.SerializeToString(&data);
        response.SetData(data);
        return response;
    }

    Response::DatabaseResponse CreateUserCommand::ParseToObject(Database::CreateAccount createAccount, TwoNet::Buffer& buffer)
    {
        const char* rawData = TwoNet::TwoProt::DeserializeData(buffer);
        return ParseTo<Database::CreateAccount>(rawData, createAccount);
    }

    unsigned char* CreateUserCommand::HashPassword(std::string rawPassword, std::string salt)
    {
        std::string saltedPassword = salt + rawPassword;
        unsigned char hashedPassword[SHA256_DIGEST_LENGTH];
        SHA256((unsigned char*)saltedPassword.c_str(), saltedPassword.length(), hashedPassword);
        return hashedPassword;
    }

    std::string CreateUserCommand::GetRandomString(unsigned int length)
    {
        std::string string;
        RAND_bytes((unsigned char*)&string[0], length);
        return string;
    }

    void CreateUserCommand::SetCreateUserFailData(Response::DatabaseResponse& response, long requestID)
    {
        // Check which error
        Database::CreateAccountResponse_FailReason reason = CreateAccountResponse_FailReason_NONE;

        switch (response.GetFailureReason()) {
            case Response::FailureReason::NO_CONNECTION: reason = CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR;  break;
            case Response::FailureReason::PARSING_ERROR: reason = CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR; break;
            case Response::FailureReason::INVALID_CREDENTIALS: reason = CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR; break;
            case Response::FailureReason::EMAIL_ALREADY_EXISTS: reason = CreateAccountResponse_FailReason_ACCOUNT_ALREADY_EXISTS; break;
            default: TWONET_CORE_ASSERT(false, "Not implemented.");
        }

        // Create response object
        Database::CreateAccountResponse responseData;
        responseData.set_requestid(requestID);
        responseData.set_success(false);
        responseData.set_failreason(reason);

        // Serialize it into data
        std::string serializedResponseData;
        responseData.SerializeToString(&serializedResponseData);

        // Put it into a response
        response.SetData(serializedResponseData);
    }
}