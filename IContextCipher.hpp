#ifndef ICONTEXTCIPHER_HPP_
# define ICONTEXTCIPHER_HPP_

#include "IStrategyCipher.hpp"

namespace Plazza {
	class IContextCipher {
	private:
		virtual void ExecuteStrategy() = 0;
		virtual void Context(Plazza::IStrategyCipher *) = 0;

	public:
		virtual ~IContextCipher() {};
	};
}

#endif