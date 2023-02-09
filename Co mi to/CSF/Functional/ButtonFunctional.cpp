#include "ButtonFunctional.h"

csf::ButtonFunctional::ButtonFunctional() :Functional(){}

csf::ButtonFunctional::ButtonFunctional(BaseObject* Object) :Functional(Object) {}

bool csf::ButtonFunctional::Pressed(Event& event, RenderWindow& window)
{
	if (Object->getEnable() && Object->getVisible())
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Left)
				if (Object->operator<(window)) {
					event.type = Event::MouseMoved;
					return true;
				}
	return false;
}

bool csf::ButtonFunctional::Released(Event& event, RenderWindow& window)
{
	if (Object->getEnable() && Object->getVisible())
		if (event.type == sf::Event::MouseButtonReleased)
			if (event.mouseButton.button == sf::Mouse::Left)
				if (Object->operator<(window)) {
					event.type = Event::MouseMoved;
					return true;
				}
	return false;
}

bool csf::ButtonFunctional::DoubleClick(Event& event, RenderWindow& window)
{
	return false;
}
