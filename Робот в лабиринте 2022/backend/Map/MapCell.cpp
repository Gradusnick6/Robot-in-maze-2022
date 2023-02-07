#include "MapCell.h"
using namespace mapBack;

MapCell::MapCell()
{
	leftWall = false;
	upWall = false;
	rightWall = false;
	downWall = false;
	cellsFilling = false;
}

MapCell::MapCell(bool leftWall_, bool upWall_, bool rightWall_, bool downWall_)
{
	leftWall = leftWall_;
	upWall = upWall_;
	rightWall = rightWall_;
	downWall = downWall_;
	cellsFilling = leftWall && upWall && rightWall && downWall;
}

MapCell& MapCell::operator=(const MapCell& other)
{
	if (this == &other)
		return *this;

	leftWall = other.leftWall;
	upWall = other.upWall;
	rightWall = other.rightWall;
	downWall = other.downWall;
	cellsFilling = other.cellsFilling;
	return *this;
}