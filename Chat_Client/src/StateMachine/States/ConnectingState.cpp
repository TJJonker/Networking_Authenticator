#include "pch.h"
#include "ConnectingState.h"
#include "LobbyState.h"
#include "Authenticate/Authenticate.pb.h"
#include "AuthenticateResponse/AuthenticateResponse.pb.h"
#include "CreateAccount/CreateAccount.pb.h"
#include "CreateAccountResponse/CreateAccountResponse.pb.h"

ConnectingState::ConnectingState(StateManager* stateManager, Networking* networking)
	: m_Networking(networking), m_StateManager(stateManager) { }

ConnectingState::~ConnectingState() { }

void ConnectingState::OnEnter()
{
	LOG_INFO("Trying to connect to the server...");
	if (!m_Networking->Connect(
		[&](TwoNet::Networking::NetworkResponse& response) {
			LOG_INFO("Connected to the server!");
			LOG_WARNING("Welcome!");
			ChooseLoginOrRegister();
		}))
	{
		TWONET_LOG_ERROR("Failed to connect to server. Please restart the application.");
		return;
	}
}

void ConnectingState::OnExit() { }

void ConnectingState::ChooseLoginOrRegister()
{
	LOG_WARNING("Please enter 'L' to login or 'R' to register.");
	std::string input;
	std::getline(std::cin, input);

	if (input == "L")
		Login();
	else if (input == "R")
		Register();
	else
		ChooseLoginOrRegister();
}

void ConnectingState::Login()
{
	std::string email;
	LOG_WARNING("Enter your email:");
	std::getline(std::cin, email);

	std::string password;
	LOG_WARNING("Enter your password:");
	std::getline(std::cin, password);

	Database::Authenticate authenticate;
	authenticate.set_requestid(1);
	authenticate.set_email(email);
	authenticate.set_password(password);

	std::string authenticateData;
	authenticate.SerializeToString(&authenticateData);
	std::string ad(authenticateData);

	m_Networking->Authenticate(authenticateData,
		[&](TwoNet::Networking::NetworkResponse localResponse) {
			Database::AuthenticateResponse response;
			response.ParseFromString(localResponse.string);

			if (response.success()) {
				LOG_WARNING("Authentication successful!");
				m_StateManager->ChangeState(StateManager::AppState::LOBBY);
			}
			else {
				if(response.failreason() == Database::AuthenticateResponse::FailReason::AuthenticateResponse_FailReason_INTERNAL_SERVER_ERROR)
					LOG_WARNING("Login failed: Internal server error.");
				if (response.failreason() == Database::AuthenticateResponse::FailReason::AuthenticateResponse_FailReason_INVALID_CREDENTIALS)
					LOG_WARNING("Login failed: Invalid credentials.");
				ChooseLoginOrRegister();
			}
		});
}

void ConnectingState::Register()
{
	std::string email;
	LOG_WARNING("Enter your email:");
	std::getline(std::cin, email);

	std::string password;
	LOG_WARNING("Enter your password:");
	std::getline(std::cin, password);

	Database::CreateAccount createAccount;
	createAccount.set_requestid(1);
	createAccount.set_email(email.c_str());
	createAccount.set_password(password.c_str());

	std::string createAccountData;
	bool result = createAccount.SerializeToString(&createAccountData);

	// Get rid of the null terminator
	m_Networking->CreateUser(createAccountData,
		[&](TwoNet::Networking::NetworkResponse localResponse) {
			Database::CreateAccountResponse response;
			response.ParseFromString(localResponse.string);

			if (response.success()) {
				LOG_WARNING("Authentication successful!");
				m_StateManager->ChangeState(StateManager::AppState::LOBBY);
			}
			else {
				if (response.failreason() == Database::CreateAccountResponse::FailReason::CreateAccountResponse_FailReason_ACCOUNT_ALREADY_EXISTS)
					LOG_WARNING("Login failed: Account with the given email already exists.");
				if (response.failreason() == Database::CreateAccountResponse::FailReason::CreateAccountResponse_FailReason_INTERNAL_SERVER_ERROR)
					LOG_WARNING("Login failed: Internal server error.");
				ChooseLoginOrRegister();
			}
		});
}

