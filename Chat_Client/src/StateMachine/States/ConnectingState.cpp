#include "pch.h"
#include "ConnectingState.h"
#include "LobbyState.h"

ConnectingState::ConnectingState(StateManager* stateManager, Networking* networking)
	: m_Networking(networking), m_StateManager(stateManager) { }

ConnectingState::~ConnectingState() { }

void ConnectingState::OnEnter()
{
	std::string username;

	LOG_WARNING("Welcome!");
	LOG_WARNING("Please enter a username.");

	std::getline(std::cin, username);

	LOG_INFO("Trying to connect to the server...");
	std::string welcomeMessage;
	if (!m_Networking->Connect([&](TwoNet::Networking::NetworkResponse& response) {
			LOG_INFO("Connected to the server!");
			LOG_WARNING(welcomeMessage);
			m_StateManager->ChangeState(StateManager::AppState::LOBBY);
		})) {
		TWONET_LOG_ERROR("Failed to connect to server. Please restart the application.");
		return;
	}

}

void ConnectingState::OnExit() { }

