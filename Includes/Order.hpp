#ifndef ORDER_HPP_
#define ORDER_HPP_

#include <iostream>
#include "IStrategyInformation.hpp"
#include "IContextInformation.hpp"

namespace Plazza {
	namespace Controller {

		struct Order {
			IContextInformation *_strategy;
			std::string _file;
		};

		enum Information
		{
			PHONE_NUMBER,
			EMAIL_ADDRESS,
			IP_ADDRESS
		};

		struct              orderBySocket
		{
			Information     info;
			std::string     fileName;
		};
  }
}

#endif
