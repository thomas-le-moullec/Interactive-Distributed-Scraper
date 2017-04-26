#ifndef IMODEL_HPP_
# define IMODEL_HPP_

#include <iostream>
#include <vector>

namespace Plazza {
	namespace Model {
		class IModel {
        public:
			virtual void Reset() = 0;
			virtual void GetData(std::vector<std::string>) = 0;
			virtual void SaveData(std::string) = 0;
			virtual ~IModel() {};
		};
	}
}

#endif
