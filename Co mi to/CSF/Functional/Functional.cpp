#include "Functional.h"
#define _USE_MATH_DEFINES
#include <math.h>

Vector2f csf::Functional::Rotate(Vector2f pos, Vector2f centre, float angle)
{
	pos.x -= centre.x;
	pos.y -= centre.y;
	angle *= (float)M_PI / 180;
	Vector2f newPos(pos.x * cos(angle) - pos.y * sin(angle),
		pos.x * sin(angle) + pos.y * cos(angle));
	newPos.x += centre.x;
	newPos.y += centre.y;
	return newPos;
}

csf::Functional::Functional()
{
	Object = NULL;
}

csf::Functional::Functional(BaseObject* Object)
{
	this->Object = Object;
}
