#include "PopUpWindow.h"
#include "SizeWindow.h"

csf::PopUpWindow::PopUpWindow()
	:Carcas() 
{
	Background = NULL;
	visible = false;
}

csf::PopUpWindow::PopUpWindow(mySprite* background)
	:Carcas(background)
{
	Background = background;
	visible = false;
}

csf::PopUpWindow::PopUpWindow(string name)
{
	Background = new mySprite(name);

	*this = PopUpWindow(Background);
}

void csf::PopUpWindow::Reload(mySprite* background)
{
	Delete();
	*this = PopUpWindow(Background);
}

void csf::PopUpWindow::Reload(string name)
{
	Delete();
	*this = PopUpWindow(name);
}

void csf::PopUpWindow::TurnOff()
{
	setVisible(false); 
	sleep(milliseconds(100));
}

void csf::PopUpWindow::TurnOn()
{
	setVisible(true);
	sleep(milliseconds(100));
}

int csf::PopUpWindow::Update(Event& event, RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			Mouse::setPosition(Mouse::getPosition(window), window);
			return true;
		}
	}
	else if (event.type == Event::TextEntered) return true;
	return false;
}

void csf::PopUpWindow::setPosition(RenderWindow& window)
{
	Vector2f temp;
	temp.x = (SizeWindow::getOriginalDimentions().x / 2.0f - realDimensions.x / 2.0f);
	temp.y = (SizeWindow::getOriginalDimentions().y / 2.0f - realDimensions.y / 2.0f);
	Carcas::setPosition(temp);
}
