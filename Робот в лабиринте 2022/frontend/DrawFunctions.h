#pragma once
#include <iostream>
#include <list>
#include <iomanip>
#include "BackHeaders.h"
#include "GameMaster.h"
#include "UserCode.h"
#include "CodeCell.h"
using namespace backend;

namespace front
{
	class DrawFunctions
	{
		// возводит str в верхний регистр
		static std::string Upper(std::string str);
		// возвращает пользовательскую команду в формате (команда)_UP_RUS_STRING
		// аргумент UC_(команда)
		static std::string getRusCommand(int input);
		// выводит пробелы
		// count - количество пробелов
		static void PrintSpace(int count);
	public:

		/////////‘”Ќ ÷»» ¬џ¬ќƒј »Ќ—“–” ÷»… ƒЋя Ё –јЌќ¬ ѕ–»Ћќ∆≈Ќ»я/////////
		
		// вывод инструкций дл€ экрана главного меню
		static void PrintMainMenu();
		// вывод инструкций дл€ выхода из приложени€/ в главное меню
		static void PrintExit_UC();
		// вывод инструкций дл€ экрана тестировани€ лабиринта и робота
		static void PrintMazeRobot_UC();
		// вывод инструкций дл€ экрана тестировани€ интерпретатора
		static void PrintInterpreter_UC();
		// вывод инструкций дл€ экрана тестировани€ пользовательского кода
		static void PrintUserCode_UC();
		// вывод инструкций дл€ ввода команд
		static void PrintCommands_UC();


		/// <summary>
		/// отрисовывает лабиринт в консоли
		/// </summary>
		/// <param name="withStart">отображать €чейку старта в лабиринте (true - отобразить)</param>
		/// <param name="withFinish">отображать €чейку финиша в лабиринте (true - отобразить)</param>
		/// <param name="withRobot">отображать местоположение робота в лабиринте (true - отобразить)</param>
		static void DrawMaze(Maze& map, Robot robot, bool withStart = true, bool withFinish = true, bool withRobot = true);
		//выводит результат прохождени€ лабиринта роботом
		static void PrintResult(Maze& map, Robot robot);

		// выводит пользовательский код
		static void PrintUserCode(UserCode& uCode);
		/// <summary>
		/// выводит пользовательский код выдел€€ в верхний регистр активные команды
		/// </summary>
		/// <param name="iCommand">индекс активной команды</param>
		/// <param name="countActiveCommand">количество активных команд</param>
		static void PrintUserCode(UserCode& uCode, int iCommand, int countActiveCommand);
	};
}