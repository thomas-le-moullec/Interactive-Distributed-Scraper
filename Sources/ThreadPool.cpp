#include "ThreadPool.hpp"

Plazza::Controller::ThreadPool::ThreadPool(unsigned int nbThreads, Plazza::Model::IModel *model) : _nbThreads(nbThreads), _ordersExecuted(0), _model(model)
{
  _mutex = new Mutex();
  _time.update();
  for (unsigned int i = 0; i < _nbThreads; i++)
    _threads.insert(_threads.end(), new Plazza::Thread(NULL, &Plazza::Controller::execOrder, this));

  /*for (unsigned int i = 0; i < _nbThreads; i++)
    _threads.insert(_threads.end(), new std::thread(&ThreadPool::execOrder, this));*/
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
  std::vector<std::string> informations;
  std::vector<Plazza::IStrategyCipher *> 	ciphers;

  ciphers.insert(ciphers.end(), new Plazza::Xor());
  ciphers.insert(ciphers.end(), new Plazza::Caesar());

  while (1)
  {
    std::string 							fileContent;
    Plazza::Controller::Order order = popOrder();
    _ordersExecuted++;
      //std::cout << "File Name order => " << order._file << " et size _ciphers => " << _ciphers.size() << std::endl; //AFFICHE
    for (int i = 0; i < _ciphers.size(); i++) {
        //std::cout << "ENTRE DANS LE FOR"<< std::endl;
      try {
        fileContent = ciphers[i]->executeCipher(order._file);
      }
      catch (RunTimeErrorController const &stdErr) {
        std::cerr << stdErr.what() << std::endl;
        _ordersExecuted--;
        return;
      }
        //std::cout << "File Content => " << fileContent << std::endl;
      if (!fileContent.empty()) {
        informations = order._strategy->ExecuteStrategy(fileContent);
          //std::cout << "Informations => " << informations[0] << std::endl;
        _model->GetData(informations);
        break;
      }
    }
    _time.update();
    _ordersExecuted--;
  }
}

void									*Plazza::Controller::execOrder(void *data)
{
  Plazza::Controller::ThreadPool	*tp = static_cast<Plazza::Controller::ThreadPool *>(data);

  tp->execOrder();
  return NULL;
}

int										Plazza::Controller::ThreadPool::getCurrentOrder()
{
  _now.update();
  std::cout << "Diff time " <<  _now.diffTime(_time) << std::endl;
    std::cout << "Nb order --> " << _orders.size() + _ordersExecuted << std::endl;
  if (_orders.size() + _ordersExecuted == 0 &&  _now.diffTime(_time) >= 5)
    return -1;
  return static_cast<int>(_ordersExecuted);
}
