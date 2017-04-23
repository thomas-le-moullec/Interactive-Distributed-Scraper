#ifndef AVIEW_HPP_
# define AVIEW_HPP_

#include "IView.hpp"
#include "IController.hpp"

namespace Plazza {
	namespace View {
		class AView : public IView {
		private:
			Plazza::Controller::IController *_controller;
			unsigned int _width;
			unsigned int _height;
			virtual void setSize(unsigned int width, unsigned int height);
			virtual void setResizable(bool isResizable) = 0;
			virtual void setVisible(bool isVisible) = 0;
			virtual void initVIew() = 0;
			virtual void getInputs() = 0;
			virtual void displayData() = 0;
			virtual void displayStatus() = 0;
			virtual void setTitle(std::string title) = 0;

        public:
            virtual ~AView() {};
        protected:
            AView();
		};
	}
}

#endif
