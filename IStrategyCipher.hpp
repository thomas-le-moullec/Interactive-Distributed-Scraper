#ifndef ISTRATEGYCIPHER_HPP_
# define ISTRATEGYCIPHER_HPP_

#include <iostream>

namespace Plazza {
	class IStrategyCipher {
	private:
		virtual void execute(std::string cipherPattern) = 0;

	public:
		virtual ~IStrategyCipher(){};
	};
}

#endif