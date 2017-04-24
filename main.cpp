#include "Information.hpp"
#include "Ncurses.hpp"
#include "NoGui.hpp"

int main()
{
    //Plazza::Model::Information toto();
    Plazza::View::IView *view = new Plazza::View::NoGui();

    while (true)
      view->getInputs();
    return 0;
};
