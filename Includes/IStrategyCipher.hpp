#ifndef ISTRATEGYCIPHER_HPP_
# define ISTRATEGYCIPHER_HPP_

#include <iostream>
#include "Errors.hpp"

namespace Plazza {
	class IStrategyCipher {
	public:
		virtual std::string executeCipher(std::string const &) = 0;
		virtual ~IStrategyCipher(){};
	};
}

#endif