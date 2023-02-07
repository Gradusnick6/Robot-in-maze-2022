#pragma once
#include "Common.h"
#include "Maze.h"

namespace backend
{
	class Robot
	{
	private:
		Point pos;
	public:
		Robot();
		Robot(Point p);
		Robot(int x, int y);
		/// <summary>
		/// инициализирует поля класса
		/// </summary>
		/// <param name="pos_">позиция робота</param>
		void Initialize(Point pos_);
		/// <summary>
		/// инициализирует поля класса
		/// </summary>
		/// <param name="x">позиция робота на оси x</param>
		/// <param name="y">позиция робота на оси y</param>
		void Initialize(int x, int y);
		/// <summary>
		/// возвращает индексы позиции робота
		/// </summary>
		Point getPos();
		/// <summary>
		/// Выполняет перемещение робота на одну ячейку
		/// </summary>
		/// <param name="rotateStep">направление движения (RS_....)</param>
		/// <returns>true - перемещение прошло успешно;
		/// false - перемещение невозможно</returns>
		bool MakeStep(Maze& map, int route);
		/// <summary>
		/// достигнут ли финиш в лабиринте map
		/// </summary>
		/// <returns>
		/// true - робот достиг финиша;
		/// false - робот не достиг финиша</returns>
		bool isFinish(Maze& map);
	};
}