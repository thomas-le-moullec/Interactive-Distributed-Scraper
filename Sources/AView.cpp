#include "AView.hpp"

void Plazza::View::AView::setSize(unsigned int width, unsigned int height) {
  (void)width;
  (void)height;
}

Plazza::View::AView::AView(Plazza::Controller::IController *controller) : _processManager(controller) {

}

void 		Plazza::View::AView::setResizable(bool isResizable)
{
  (void)isResizable;
}

void 		Plazza::View::AView::setVisible(bool isVisible)
{
  (void)isVisible;
}

void 		Plazza::View::AView::setTitle(std::string title)
{
  (void)title;
}
