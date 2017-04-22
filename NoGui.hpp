#ifndef NOGUI_HPP_
# define NOGUI_HPP_

#include "AView.hpp"
#include "IObserver.hpp"

namespace Plazza {
	namespace View {
		class NoGui : Plazza::View::AView, Plazza::IObserver {
		private:
			Plazza::Controller::IController *_controller;
			unsigned int _width;
			unsigned int _height;
			void initView();
			void getInputs();
			void displayData();
			void displayStatus();
		public:
			NoGui();
			virtual ~NoGui() {};
		};
	}
}

#endif
