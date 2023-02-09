#include "DisappearingFunctional.h"

csf::DisappearingFunctional::DisappearingFunctional()
	: Functional()
{
	startLocation = Vector2f(0, 0);
	Object = NULL;
	orientation = NotMove;
	flightSpeed = 0;
	vanishingRate = 0;
	alpha = 255;
}

csf::DisappearingFunctional::DisappearingFunctional(BaseObject* object, Orientation orientation, float flightSpeed, float vanishingRate)
	: Functional(object)
{
	Object = object;
	this->orientation = orientation;
	this->flightSpeed = flightSpeed;
	this->vanishingRate = vanishingRate;
	alpha = 255;
	startLocation = Object->getPosition();
}

void csf::DisappearingFunctional::Refresh()
{
	alpha = 255;
	Object->setColor(-1, -1, -1, (int)alpha);
	Object->setPosition(startLocation);
}

void csf::DisappearingFunctional::Update()
{
	if (Object->getVisible())
	{
		Vector2f location = Object->getPosition();
		switch (orientation)
		{
		case DisappearingFunctional::Up: Object->setPosition(location.x, location.y - flightSpeed); break;
		case DisappearingFunctional::Down: Object->setPosition(location.x, location.y + flightSpeed); break;
		case DisappearingFunctional::Left: Object->setPosition(location.x - flightSpeed, location.y); break;
		case DisappearingFunctional::Right: Object->setPosition(location.x + flightSpeed, location.y); break;
		case DisappearingFunctional::NotMove: break;
		}
		alpha -= vanishingRate;
		Object->setColor(-1, -1, -1, (int)alpha);
		if (Object->getColor().a <= 1)
		{
			Object->setColor(-1, -1, -1, 0);
			Object->setVisible(false);
		}
	}
}
