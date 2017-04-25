#ifndef NOGUI_HPP_
# define NOGUI_HPP_

#include <unistd.h>
#include "AView.hpp"
#include "IObserver.hpp"
#include "ProcessManagerSockets.hpp"

namespace Plazza {
	namespace View {
		class NoGui : public AView, public IObserver {
		public:
			NoGui(Plazza::Controller::IController *);
			void Update(std::vector<std::string> data);
			virtual ~NoGui() {};
			void initView();
			void displayData();
			void displayStatus();
			void getInputs();
			void initVIew();
		};
	}
}

#endif
