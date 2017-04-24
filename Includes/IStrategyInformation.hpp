#ifndef ISTRATEGYINFORMATION_HPP_
#define ISTRATEGYINFORMATION_HPP_

#include <iostream>
#include <vector>

namespace Plazza {
	class IStrategyInformation {

	public:
        virtual void execute(std::string const &) = 0;
		virtual ~IStrategyInformation() {};
		virtual bool IsValidInformation(char const &) = 0;
		virtual int  FindInformation(int) = 0;
	};
}

#endif
