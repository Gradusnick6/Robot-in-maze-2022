#pragma once

namespace mapBack
{

	class MapCell
	{
	public:
		//true (закрытая зона); false (открытая зона)
		bool leftWall, upWall, rightWall, downWall;
		//true (закрытая зона); false (открытая зона)
		bool cellsFilling;
		MapCell();
		MapCell(bool leftWall_, bool upWall_, bool rightWall_, bool downWall_);
		MapCell& operator = (const MapCell& other);
	};
}