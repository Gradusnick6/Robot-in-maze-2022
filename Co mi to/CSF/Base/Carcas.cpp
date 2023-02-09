#include "Carcas.h"

void csf::Carcas::updateRealDimensions()
{
	Vector2f UpperLeft, LowerRight;
	if ((int)Objects.size() < 1) return;

	UpperLeft = Objects[0]->getRealPosition();
	LowerRight.x = Objects[0]->getRealPosition().x + Objects[0]->getRealDimensions().x;
	LowerRight.y = Objects[0]->getRealPosition().y + Objects[0]->getRealDimensions().y;

	for (int i = 1; i < (int)Objects.size(); i++)
	{
		Vector2f tempLocation = Objects[i]->getRealPosition();
		Vector2f tempDimensions = Objects[i]->getRealDimensions();

		if (UpperLeft.x > tempLocation.x) UpperLeft.x = tempLocation.x;
		if (LowerRight.x < tempLocation.x + tempDimensions.x) LowerRight.x = tempLocation.x + tempDimensions.x;
		if (UpperLeft.y > tempLocation.y) UpperLeft.y = tempLocation.y;
		if (LowerRight.y < tempLocation.y + tempDimensions.y) LowerRight.y = tempLocation.y + tempDimensions.y;
	}
	realLocation = UpperLeft;
	realDimensions = Vector2f((float)(LowerRight.x - UpperLeft.x), (float)(LowerRight.y - UpperLeft.y));
}

void csf::Carcas::updateDimensions()
{
	Vector2f UpperLeft, LowerRight;
	Vector2f maskUpperLeft;
	if ((int)Objects.size() < 1) return;

	UpperLeft = Objects[0]->getPosition();
	LowerRight.x = Objects[0]->getPosition().x + Objects[0]->getScaleDimensions().x;
	LowerRight.y = Objects[0]->getPosition().y + Objects[0]->getScaleDimensions().y;
	maskUpperLeft = Objects[0]->getMaskPosition();

	for (int i = 1; i < (int)Objects.size(); i++)
	{
		Vector2f tempLocation = Objects[i]->getPosition();
		Vector2f tempDimensions = Objects[i]->getScaleDimensions();
		Vector2f tempMaskLocation = Objects[i]->getMaskPosition();

		if (UpperLeft.x > tempLocation.x) UpperLeft.x = tempLocation.x;
		if (LowerRight.x < tempLocation.x + tempDimensions.x) LowerRight.x = tempLocation.x + tempDimensions.x;
		if (UpperLeft.y > tempLocation.y) UpperLeft.y = tempLocation.y;
		if (LowerRight.y < tempLocation.y + tempDimensions.y) LowerRight.y = tempLocation.y + tempDimensions.y;

		if (maskUpperLeft.x > tempMaskLocation.x) maskUpperLeft.x = tempMaskLocation.x;
		if (maskUpperLeft.y > tempMaskLocation.y) maskUpperLeft.y = tempMaskLocation.y;
	}
	if (location != UpperLeft)
	{
		origin.x = (originLocation.x - UpperLeft.x) / scale.x;
		origin.y = (originLocation.y - UpperLeft.y) / scale.y;
		for (int i = 0; i < (int)Objects.size(); i++)
		{
			Vector2f objectLocation = Objects[i]->getPosition();
			Objects[i]->setOrigin(UpperLeft.x - objectLocation.x,
				UpperLeft.y - objectLocation.y);
		}
	}
	location = UpperLeft;
	maskLocation = maskUpperLeft;
	scaleDimensions = Vector2f((float)(LowerRight.x - UpperLeft.x), (float)(LowerRight.y - UpperLeft.y));
	originalDimensions.x = scaleDimensions.x / scale.x;
	originalDimensions.y = scaleDimensions.y / scale.y;
	updateRealDimensions();
}

void csf::Carcas::setPositionObject(BaseObject* Object, float x, float y)
{
	Vector2f temp = Objects[0]->getPosition();
	temp.x += x;
	temp.y += y;
	Object->setPosition(temp);
	updateDimensions();
}

csf::Carcas::Carcas()
	: BaseObject() {}

csf::Carcas::Carcas(BaseObject* object)
	: BaseObject()
{
	name = object->getName();
	color = object->getColor();
	origin = object->getOrigin();
	rotate = object->getRotate();
	scale = object->getScale();
	visible = object->getVisible();
	enable = object->getEnable();
	maskRect = object->getMaskRect();

	location = Rotate(object->getPosition(), object->getOriginPosition(), -object->getRotate());
	originalDimensions = object->getOriginalDimensions();
	

	setOrigin(origin.x, origin.y);
	setPosition(originLocation);
	setScale(scale.x, scale.y);
	setRotate(rotate);

	setObject(object);
}

