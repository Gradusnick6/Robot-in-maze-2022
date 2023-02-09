#include "PlateFunctional.h"
#include "SizeWindow.h"

namespace csf
{
	BaseObject* PlateFunctional::MovingPlate = NULL;

	csf::PlateFunctional::PlateFunctional() :Functional()
	{
		moving = false;
	}

	csf::PlateFunctional::PlateFunctional(BaseObject* Object) :Functional(Object)
	{
		moving = false;
	}

	BaseObject* PlateFunctional::MovePlate(RenderWindow& window)
	{
		static Vector2f differencePosition;
		static Vector2f windowMousePostion;
		if (Object->getVisible() && Object->getEnable())
		{
			// Обнуление 
			if (!Mouse::isButtonPressed(Mouse::Left)) 
			{
				MovingPlate = NULL;
				moving = false; 
				differencePosition = Vector2f(0, 0); 
				return NULL; 
			}
			// Выбор нового перетаскиваемого объекта
			if (Object->operator<(window) && MovingPlate == NULL) 
			{ 
				MovingPlate = Object;  
				moving = true; 
				windowMousePostion = window.mapPixelToCoords(Mouse::getPosition(window));
				differencePosition = Vector2f(Object->getOriginPosition().x - windowMousePostion.x,
											  Object->getOriginPosition().y - windowMousePostion.y);
			}
			// Перетаскивание выбранного объекта
			if (MovingPlate == Object)
			{
				windowMousePostion = window.mapPixelToCoords(Mouse::getPosition(window));
				Object->setPosition(windowMousePostion.x + differencePosition.x,
								    windowMousePostion.y + differencePosition.y);
				moving = true;
				return Object;
			}
		}
		return NULL;
	}

	bool PlateFunctional::getMoving()
	{
		if (!Mouse::isButtonPressed(Mouse::Left))
		{
			MovingPlate = NULL;
			moving = false;
		}
		return moving;
	}

	BaseObject* PlateFunctional::getMovingPlate()
	{
		return MovingPlate;
	}
}
