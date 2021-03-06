#ifndef 	INFORMATION_HPP
# define 	INFORMATION_HPP

#include "AModel.hpp"

namespace Plazza {
	namespace Model {
		class Information : public AModel {
		private:
            std::vector<std::vector<std::string>> _informations;
		public:
			void Reset();
			void GetData(std::vector<std::string>);
			void SaveData(const std::string &);
			virtual ~Information() {};
			Information();
		};
	}
}

#endif
