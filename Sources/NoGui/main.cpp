#include "Information.hpp"
#include "Ncurses.hpp"
#include "NoGui.hpp"

int	mainError(const std::string &str)
{
  std::cout << str << std::endl;
  return 1;
}

int main(int ac, char **av)
{
  if (ac != 2)
    return mainError("Usage: ./plazza [number of threads]");

  int	nbThreads = atoi(av[1]);

  if (nbThreads <= 0)
    return mainError("Usage: the number of threads per process must be positive");
  Plazza::Model::IModel *model = new Plazza::Model::Information();
  Plazza::Controller::IController *controller = new Plazza::Controller::ProcessManagerSockets(nbThreads, model);
  Plazza::View::IView *viewNoGui = new Plazza::View::NoGui(controller);

  static_cast<Plazza::Model::AModel *>(model)->AddObserver(static_cast<Plazza::View::NoGui *>(viewNoGui));
  viewNoGui->LoopView();
  return 0;
};
