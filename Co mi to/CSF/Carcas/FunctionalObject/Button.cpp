#include "Button.h"
#include "Carcas.h"
#include "mySprite.h"

csf::Button::Button()
	:Carcas(), ButtonFunctional() {}

csf::Button::Button(BaseObject* Object)
	:Carcas(Object), ButtonFunctional(this) {}

csf::Button::Button(string name, float x, float y)
{
	mySprite* temp = new mySprite(name, x, y);
	*this = Button(temp);
	setAwakeningType(AwakeningTypes::ChangeFrame);
	this->Object = this;
}

void csf::Button::Reload(BaseObject* Object)
{
	Delete();
	*this = Button(Object);
	this->Object = this;
}

void csf::Button::Reload(string name, float x, float y)
{
	Delete();
	*this = Button(name, x, y);
	this->Object = this;
}

void csf::Button::setAwakeningType(AwakeningTypes AwakeningType)
{
	if (this->AwakeningType == AwakeningTypes::ChangeFrame) {
		Objects[0]->setAwakeningType(nonAwakening);
		updateDimensions();
	}

	switch (AwakeningType)
	{
	case csf::BaseObject::ChangeColor:
		Objects[0]->setAwakeningType(AwakeningType);
		break;
	case csf::BaseObject::ChangeFrame:
		Objects[0]->setAwakeningType(AwakeningType);
		updateDimensions();
		break;
	}
	BaseObject::setAwakeningType(AwakeningType);
}