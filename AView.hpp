#ifndef AVIEW_HPP_
# define AVIEW_HPP_

#include "IView.hpp"
//#include "IController.hpp"
#include "ProcessManagerSockets.cpp"

namespace Plazza {
	namespace View {
		class AView : public IView {
		private:
			unsigned int _width;
			unsigned int _height;

    public:
      virtual ~AView() {};
			virtual void getInputs() = 0;
			virtual void setSize(unsigned int width, unsigned int height);
			virtual void setResizable(bool isResizable);
			virtual void setVisible(bool isVisible);
			virtual void initVIew() = 0;
			virtual void displayData() = 0;
			virtual void displayStatus() = 0;
			virtual void setTitle(std::string title);

    protected:
			//Plazza::Controller::IController *_controller;
      AView();
		};
	}
}

#endif
