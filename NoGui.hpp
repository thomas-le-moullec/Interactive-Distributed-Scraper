#ifndef NOGUI_HPP_
# define NOGUI_HPP_

#include <unistd.h>
#include "AView.hpp"
#include "IObserver.hpp"
#include "ProcessManagerSockets.hpp"

namespace Plazza {
	namespace View {
		class NoGui : public AView {
		private:
			//Plazza::Controller::IController *_controller;
			Plazza::Controller::IProcessManager *_processManager;

			unsigned int _width;
			unsigned int _height;
		public:
			NoGui();
			virtual ~NoGui() {};
			void initView();
			void displayData();
			void displayStatus();
			void getInputs();
			void initVIew();
		};
	}
}

// HERITE DE IOBSERVER

#endif
