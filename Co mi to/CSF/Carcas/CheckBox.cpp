#include "CheckBox.h"

namespace csf
{

	CheckBox::CheckBox() 
		:Carcas()
	{
		Box = NULL;
		buttonFunctional = NULL;
		Check = NULL;
		isCheck = false;
	}

	CheckBox::CheckBox(BaseObject* box, ButtonFunctional* buttonFunctional, BaseObject* Check)
		:Carcas(box)
	{
		Box = box;
		this->Check = Check;
		this->buttonFunctional = buttonFunctional;
		setObject(Check);
		isCheck = Check->getVisible();
	}

	CheckBox::CheckBox(Button* button, BaseObject* Check)
		:CheckBox(button, button, Check){}

	CheckBox::CheckBox(string name, bool isCheck, float x, float y) 
	{
		Box = new Button(name);
		Box->setAwakeningType(AwakeningTypes::ChangeFrame);

		Vector2f temp = Box->getPosition();
		Check = new mySprite(name + "Check");
		temp.x += Box->getScaleDimensions().x / 2 - Check->getScaleDimensions().x / 2;
		temp.y += Box->getScaleDimensions().y / 2 - Check->getScaleDimensions().y / 2;
		Check->setPosition(temp);
		Check->setVisible(false);
		*this = CheckBox((Button*)Box, Check);
	}


	void CheckBox::Reload(BaseObject* box, ButtonFunctional* buttonFunctional, BaseObject* Check)
	{
		Delete();
		*this = CheckBox(box, buttonFunctional, Check);
	}
	void CheckBox::Reload(Button* button, BaseObject* Check)
	{
		Delete();
		*this = CheckBox(button, button, Check);
	}
	void CheckBox::Reload(string name, bool isCheck, float x, float y) 
	{
		Delete();
		*this = CheckBox(name, isCheck, x, y);
	}

	bool CheckBox::Update(Event& event, RenderWindow& window)
	{
		if (getVisible() && getEnable())
			if (buttonFunctional->Pressed(event, window)) setCheck(!isCheck);
		return isCheck;
	}

	bool CheckBox::getCheck()
	{
		return isCheck;
	}

	void CheckBox::setCheck(bool isCheck)
	{
		this->isCheck = isCheck; 
		Check->setVisible(isCheck);
	}
}