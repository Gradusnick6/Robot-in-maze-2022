#include "Plate.h"
#include "Carcas.h"
#include "mySprite.h"
#include "PlateFunctional.h"

csf::Plate::Plate()
	:Carcas(), PlateFunctional() {}

csf::Plate::Plate(BaseObject* Object)
	:Carcas(Object), PlateFunctional(this) {}

csf::Plate::Plate(string name, float x, float y)
{
	mySprite* temp = new mySprite(name, x, y);
	*this = Plate(temp);
	setAwakeningType(AwakeningTypes::ChangeFrame);
	Object = this;
}

void csf::Plate::Reload(BaseObject* Object)
{
	Delete();
	*this = Plate(Object);
	this->Object = this;
}

void csf::Plate::Reload(string name, float x, float y)
{
	Delete();
	*this = Plate(name, x, y);
	Object = this;
}

void csf::Plate::setAwakeningType(AwakeningTypes AwakeningType)
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
	case csf::BaseObject::ChangeScale:
		Objects[0]->setAwakeningType(AwakeningType);
		break;
	}

	BaseObject::setAwakeningType(AwakeningType);
}