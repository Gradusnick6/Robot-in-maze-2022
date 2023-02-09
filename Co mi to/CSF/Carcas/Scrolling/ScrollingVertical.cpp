#include "ScrollingVertical.h"

void csf::ScrollingVertical::updateConfiguration()
{
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setOrigin(0, 0);

	Box->setPosition(location);
	upScrollButton->setPosition(location.x, location.y - upScrollButton->getScaleDimensions().y);
	downScrollButton->setPosition(location.x, location.y + Box->getScaleDimensions().y);

	scrollPlate->setPosition(0);
	setOrigin(0, -upScrollButton->getScaleDimensions().y);

	Vector2f objectLocation;
	for (int i = 0; i < (int)Objects.size(); i++)
	{
		objectLocation = Objects[i]->getPosition();
		Objects[i]->setOrigin(location.x - objectLocation.x,
			location.y - objectLocation.y);
	}
	updateDimensions();
}

csf::ScrollingVertical::ScrollingVertical()
	:Scrolling() {}

csf::ScrollingVertical::ScrollingVertical(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton, string nameScrollPlate)
	:Scrolling(master, Box, upScrollButton, downScrollButton)
{
	this->master = master;
	
	scrollPlate = new ScrollPlateVertical(Box, nameScrollPlate);
	scrollPlate->setAwakeningType(AwakeningTypes::nonAwakening);
	setObject(scrollPlate);
	updateConfiguration();
	scrollPlate->setOrigin(0, 0);
	
	updatePosition();
}

csf::ScrollingVertical::ScrollingVertical(mySprite* master, string name)
{
	Box = new mySprite(name);
	upScrollButton = new Button(name + "UpButton");
	downScrollButton = new Button(name + "DownButton");
	
	*this = ScrollingVertical(master, Box, upScrollButton, downScrollButton, name + "Plate");
	this->name = name;
}

void csf::ScrollingVertical::Reload(mySprite* master, string name)
{
	Delete();
	*this = ScrollingVertical(master, name);
}

void csf::ScrollingVertical::Reload(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton, string nameScrollPlate)
{
	Delete();
	*this = ScrollingVertical(master, Box, upScrollButton, downScrollButton, name);
}

void csf::ScrollingVertical::updatePosition()
{
	setPosition(master->getPosition().x + master->getScaleDimensions().x, 
				master->getPosition().y);
}

csf::ScrollingVertical::ScrollPlateVertical::ScrollPlateVertical()
	:ScrollPlate() {}

csf::ScrollingVertical::ScrollPlateVertical::ScrollPlateVertical(BaseObject* master, string name)
	:ScrollPlate(master, name) 
{
	setPosition(0);
}

void csf::ScrollingVertical::ScrollPlateVertical::setPosition(float x, float y)
{
	//auto temp = master->getRotate();
	//master->setRotate(0);
	x = master->getPosition().x + master->getScaleDimensions().x * (float)0.5 - scaleDimensions.x * (float)0.5;
	if (y < master->getPosition().y) y = master->getPosition().y;
	else if (y > master->getPosition().y + master->getScaleDimensions().y - scaleDimensions.y) 
		y = master->getPosition().y + master->getScaleDimensions().y - scaleDimensions.y;
	Carcas::setPosition(x, y);
	// master->setRotate(temp);
}

void csf::ScrollingVertical::ScrollPlateVertical::setPosition(float percent)
{
	if (percent < 0) percent = 0;
	else if (percent > 1) percent = 1;
	setPosition(0, (master->getScaleDimensions().y - scaleDimensions.y) * percent);
}

float csf::ScrollingVertical::ScrollPlateVertical::getScrolling()
{
	float temp;
	temp = location.y - master->getPosition().y;
	if (temp < 0) return 0;
	temp /= (master->getScaleDimensions().y - scaleDimensions.y);
	return temp;
}
