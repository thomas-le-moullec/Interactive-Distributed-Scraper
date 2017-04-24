#include "NoGui.hpp"

void Plazza::View::NoGui::initVIew()
{

}

void Plazza::View::NoGui::initView() {
	// TODO - implement NoGui::initView
	throw "Not yet implemented";
}

void Plazza::View::NoGui::getInputs() {
	char	buff[1];

	read(1, &buff, 1);
	_processManager->NotifyController(buff[0]);
}

void Plazza::View::NoGui::displayData() {
	// TODO - implement NoGui::displayData
	throw "Not yet implemented";
}

void Plazza::View::NoGui::displayStatus() {
	// TODO - implement NoGui::displayStatus
	throw "Not yet implemented";
}

Plazza::View::NoGui::NoGui() {
	  _processManager = new Plazza::Controller::ProcessManagerSockets(5);
}
