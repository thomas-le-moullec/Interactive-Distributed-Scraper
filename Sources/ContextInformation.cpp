#include "ContextInformation.hpp"

std::vector<std::string> Plazza::ContextInformation::ExecuteStrategy(std::string const &fileContent) {
	return _strategy->execute(fileContent);
}

Plazza::ContextInformation::ContextInformation(Plazza::IStrategyInformation *strategy){
	_strategy = strategy;
}
