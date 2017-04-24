#include "AController.hpp"

void Plazza::Controller::AController::Reset()
{
}

void Plazza::Controller::AController::SetCommandLine(std::string command) {
	this->_commandLine = command;
}

std::string Plazza::Controller::AController::GetCommandLine() {
	return this->_commandLine;
}

Plazza::Controller::AController::AController() {
	std::cout << "Construction du AController" << std::endl;
}
