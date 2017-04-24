#ifndef IVIEW_HPP_
# define IVIEW_HPP_

#include <iostream>

namespace Plazza {
	namespace View {
		class IView {
    public:
      virtual ~IView() {}
			virtual void getInputs() = 0;
			virtual void setSize(unsigned int width, unsigned int height) = 0;
			virtual void setResizable(bool isResizable) = 0;
			virtual void setVisible(bool isVisible) = 0;
			virtual void initVIew() = 0;
			virtual void displayData() = 0;
			virtual void displayStatus() = 0;
		};
	}
}

#endif
