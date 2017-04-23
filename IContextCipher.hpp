#ifndef ICONTEXTCIPHER_HPP_
# define ICONTEXTCIPHER_HPP_

#include "IStrategyCipher.hpp"

namespace Plazza {
	class IContextCipher {
	public:
		virtual std::string ExecuteStrategy() = 0;
		virtual ~IContextCipher() {};
	};
}

#endif