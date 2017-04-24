#ifndef TIME_HPP_
#define	TIME_HPP_

#include <time.h>

namespace Plazza {
  class		Time
  {
  public:
    Time();
    ~Time();
    int				diffTime(Time);
    time_t		getTime() const;
    void			update();
  private:
    time_t	_time;
  };
}

#endif
