#include "pch.h"
#include "CreatUserCommand.h"


namespace Database {
    Response::DatabaseResponse Database::CreateUserCommand::Execute(TwoNet::Buffer& buffer)
    {
        Response::DatabaseResponse response;

        // Parse to CreateAccound object.
        Database::CreateAccount createAccount;
        response = ParseToObject(createAccount, buffer);
        CHECK(response);

        // Check for existing account
        GetUserWithEmailData userData{ createAccount.email() };
        m_API.GetUserWithEmail(userData);
        CHECK(response);

        if (response.GetResult()->next()) {
            response.SetFailureReason(Response::FailureReason::EMAIL_ALREADY_EXISTS);
            return response;
        }

        // Hash password
        std::string salt = GetRandomString(8);
        std::string hashedPassword = (char*)HashPassword(createAccount.password(), salt);

        // Email, Salt, HashedPassword
        CreateUserData createUserData {createAccount.email(), salt, hashedPassword };
        return m_API.CreateUser(createUserData);
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
}