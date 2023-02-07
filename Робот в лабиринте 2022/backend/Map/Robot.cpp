#include "Robot.h"

using namespace backend;

Robot::Robot(){ pos.setPoint(0, 0); }

Robot::Robot(Point p) { Initialize(p); }

Robot::Robot(int x, int y) { Initialize(x, y); }

void Robot::Initialize(Point p) { pos = p; }

void Robot::Initialize(int x, int y) { pos.setPoint(x, y); }

Point Robot::getPos() { return pos; }

bool Robot::MakeStep(Maze& map, int route)
{
	switch (route)
	{
	case RS_UP:
		if (!map.isWallOnRoute(pos.x, pos.y, RS_UP))
		{
			pos.x--; return true;
		} return false;
	case RS_DOWN:
		if (!map.isWallOnRoute(pos.x, pos.y, RS_DOWN))
		{
			pos.x++; return true;
		} return false;
	case RS_LEFT:
		if (!map.isWallOnRoute(pos.x, pos.y, RS_LEFT))
		{
			pos.y--; return true;
		} return false;
	case RS_RIGHT:
		if (!map.isWallOnRoute(pos.x, pos.y, RS_RIGHT))
		{
			pos.y++; return true;
		} return false;
	}
	return false;
}

bool Robot::isFinish(Maze& map) { return pos.x == map.getFinishPos().x && pos.y == map.getFinishPos().y; }