#ifndef ISTRATEGYINFORMATION_HPP_
# define ISTRATEGYINFORMATION_HPP_

#include <iostream>

namespace Plazza {
	class IStrategyInformation {
	private:
		virtual void execute(std::string file) = 0;
		virtual bool isValidInformation(char const &) = 0;
		virtual int  FindInformation(int) = 0;

	public:
		virtual ~IStrategyInformation() {};
	};
}

#endif