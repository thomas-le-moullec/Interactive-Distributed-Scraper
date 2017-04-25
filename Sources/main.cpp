#include "Information.hpp"
#include "Ncurses.hpp"
#include "NoGui.hpp"

int main()
{
    Plazza::Model::IModel *model = new Plazza::Model::Information();
    Plazza::Controller::IController *controller = new Plazza::Controller::ProcessManagerSockets(5, model); //ok
    //Plazza::View::IView *viewNoGui = new Plazza::View::NoGui(controller);
    Plazza::View::IView *viewNcurses = new Plazza::View::Ncurses(controller);

    //static_cast<Plazza::Model::AModel *>(model)->AddObserver(static_cast<Plazza::View::NoGui *>(viewNoGui));
    static_cast<Plazza::Model::AModel *>(model)->AddObserver(static_cast<Plazza::View::Ncurses *>(viewNcurses));
    while (true) {
        viewNcurses->getInputs();
    }
    return 0;
};
