#ifndef NCURSES_HPP_
# define NCURSES_HPP_

#include "AView.hpp"
#include "IObserver.hpp"
#include "ProcessManagerSockets.hpp"
//#include <ncurses.h>
#include <curses.h>


#include <iostream>
#include <bitset>
#include <fstream>
#include <iostream>
#include <string>
#include <ios>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <cstring>
#include <sys/ioctl.h>
#include <dirent.h>
#include <dlfcn.h>

namespace Plazza {
	namespace View {
		class Ncurses : public AView, public IObserver {
		public:
			//Plazza::Controller::IController *_processManager;
			int modeCanonique(int mode);
			void initView();
			void getInputs();
			void displayData();
			void displayStatus();
			void Update(std::vector<std::string> data);
			Ncurses(Plazza::Controller::IController *);
			virtual ~Ncurses();
			void LoopView();
		private:
			std::string	_commandToPrint;
		};
	}
}

#endif
