#include "Information.hpp"
#include "Ncurses.hpp"
#include "NoGui.hpp"

int main()
{
    Plazza::Model::IModel *model = new Plazza::Model::Information();
    Plazza::Controller::IController *controller = new Plazza::Controller::ProcessManagerSockets(5, model); //ok
    Plazza::View::IView *viewNoGui = new Plazza::View::NoGui(controller);

    static_cast<Plazza::Model::AModel *>(model)->AddObserver(static_cast<Plazza::View::NoGui *>(viewNoGui));
    viewNoGui->LoopView();
    return 0;
};
