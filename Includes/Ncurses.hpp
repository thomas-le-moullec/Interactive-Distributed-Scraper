#ifndef NCURSES_HPP_
# define NCURSES_HPP_

#include "AView.hpp"
#include "IObserver.hpp"
#include "ProcessManagerSockets.hpp"
#include <curses.h>

namespace Plazza {
	namespace View {
		class Ncurses : public AView, public IObserver {
		private:
			unsigned int _width;
			unsigned int _height;
		public:
			Plazza::Controller::IController *_processManager;
			void modeCanonique(int mode);
			void initView();
			void getInputs();
			void displayData();
			void displayStatus();
			void Update(std::vector<std::string> data);
			Ncurses();
			virtual ~Ncurses() {};
		};
	}
}

#endif
