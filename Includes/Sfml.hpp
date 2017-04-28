#ifndef SFML_HPP_
# define SFML_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "AView.hpp"
#include "IObserver.hpp"

namespace Plazza {
    namespace View {
        class Sfml : public AView, public IObserver {
        public:
            void initView();
            void getInputs();
            void displayData();
            void displayStatus();
            void Update(std::vector<std::string> data);
            Sfml(Plazza::Controller::IController *);
            virtual ~Sfml();
            void LoopView();
        private:
            std::string	_commandToPrint;
        };
    }
}

#endif
