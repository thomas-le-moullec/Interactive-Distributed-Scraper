#include "ContextInformation.hpp"

void Plazza::ContextInformation::ExecuteStrategy(std::string const &fileContent) {
	return _strategy->execute(fileContent);
}

Plazza::ContextInformation::ContextInformation(Plazza::IStrategyInformation *strategy){
	_strategy = strategy;
}
