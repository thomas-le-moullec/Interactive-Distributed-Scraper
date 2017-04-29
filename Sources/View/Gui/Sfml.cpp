#include "Sfml.hpp"

void 								Plazza::View::Sfml::Update(std::vector<std::string> data) {
  (void)data;
}

void Plazza::View::Sfml::initView() {
}

void Plazza::View::Sfml::getInputs() {
}

void Plazza::View::Sfml::displayData() {
}

void Plazza::View::Sfml::displayStatus() {
}

Plazza::View::Sfml::Sfml(Plazza::Controller::IController *controller) : AView(controller), _commandToPrint("") {
}

Plazza::View::Sfml::~Sfml() {
}

void Plazza::View::Sfml::LoopView() {
    while (true) {
        getInputs();
    }
}
