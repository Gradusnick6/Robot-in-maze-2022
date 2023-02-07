#pragma once
#include <string>

namespace commonBack
{
	struct Point
	{
		int x, y;
		void setPoint(int x_, int y_);
		Point();
		Point(int x_, int y_);
		Point& operator=(const Point& other);
		bool operator==(const Point& other);
	};

	/// <summary>
	/// является ли содержимое строки целым числом
	/// </summary>
	/// <returns>true - str содержит int;
	/// false - str содержит не int</returns>
	bool checkStringOnInt(std::string str);
}