#include "ThreadPool.hpp"

Plazza::Controller::ThreadPool::ThreadPool(unsigned int nbThreads) : _nbThreads(nbThreads), _ordersExecuted(0)
{
  _mutex = new Mutex();
  _time.update();
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
    Order order = popOrder();
    _ordersExecuted++;
    //order._strategy->execute(order._file);
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
