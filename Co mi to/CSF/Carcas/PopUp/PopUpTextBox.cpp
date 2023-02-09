#include "PopUpTextBox.h"

csf::PopUpTextBox::PopUpTextBox()
	:PopUpWindow() {}

csf::PopUpTextBox::PopUpTextBox(mySprite* background, myText* text, Button* close, Button* apply)
	:PopUpWindow(background)
{
	this->text = text;
	Close = close;
	Apply = apply;
	setObject(text);
	setObject(Close);
	setObject(Apply);
}

csf::PopUpTextBox::PopUpTextBox(string name, int maxLenght)
{
	Background = new mySprite(name);
	text = new myText(0, 0, L"", 14);
	Close = new Button(name + "Close");
	Apply = new Button(name + "Apply");

	Close->setAwakeningType(AwakeningTypes::ChangeFrame);
	Apply->setAwakeningType(AwakeningTypes::ChangeFrame);

	location.x = location.y = 0;
	Background->setPosition(location.x, location.y);
	Close->setPosition(location.x + Background->getScaleDimensions().x - Close->getScaleDimensions().x - (float)0.1 * Close->getScaleDimensions().x,
					   location.y + (float)0.15 * Close->getScaleDimensions().y);
	Apply->setPosition(location.x + Background->getScaleDimensions().x / 2 - Apply->getScaleDimensions().x / 2,
					   location.y + Background->getScaleDimensions().y / 2 + Apply->getScaleDimensions().y / 2);
	text->setPosition(location.x + Background->getScaleDimensions().x / 2,
					  location.y + Background->getScaleDimensions().y / 2);

	*this = PopUpTextBox(Background, text, Close, Apply);
}

void csf::PopUpTextBox::Reload(string name, int maxLenght)
{
	Delete();
	*this = PopUpTextBox(name, maxLenght);
}

void csf::PopUpTextBox::Reload(mySprite* background, myText* text, Button* close, Button* apply)
{
	Delete();
	*this = PopUpTextBox(background, text, close, apply);
}

int csf::PopUpTextBox::Update(Event& event, RenderWindow& window)
{
	if (visible)
	{
		text->Input(event);
		if (Close->Pressed(event, window)) { return TEXTBOXCLOSE; }
		if (Apply->Pressed(event, window) || Keyboard::isKeyPressed(Keyboard::Return)) return TEXTBOXAPPLY;
	}
	return TEXTBOXCONTINUE;
}
