#include "Ncurses.hpp"

void Plazza::View::Ncurses::modeCanonique(int mode) {
}

void Plazza::View::Ncurses::Update(std::vector<std::string> data) {

}

void Plazza::View::Ncurses::initView() {
}

void Plazza::View::Ncurses::getInputs() {
}

void Plazza::View::Ncurses::displayData() {
}

void Plazza::View::Ncurses::displayStatus() {
}

Plazza::View::Ncurses::Ncurses(Plazza::Controller::IController *controller) : AView(controller) {
}

void Plazza::View::Ncurses::LoopView() {
    while (true) {
        getInputs();
    }
}