void csf::Carcas::Reload(BaseObject* object)
{
	Delete();
	*this = Carcas(object);
}

void csf::Carcas::operator>(RenderWindow& window)
{
	if (visible)
		for (int i = 0; i < (int)Objects.size(); i++)
			Objects[i]->operator>(window);
}

void csf::Carcas::operator>>(RenderWindow& window)
{
	if (visible)
		for (int i = 0; i < (int)Objects.size(); i++)
			Objects[i]->operator>>(window);
}

void csf::Carcas::setPosition(Vector2f _location)
{
	BaseObject::setPosition(_location);
}

void csf::Carcas::setPosition(float x, float y)
{
	originLocation = Vector2f(x, y);
	location.x = x - origin.x * scale.x;
	location.y = y - origin.y * scale.y;
	location = Rotate(location, originLocation, rotate);
	for (int i = 0; i < (int)Objects.size(); i++)
	{
		Objects[i]->setPosition(location);
	}
	updateDimensions();
}

void csf::Carcas::setColorAwakening(int red, int green, int blue, int alpha)
{
	colorAwakening = getUpdateColor(colorAwakening, red, green, blue, alpha);
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setColorAwakening(red, green, blue, alpha);
}

void csf::Carcas::setScaleAwakening(Vector2f scale)
{
	scaleAwakening = scale;
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setScaleAwakening(scaleAwakening);
}

void csf::Carcas::setColor(int red, int green, int blue, int alpha)
{
	color = getUpdateColor(color, red, green, blue, alpha);
	for (int i = 0; i < (int)Objects.size(); i++) 
		Objects[i]->setColor(red, green, blue, alpha);
}

void csf::Carcas::setOrigin(float x, float y)
{
	origin.x = x;
	origin.y = y;
	originLocation = Vector2f(location.x + origin.x * scale.x, location.y + origin.y * scale.y);
}

void csf::Carcas::setColor(Color color)
{
	setColor(color.r, color.g, color.b, color.a);
}

void csf::Carcas::setVisible(bool visible)
{
	this->visible = visible;
	for (int i = 0; i < (int)Objects.size(); i++) 
		Objects[i]->setVisible(visible);
}

void csf::Carcas::setEnable(bool enable)
{
	this->enable = enable;
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setEnable(enable);
}

void csf::Carcas::setScale(float x, float y)
{
	scale.x = x;
	scale.y = y;
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setScale(scale.x, scale.y);
	setPosition(originLocation);
	updateDimensions();
}

void csf::Carcas::setRotate(float angle)
{
	rotate = angle;
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->setRotate(rotate);
	setPosition(originLocation);
	updateDimensions();
}

void csf::Carcas::setTextureRect(FloatRect textureRect)
{
	for (int i = 0; i < (int)Objects.size(); i++)
	{
		Objects[i]->setTextureRect(Objects[i]->getTextureRect());
	}
	updateDimensions();
}

void csf::Carcas::updateConfiguration() {}

void csf::Carcas::setTextureRect(FloatRect textureRect, int index)
{
	Objects[index]->setTextureRect(textureRect);
	updateDimensions();
}

void csf::Carcas::setMaskRect(FloatRect maskRect)
{
	this->maskRect = maskRect;
	textureRect = maskRect;
	for (int i = 0; i < (int)Objects.size(); i++)
	{
		Objects[i]->setMaskRect(maskRect);
	}
	updateDimensions();
}

void csf::Carcas::setObject(BaseObject* object)
{
	Objects.push_back(object);
	Vector2f objectLocation = object->getPosition();
	object->setOrigin(location.x - objectLocation.x,
					  location.y - objectLocation.y);
	updateDimensions();
}

void csf::Carcas::setPositionObject(int index, float x, float y)
{
	setPositionObject(Objects[index], x, y);
}

void csf::Carcas::setPositionObject(string name, float x, float y)
{
	int index = -1;
	for (int i = 0; i < (int)Objects.size(); i++)
		if (Objects[i]->getName() == name) { index = i; break; }
	
	if (index == -1) return;
	setPositionObject(Objects[index], x, y);
}

void csf::Carcas::Delete()
{
	for (int i = 0; i < (int)Objects.size(); i++)
		Objects[i]->Delete();
	Objects.clear();
}