#include "Time.hpp"

Plazza::Time::Time()
{
}

Plazza::Time::~Time()
{
}

int			Plazza::Time::diffTime(Plazza::Time _other)
{
  return static_cast<int>(difftime(_time, _other.getTime()));
}

time_t		Plazza::Time::getTime() const
{
  return _time;
}

void		Plazza::Time::update()
{
  time(&_time);
}
