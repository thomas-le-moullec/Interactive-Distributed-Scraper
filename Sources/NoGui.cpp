#include "NoGui.hpp"

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

Plazza::View::NoGui::NoGui(Plazza::Controller::IController *controller) : AView(controller) {
}

void Plazza::View::NoGui::Update(std::vector<std::string> data) {
	//std::cout << "HELLO VIEW" << std::endl;
    for (int i = 0; i <  data.size(); i++) {
        std::cout << data[i] << std::endl;
    }
    //Fill Data needed by the View
    //_data = data;
}

void Plazza::View::NoGui::LoopView() {
    while (true) {
        getInputs();
        //Display(std::vector<std::string> data);
    }
}
