#ifndef NCURSES_HPP_
# define NCURSES_HPP_

#include "AView.hpp"
#include "IObserver.hpp"
#include <curses.h>

namespace Plazza {
	namespace View {
		class Ncurses : public AView, public IObserver {
		private:
			//Plazza::Controller::IController *_controller;
			unsigned int _width;
			unsigned int _height;
			void modeCanonique(int mode);
			void initView();
			void getInputs();
			void displayData();
			void displayStatus();
		public:
			Ncurses();
			virtual ~Ncurses() {};
		};
	}
}

#endif
