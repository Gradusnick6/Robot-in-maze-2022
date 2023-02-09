#include "Scrolling.h"
#include "SizeWindow.h"

csf::Scrolling::Scrolling()
	: Carcas()
{
	master = NULL;
	scrollPlate = NULL;
	Box = NULL;
	upScrollButton = NULL;
	downScrollButton = NULL;
}

csf::Scrolling::Scrolling(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton)
	:Carcas(Box)
{
	this->master = master;

	this->Box = Box;
	this->upScrollButton = upScrollButton;
	this->downScrollButton = downScrollButton;

	setObject(upScrollButton);
	setObject(downScrollButton);
}

int csf::Scrolling::Update(Event& event, RenderWindow& window)
{
	if (scrollPlate->MovePlate(window)) {
		master->setScrolling(scrollPlate->getScrolling());
		return 0;
	}
	else if (event.type == sf::Event::MouseWheelScrolled && (operator<(window) || master->operator<(window))) {
		scrollPlate->WheelScrolled((float)(event.mouseWheelScroll.delta * 0.05));
		event.type = Event::MouseMoved;
		master->setScrolling(scrollPlate->getScrolling());
		return 0;
	}
	else if (upScrollButton->Pressed(event, window)) {
		scrollPlate->WheelScrolled((float)(0.05));
		master->setScrolling(scrollPlate->getScrolling());
		return 0;
	}
	else if (downScrollButton->Pressed(event, window)) {
		scrollPlate->WheelScrolled((float)(-0.05));
		master->setScrolling(scrollPlate->getScrolling());
		return 0;
	}
	else if (operator<(window)) {
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				Vector2f temp(Mouse::getPosition(window));
				temp.x *= SizeWindow::getScaleAdapting().x;
				temp.y *= SizeWindow::getScaleAdapting().y;
				scrollPlate->setPosition(temp.x, temp.y);
				event.type = Event::MouseMoved;
				master->setScrolling(scrollPlate->getScrolling());
				return 0;
			}
	}
	return -1;
}

float csf::Scrolling::getScrolling()
{
	return scrollPlate->getScrolling();
}

csf::Scrolling::ScrollPlate::ScrollPlate()
	:Plate() 
{
	master = NULL;
}

csf::Scrolling::ScrollPlate::ScrollPlate(BaseObject* master, string name)
{
	Reload(master, name);
}

void csf::Scrolling::ScrollPlate::Reload(BaseObject* master, string name)
{
	*this = *(ScrollPlate*)*(Plate(name, true));
	this->master = master;
	this->Object = this;
}

void csf::Scrolling::ScrollPlate::WheelScrolled(float percent)
{
	percent *= -1;
	if (percent > 1) percent = 1;
	else if (percent < -1) percent = -1;
	setPosition(location.x + master->getScaleDimensions().x * percent, 
				location.y + master->getScaleDimensions().y * percent);
}
