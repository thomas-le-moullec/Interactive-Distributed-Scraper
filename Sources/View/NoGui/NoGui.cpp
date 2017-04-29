#include "NoGui.hpp"

void Plazza::View::NoGui::initView() {
}

void Plazza::View::NoGui::getInputs() {
	std::string	str;

	getline(std::cin, str);
	if (str == "")
		str = "exit";
	_processManager->NotifyController(str);
}

void Plazza::View::NoGui::displayData() {
}

void Plazza::View::NoGui::displayStatus() {
}

Plazza::View::NoGui::NoGui(Plazza::Controller::IController *controller) : AView(controller) {
	_mutex = new Plazza::Mutex();
}

void Plazza::View::NoGui::Update(std::vector<std::string> data) {
    for (unsigned int i = 0; i < data.size(); i++) {
      std::cout << data[i] << std::endl;
    }
}

void Plazza::View::NoGui::LoopView() {
    while (true) {
        getInputs();
        //Display(std::vector<std::string> data);
    }
}
