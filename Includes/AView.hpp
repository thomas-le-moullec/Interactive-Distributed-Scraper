#ifndef AVIEW_HPP_
# define AVIEW_HPP_

#include "IView.hpp"
#include "IController.hpp"

namespace Plazza {
	namespace View {
		class AView : public IView {
    public:
      virtual ~AView() {};
			virtual void getInputs() = 0;
			virtual void setSize(unsigned int width, unsigned int height);
			virtual void setResizable(bool isResizable);
			virtual void setVisible(bool isVisible);
			virtual void initView() = 0;
			virtual void displayData() = 0;
			virtual void displayStatus() = 0;
			virtual void setTitle(std::string title);
			virtual void LoopView() = 0;

    protected:
      AView(Plazza::Controller::IController *);
			unsigned int 										_width;
			unsigned int 										_height;
			Plazza::Controller::IController *_processManager;
		};
	}
}

#endif
