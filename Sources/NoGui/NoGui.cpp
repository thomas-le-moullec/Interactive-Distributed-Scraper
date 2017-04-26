#include "NoGui.hpp"

void Plazza::View::NoGui::initView() {
}

void Plazza::View::NoGui::getInputs() {
	char	buff[1];

	buff[0] = 0;
	read(1, &buff, 1);
	_processManager->NotifyController(buff[0]);
	//std::cout << "-->" << buff[0] << "<--" << std::endl;
	/*std::string	str;

	getline(std::cin, str);*/
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
    //Fill Data needed by the View
    //_data = data;
}

void Plazza::View::NoGui::LoopView() {
    while (true) {
        getInputs();
        //Display(std::vector<std::string> data);
    }
}
