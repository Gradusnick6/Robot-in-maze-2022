#pragma once

namespace mapBack
{

	class MapCell
	{
	public:
		//true (�������� ����); false (�������� ����)
		bool leftWall, upWall, rightWall, downWall;
		//true (�������� ����); false (�������� ����)
		bool cellsFilling;
		MapCell();
		MapCell(bool leftWall_, bool upWall_, bool rightWall_, bool downWall_);
		MapCell& operator = (const MapCell& other);
	};
}