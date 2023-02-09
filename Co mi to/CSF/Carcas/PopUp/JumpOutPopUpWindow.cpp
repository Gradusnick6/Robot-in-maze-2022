#include "JumpOutPopUpWindow.h"
#include "SizeWindow.h"

csf::JumpOutPopUpWindow::JumpOutPopUpWindow()
	:PopUpWindow() 
{
	orientation = Right; 
	numberClockCycles = 100;
}

csf::JumpOutPopUpWindow::JumpOutPopUpWindow(mySprite* background, Button* close, Orientation orientation, int numberClockCycles)
	:PopUpWindow(background)
{
	this->orientation = orientation;
	this->numberClockCycles = numberClockCycles;
	Close = close;
	setObject(Close);
}

csf::JumpOutPopUpWindow::JumpOutPopUpWindow(string name, Orientation orientation, int numberClockCycles)
{
	Background = new mySprite(name);
	Close = new Button(name + "Close");
	Close->setAwakeningType(AwakeningTypes::ChangeFrame);
	location.x = location.y = 0;
	Background->setPosition(location.x, location.y);
	Close->setPosition(location.x + Close->getScaleDimensions().x, location.y + Close->getScaleDimensions().y);

	*this = JumpOutPopUpWindow(Background, Close, orientation, numberClockCycles);
}

void csf::JumpOutPopUpWindow::Reload(string name, Orientation orientation, int numberClockCycles)
{
	Delete();
	*this = JumpOutPopUpWindow(name, orientation, numberClockCycles);
}

void csf::JumpOutPopUpWindow::Reload(mySprite* background, Button* close, Orientation orientation, int numberClockCycles)
{
	Delete();
	*this = JumpOutPopUpWindow(background, close, orientation, numberClockCycles);
}

void csf::JumpOutPopUpWindow::setPosition(float x, float y, RenderWindow& window)
{
	switch (orientation)
	{
	case JumpOutPopUpWindow::Up: y = 0; break;
	case JumpOutPopUpWindow::Down: y = (float)SizeWindow::getOriginalDimentions().y; break;
	case JumpOutPopUpWindow::Left: x = 0; break;
	case JumpOutPopUpWindow::Right: x = (float)SizeWindow::getOriginalDimentions().x; break;
	}
	Carcas::setPosition(x, y);
}

int csf::JumpOutPopUpWindow::Update(Event& event, RenderWindow& window)
{
	if (visible)
	{
		switch (orientation)
		{
		case JumpOutPopUpWindow::Up:
			if (location.y > 0)
				Carcas::setPosition(location.x, 
									location.y + ((float)scaleDimensions.y / numberClockCycles));
			else 
				Carcas::setPosition(location.x, 0);
			break;

		case JumpOutPopUpWindow::Down:
			if (location.y > window.getSize().y / SizeWindow::getScaleAdapting().y - scaleDimensions.y)
				Carcas::setPosition(location.x, 
									location.y - ((float)scaleDimensions.y / numberClockCycles));
			else 
				Carcas::setPosition(location.x, 
									(float)window.getSize().y / SizeWindow::getScaleAdapting().y - scaleDimensions.y);
			break;

		case JumpOutPopUpWindow::Left:
			if (location.x > 0)
				Carcas::setPosition(location.x + ((float)scaleDimensions.x / numberClockCycles), 
									location.y);
			else 
				Carcas::setPosition(0, location.y);
			break;

		case JumpOutPopUpWindow::Right:
			if (location.x > window.getSize().x / SizeWindow::getScaleAdapting().x - scaleDimensions.x)
				Carcas::setPosition(location.x - ((float)scaleDimensions.x / numberClockCycles), 
									location.y);
			else 
				Carcas::setPosition((float)window.getSize().x / SizeWindow::getScaleAdapting().x - scaleDimensions.x, 
									location.y);
			break;
		}
		if (Close->Pressed(event, window)) { visible = false; }
	}
	else setPosition(location.x, location.y, window);
	return JUMPPOPUPCONTINUE;
}

void csf::JumpOutPopUpWindow::TurnOff()
{
	setVisible(false);
}

void csf::JumpOutPopUpWindow::TurnOn()
{
	setVisible(true);
}
