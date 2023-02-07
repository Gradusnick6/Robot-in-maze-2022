#include "Common.h"
using namespace commonBack;

void Point::setPoint(int x_, int y_)
{
	x = x_;
	y = y_;
}

Point::Point()
{
	x = -1;
	y = -1;
}

Point::Point(int x_, int y_) { setPoint(x_, y_); }

Point& Point::operator=(const Point& other)
{
	if (this == &other)
		return *this;

	x = other.x;
	y = other.y;
	return *this;
}

bool Point::operator==(const Point& other)  { return y == other.y && x == other.x; }

bool commonBack::checkStringOnInt(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
		if ((int)str[i] < '0' || (int)str[i] > '9')
			return false;
	return true;
}