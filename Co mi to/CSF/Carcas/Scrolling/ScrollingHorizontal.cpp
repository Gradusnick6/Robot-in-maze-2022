#include "ScrollingHorizontal.h"

void csf::ScrollingHorizontal::updateConfiguration()
{
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setOrigin(0, 0);

	Box->setPosition(location);
	upScrollButton->setPosition(location.x - upScrollButton->getScaleDimensions().x, location.y);
	downScrollButton->setPosition(location.x + Box->getScaleDimensions().x, location.y);

	scrollPlate->setPosition(0);
	setOrigin(-upScrollButton->getScaleDimensions().x, 0);

	Vector2f objectLocation;
	for (int i = 0; i < (int)Objects.size(); i++)
	{
		objectLocation = Objects[i]->getPosition();
		Objects[i]->setOrigin(location.x - objectLocation.x,
			location.y - objectLocation.y);
	}
	updateDimensions();
}

csf::ScrollingHorizontal::ScrollingHorizontal()
	: Scrolling() {}

csf::ScrollingHorizontal::ScrollingHorizontal(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton, string nameScrollPlate)
	:Scrolling(master, Box, upScrollButton, downScrollButton)
{
	this->master = master;

	scrollPlate = new ScrollPlateHorizontal(Box, nameScrollPlate);
	scrollPlate->setAwakeningType(AwakeningTypes::nonAwakening);
	setObject(scrollPlate);
	updateConfiguration();
	scrollPlate->setOrigin(0, 0);

	updatePosition();
}

csf::ScrollingHorizontal::ScrollingHorizontal(mySprite* master, string name)
{
	Box = new mySprite(name);
	upScrollButton = new Button(name + "UpButton");
	downScrollButton = new Button(name + "DownButton");

	*this = ScrollingHorizontal(master, Box, upScrollButton, downScrollButton, name + "Plate");
	this->name = name;
}

void csf::ScrollingHorizontal::Reload(mySprite* master, string name)
{
	Delete();
	*this = ScrollingHorizontal(master, name);
}

void csf::ScrollingHorizontal::Reload(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton, string nameScrollPlate)
{
	Delete();
	*this = ScrollingHorizontal(master, Box, upScrollButton, downScrollButton, name);
}

void csf::ScrollingHorizontal::updatePosition()
{
	setPosition(master->getPosition().x, master->getPosition().y + master->getScaleDimensions().y);
}

csf::ScrollingHorizontal::ScrollPlateHorizontal::ScrollPlateHorizontal()
	: ScrollPlate() {}

csf::ScrollingHorizontal::ScrollPlateHorizontal::ScrollPlateHorizontal(BaseObject* master, string name)
	:ScrollPlate(master, name) 
{
	setPosition(0);
}

void csf::ScrollingHorizontal::ScrollPlateHorizontal::setPosition(float x, float y)
{
	y = master->getPosition().y + master->getScaleDimensions().y * 0.5f - scaleDimensions.y * 0.5f;
	if (x < master->getPosition().x) x = master->getPosition().x;
	else if (x > master->getPosition().x + master->getScaleDimensions().x - scaleDimensions.x)
		x = master->getPosition().x + master->getScaleDimensions().x - scaleDimensions.x;
	Carcas::setPosition(x, y);
}

void csf::ScrollingHorizontal::ScrollPlateHorizontal::setPosition(float percent)
{
	if (percent < 0) percent = 0;
	else if (percent > 1) percent = 1;
	setPosition((master->getScaleDimensions().x - scaleDimensions.x) * percent, 0);
}

float csf::ScrollingHorizontal::ScrollPlateHorizontal::getScrolling()
{
	float temp;
	temp = location.x - master->getPosition().x;
	if (temp < 0) return 0;
	temp /= (master->getScaleDimensions().x - scaleDimensions.x);
	return temp;
}
