#include "ThreadPool.hpp"

Plazza::Controller::ThreadPool::ThreadPool(unsigned int nbThreads, Plazza::Model::IModel *model, std::vector<Plazza::IStrategyCipher *> &ciphers) : _nbThreads(nbThreads), _ordersExecuted(0), _ciphers(ciphers), _model(model)
{
  _mutex = new Mutex();
  _time.update();
    _model = model;
    _ciphers = ciphers;
  for (unsigned int i = 0; i < _nbThreads; i++)
    _threads.insert(_threads.end(), new std::thread(&ThreadPool::execOrder, this));
}

Plazza::Controller::ThreadPool::~ThreadPool()
{
}

void									Plazza::Controller::ThreadPool::pushOrder(Order order)
{
  _time.update();
  _mutex->lock();
  _orders.insert(_orders.end(), order);
  _cond.signal();
  _mutex->unlock();
}

Plazza::Controller::Order								Plazza::Controller::ThreadPool::popOrder()
{
  _mutex->lock();
  while (_orders.empty())
    _cond.wait(_mutex);
  Order order = _orders[0];
  _orders.erase(_orders.begin());
  _mutex->unlock();
  return order;
}

void									Plazza::Controller::ThreadPool::execOrder()
{
  while (true)
  {
    std::string fileContent;
    Order order = popOrder();
    _ordersExecuted++;
    /*for (std::vector<IStrategyCipher *>::iterator it = _ciphers.begin() ; it != _ciphers.end(); ++it) {
      if ((fileContent = _ciphers[*it].executeCipher(order._file)) != NULL) {
        order._strategy->ExecuteStrategy(fileContent);
        break;
      }
    }*/
      for (int i = 0; i < _ciphers.size(); i++) {
              fileContent = _ciphers[i]->executeCipher(order._file);
          if (!fileContent.empty()) {
              order._strategy->ExecuteStrategy(fileContent);
              break;
          }
      }
    _time.update();
    _ordersExecuted--;
  }
}

int										Plazza::Controller::ThreadPool::getCurrentOrder()
{
  _now.update();
  std::cout << "Diff time " <<  _now.diffTime(_time) << std::endl;
  if (_orders.size() + _ordersExecuted == 0 &&  _now.diffTime(_time) >= 5)
    return -1;
  return static_cast<int>(_orders.size() + _ordersExecuted);
}