#include "NoGui.hpp"

void Plazza::View::NoGui::initVIew()
{

}

void Plazza::View::NoGui::initView() {
}

void Plazza::View::NoGui::getInputs() {
	char	buff[1];

	read(1, &buff, 1);
	_processManager->NotifyController(buff[0]);
}

void Plazza::View::NoGui::displayData() {
}

void Plazza::View::NoGui::displayStatus() {
}

Plazza::View::NoGui::NoGui() {
	_processManager = new Plazza::Controller::ProcessManagerSockets(5);
}
