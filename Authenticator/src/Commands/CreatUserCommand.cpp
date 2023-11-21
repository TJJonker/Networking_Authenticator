#include "pch.h"
#include "CreatUserCommand.h"
#include "CreateAccountResponse/CreateAccountResponse.pb.h"
#include <random>
#include <sstream>
#include <iomanip>

namespace Database {
    Response::DatabaseResponse Database::CreateUserCommand::Execute(TwoNet::Buffer& buffer)
    {
        Response::DatabaseResponse response;

        // Parse to CreateAccound object.
        Database::CreateAccount createAccount;

        response = ParseToObject(createAccount, buffer);
        CHECK(response, createAccount.requestid());

        long ri = createAccount.requestid();
        std::string em = createAccount.email();
        std::string pw = createAccount.password();

        // Check for existing account
        GetUserWithEmailData userData{ createAccount.email() };
        response = m_API.GetUserWithEmail(userData);
        CHECK(response, createAccount.requestid());

        if (response.GetResult()->next() ) {
            response.SetFailureReason(Response::FailureReason::EMAIL_ALREADY_EXISTS);
            CHECK(response, createAccount.requestid());
        }

        // Hash password
        std::string salt = GetRandomString(64);
        std::string hashedPassword = HashPassword(createAccount.password(), salt);

        // Email, Salt, HashedPassword
        CreateUserData createUserData {createAccount.email(), salt, hashedPassword};
        response = m_API.CreateUser(createUserData);

        // Create response
        Database::CreateAccountResponse createUserResponse;
        createUserResponse.set_requestid(1);
        createUserResponse.set_success(true);
        createUserResponse.set_failreason(CreateAccountResponse_FailReason_NONE);


        std::string data;
        createUserResponse.SerializeToString(&data);
        response.SetData(data);

        return response;
    }

    Response::DatabaseResponse CreateUserCommand::ParseToObject(Database::CreateAccount& createAccount, TwoNet::Buffer& buffer)
    {
        const char* rawData = TwoNet::TwoProt::DeserializeData(buffer);
        return ParseTo<Database::CreateAccount>(rawData, createAccount);
    }

    std::string CreateUserCommand::HashPassword(const std::string& rawPassword, const std::string& salt)
    {
        std::string saltedPassword = salt + rawPassword;
        std::vector<unsigned char> hashedPassword(SHA256_DIGEST_LENGTH);
        
        SHA256((const unsigned char*)saltedPassword.c_str(), saltedPassword.length(), hashedPassword.data());

        std::stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)hashedPassword[i];
        }
        return ss.str();
    }

    std::string CreateUserCommand::GetRandomString(unsigned int length)
    {
        static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, sizeof(charset) - 2);

        std::string result;
        result.reserve(length);

        for (std::size_t i = 0; i < length; ++i) {
            result += charset[dis(gen)];
        }

        return result;
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
        responseData.set_requestid(1);
        responseData.set_userid(1);
        responseData.set_success(false);
        responseData.set_failreason(reason);

        // Serialize it into data
        std::string serializedResponseData;
        responseData.SerializeToString(&serializedResponseData);

        // Put it into a response
        response.SetData(serializedResponseData);
    }
}