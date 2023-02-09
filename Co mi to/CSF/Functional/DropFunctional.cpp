#include "DropFunctional.h"
#include "SizeWindow.h"

void csf::DropFunctional::setPosition(Vector2f mousePosition, RenderWindow& window)
{
	Vector2f dimensions = Object->getRealDimensions();
	Vector2f location = Object->getRealPosition();

	if (mousePosition.x + (float)dimensions.x >= SizeWindow::getOriginalDimentions().x)
		location.x = SizeWindow::getOriginalDimentions().x - (float)dimensions.x;
	else location.x = mousePosition.x;

	if (mousePosition.y + (float)dimensions.y >= SizeWindow::getOriginalDimentions().y)
		location.y = SizeWindow::getOriginalDimentions().y - (float)dimensions.y;
	else location.y = mousePosition.y;

	Object->setPosition(location.x,
						location.y);
}

csf::DropFunctional::DropFunctional()
	:Functional()
{ 
	this->master = NULL; 
}

csf::DropFunctional::DropFunctional(BaseObject* master, BaseObject* Object)
	:Functional(Object)
{
	this->master = master;
}

void csf::DropFunctional::Update(Event& event, RenderWindow& window)
{
	if (Object->getEnable() && master->operator<(window))
	{
		Vector2f windowMousePostion = window.mapPixelToCoords(Mouse::getPosition(window));
		setPosition(window.mapPixelToCoords(Mouse::getPosition(window)), window);
		Object->setVisible(true);
	} 
	else Object->setVisible(false);
}

void csf::DropFunctional::setMaster(BaseObject* master)
{
	this->master = master;
}
