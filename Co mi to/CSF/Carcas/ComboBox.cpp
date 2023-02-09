#include "ComboBox.h"

csf::ComboBox::ComboBox()
	:Carcas() 
{
	movePlate = -1; 
	visible = false; 
	enable = false; 
	lineSpacing = 1;
	size = 1;
	startPositionPlate.x = startPositionPlate.y = 0;
}

csf::ComboBox::ComboBox(mySprite* box)
	:Carcas(box)
{
	Box = box;
	movePlate = -1;
	lineSpacing = 1;
	startPositionPlate.x = startPositionPlate.y = 0;
}

csf::ComboBox::ComboBox(mySprite* box, vector<Plate*> plateBank)
	:ComboBox(box)
{
	for (int i = 0; i < (int)plateBank.size(); i++)
	{
		this->plateBank.push_back(plateBank[i]);
		setObject(plateBank[i]);
	}
	size = (int)plateBank[0]->getScaleDimensions().y;
	updatePosition();
}

csf::ComboBox::ComboBox(string name, int numPlate)
{
	mySprite* box = new mySprite(name);
	vector<Plate*> plateBank;
	for (int i = 0; i < numPlate; i++)
	{
		Plate* temp = new Plate(name + "_" + to_string(i + 1), true);
		temp->setAwakeningType(AwakeningTypes::ChangeFrame);
		plateBank.push_back(temp);
	}
	*this = ComboBox(box, plateBank);
}

void csf::ComboBox::Reload(mySprite* box)
{
	Delete();
	*this = ComboBox(box);
}

void csf::ComboBox::Reload(mySprite* box, vector<Plate*> plateBank)
{
	Delete();
	*this = ComboBox(box, plateBank);
}

void csf::ComboBox::Reload(string name, int numPlate)
{
	Delete();
	*this = ComboBox(name, numPlate);
}

csf::Plate* csf::ComboBox::operator[](int i)
{
	if (i < 0 || i >(int)plateBank.size())
		return plateBank[i];
	else return NULL;
}

void csf::ComboBox::operator>(RenderWindow& window)
{
	Carcas::operator>(window);
	if (Plate::getMovingPlate() != NULL)
		Plate::getMovingPlate()->Draw(window);
}

void csf::ComboBox::operator>>(RenderWindow& window)
{
	Carcas::operator>>(window);
	if (Plate::getMovingPlate() != NULL)
		Plate::getMovingPlate()->DrawAwakening(window);
}

void csf::ComboBox::updatePosition()
{
	auto temp = rotate;
	setRotate(0);
	float y = Box->getPosition().y + startPositionPlate.y;
	for (int i = 0; i < (int)plateBank.size(); i++)
	{
		Vector2f temp = Vector2f(location.x - (Box->getPosition().x + Box->getScaleDimensions().x / 2 - plateBank[i]->getScaleDimensions().x / 2),
			location.y - y);
		plateBank[i]->setOrigin(temp.x, temp.y);
		plateBank[i]->setPosition(location);
		y += lineSpacing * size;
	}
	setRotate(temp);
	updateDimensions();
}

csf::Plate* csf::ComboBox::MovePlates(RenderWindow& window)
{
	if (!visible) return NULL;

	Plate* temp = NULL;
	if (movePlate == -1)
	{
		for (int i = 0; i < (int)plateBank.size(); i++)
			if (plateBank[i]->MovePlate(window)) { movePlate = i; return temp; }
		updatePosition(); return temp;
	}
	else
	{
		if (plateBank[movePlate]->MovePlate(window)) { return temp; }
		else { temp = plateBank[movePlate]; movePlate = -1; updatePosition(); return temp; }
	}
}

void csf::ComboBox::setLineSpacing(float lineSpacing)
{
	this->lineSpacing = lineSpacing;
	updatePosition();
}

float csf::ComboBox::getLineSpacing()
{
	return lineSpacing;
}

void csf::ComboBox::setStartPositionPlate(Vector2f startPositionPlate)
{
	if (startPositionPlate.x == -1 && startPositionPlate.y == -1)
	{
		float dy = plateBank.size() * lineSpacing * plateBank[0]->getScaleDimensions().y;
		this->startPositionPlate.y = Box->getScaleDimensions().y / 2 - dy / 2;
		this->startPositionPlate.x = -1;
	}
	else this->startPositionPlate = startPositionPlate;
	updatePosition();
}

Vector2f csf::ComboBox::getStartPositionPlate()
{
	return startPositionPlate;
}
