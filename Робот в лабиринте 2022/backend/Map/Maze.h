#pragma once
#include <time.h>
#include "FileReader.h"
using namespace commonBack;
using namespace mapBack;

namespace backend
{
	class Maze
	{
	private:
		
		int size;
		int mapNumber;
		MapCell** map;
		/// <summary>
		/// индексы стартовой ячейки
		/// </summary>
		Point startPos;
		/// <summary>
		/// индексы финишной ячейки
		/// </summary>
		Point finishPos;
		/// <summary>
		/// очистить память карты
		/// </summary>
		void clearMap();
		/// <summary>
		/// возвращает количество карт уровня сложности levelDifficulty в файле
		/// </summary>
		/// <returns>true - заполнение прошло успешно;
		/// false - заполнение завершилось ошибкой </returns>
		static bool getMapCount(int levelDifficulty, int& mapCount_out);
		/// <summary>
		/// заполняет ячейки карты данными из файла
		/// </summary>
		/// <param name="levelDifficulty">уровень сложности карты</param>
		/// <returns>true - заполнение прошло успешно;
		/// false - заполнение завершилось ошибкой </returns>
		bool setMap(int levelDifficulty);
		/// <summary>
		/// Заполнение ячеек карты значениями mapStr
		/// </summary>
		void setMapByCell(std::vector<std::string> mapStr);
		/// <summary>
		/// заполняет точку pos_out, если в данных ячейки с индексами (x;y) присутсвует symbol 
		/// </summary>
		/// <param name="str">строки с символами</param>
		/// <param name="symbol">определяет тип точки (START_SYMBOL, FINISH_SYMBOL)</param>
		void setPos(std::vector<std::string> str, char symbol, int x, int y, Point& pos_out);
	public:
		Maze();
		/// <summary>
		/// инициализирует поля класса
		/// </summary>
		/// <param name="levelDifficulty">номер уровня сложности</param>
		/// <returns>true - инициализация прошла успешна;
		/// false - инициализация завершилась ошибкой</returns>
		bool Initialize(int levelDifficulty);
		/// <summary>
		/// инициализирует поля класса
		/// </summary>
		/// <param name="levelDifficulty">номер уровня сложности</param>
		/// <param name="number">номер карты</param>
		/// <returns>true - инициализация прошла успешна;
		/// false - инициализация завершилась ошибкой</returns>
		bool Initialize(int levelDifficulty, int mapNumber);
		/// <summary>
		/// возвращает размер квадратной матрицы по одному измерению
		/// </summary>
		int getSize();
		/// <summary>
		/// возвращает номер карты
		/// </summary>
		int getNumber();
		/// <summary>
		/// заполняет поле number значением value
		/// </summary>
		void setNumber(int value);
		/// <summary>
		/// возвращает индексы стартовой позиции
		/// </summary>
		Point getStartPos();
		/// <summary>
		/// возвращает индексы финишной позиции
		/// </summary>
		Point getFinishPos();
		/// <summary>
		/// возвращает ячейку карты
		/// </summary>
		/// <param name="x">первый индекс ячейки</param>
		/// <param name="y">второй индекс ячейки</param>
		MapCell getMapCell(int x, int y);
		/// <summary>
		/// есть ли стена по направлению route
		/// </summary>
		/// <param name="x">координата исходной точки</param>
		/// <param name="y">координата исходной точки</param>
		/// <param name="route">направление движения (RS_....)</param>
		/// <returns>true - на пути стена;
		/// false - на пути свободно</returns>
		bool isWallOnRoute(int x, int y, int route);
		~Maze();
	};
}