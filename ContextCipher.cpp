#include "ContextCipher.hpp"

std::string Plazza::ContextCipher::ExecuteStrategy() {
	return _strategy->executeCipher();
}

Plazza::ContextCipher::ContextCipher(Plazza::IStrategyCipher *strategy) {
	_strategy = strategy;
}
