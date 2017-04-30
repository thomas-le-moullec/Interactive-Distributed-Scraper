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
    std::unique_ptr<Plazza::Model::IModel> model(new Plazza::Model::Information());
    std::unique_ptr<Plazza::Controller::IController> controller(new Plazza::Controller::ProcessManagerSockets(nbThreads, model.get()));
    std::unique_ptr<Plazza::View::IView> viewNcurses(new Plazza::View::Ncurses(controller.get()));

    static_cast<Plazza::Model::AModel *>(model.get())->AddObserver(static_cast<Plazza::View::Ncurses *>(viewNcurses.get()));
  viewNcurses->LoopView();
  return 0;
};
