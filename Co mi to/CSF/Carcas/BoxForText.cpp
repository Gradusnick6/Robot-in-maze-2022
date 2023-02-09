#include "BoxForText.h"

csf::BoxForText::BoxForText()
	: Carcas()
{
	Box = NULL;
	text = NULL;
	centre.x = 0;
	centre.y = 0;
	sizeBox.y = 0;
	sizeBox.y = 0;
}

csf::BoxForText::BoxForText(mySprite* box, myText* text)
{
	centre.x = box->getScaleDimensions().x / 2.f;
	centre.y = box->getScaleDimensions().y / 2.f;
	*this = BoxForText(box, text, centre, box->getScaleDimensions());
}

csf::BoxForText::BoxForText(mySprite* box, myText* text, Vector2f centre, Vector2f sizeBox)
	: Carcas(box)
{
	Box = box;
	setObject(text);
	this->text = text;
	setCentre(centre);
	setSizeBox(sizeBox);
	updatePosition();
}

void csf::BoxForText::Reload(mySprite* background, myText* text, Vector2f centre, Vector2f sizeBox)
{
	Delete();
	*this = BoxForText(background, text, centre, sizeBox);
}

void csf::BoxForText::Reload(mySprite* background, myText* text)
{
	Delete();
	*this = BoxForText(background, text);
}

Vector2f csf::BoxForText::getSizeBox()
{
	return sizeBox;
}

Vector2f csf::BoxForText::getCentre()
{
	return centre;
}

void csf::BoxForText::setSizeBox(Vector2f sizeBox)
{
	this->sizeBox = sizeBox;
}

void csf::BoxForText::setCentre(Vector2f centre)
{
	this->centre = centre;
}

void csf::BoxForText::updatePosition()
{
	//text->AlignTextBox(sizeBox);
	text->setPosition(Box->getPosition().x + centre.x, Box->getPosition().y + centre.y);
}
