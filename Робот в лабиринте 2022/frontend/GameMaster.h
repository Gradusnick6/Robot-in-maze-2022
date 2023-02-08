#pragma once
#include <string>
#include "windows.h"
#include <iostream>
#include "BackHeaders.h"
#include "DrawFunctions.h"
#include "UserCode.h"
#include "lists/GameStatuses.h"
#include "lists/UserCommands.h"
using namespace backend;

namespace front
{
	static class GameMaster
	{
	private:
		// отражает активный игровой экран
		static int status;
		static Maze map;
		static Robot robot;
		static UserCode uCode;

		/// <summary>
		/// возвращает пользовательскую команду
		/// </summary>
		/// <param name="input">UC_UP, ...., UC_AND</param>
		static std::string getCommand(int input);

		/////////ФУНКЦИИ ОБРАБОТКИ ОКОН/////////

		// обработка окна главного меню
		static void ProcMainMenu();
		// обработка окна тестирования работоспособности лабиринта и робота
		static void ProcMazeRobot();
		// обработка окна тестирования работоспособности интерпретатора
		static void ProcInterpreter(); 
		// обработка окна тестирования работоспособности интерпретатора при запуске обработки кода
		static void ProcRobotRun();
		// обработка окна тестирования работоспособности пользовательского кода
		static void ProcUserCode();


		/////////ФУНКЦИИ СОПРОВОЖДЕНИЯ/////////

		/// <summary>
		/// Обработка команды копирования
		/// </summary>
		/// <returns>
		/// true - копирование произведено;     
		/// false - команды не скопированы</returns>
		static bool CopyCommands();
		/// <summary>
		/// Обработка команды вставки
		/// </summary>
		/// <returns>
		/// true - вставка произведена;     
		/// false - вставка завершилась неудачей</returns>
		static bool PasteCommands();
		/// <summary>
		/// Обработка команды добавления пользовательской команды
		/// </summary>
		/// <returns>
		/// true - добавление произведено;     
		/// false - добавление завершилось неудачей</returns>
		static bool AddCommand();
		/// <summary>
		/// Обработка команды удаления пользовательской команды
		/// </summary>
		/// <returns>
		/// true - удаление произведено;     
		/// false - удаление завершилось неудачей</returns>
		static bool DeleteCommand();
		/// <summary>
		/// Обработка команды перемещения пользовательской команды
		/// </summary>
		/// <returns>
		/// true - перемещение произведено;     
		/// false - перемещение завершилось неудачей</returns>
		static bool MoveCommand();
		/// <summary>
		/// выводит на консоль сообщение о требовании вывода x, y		
		/// возвращает Point(x, y)
		/// </summary>
		static Point ScanPoint();
		/// <returns>
		/// true - input соответсвует значению выхода из игры/в меню;     
		/// false - input не соответсвует значению выхода из игры/в меню</returns>
		static bool isExitCommands(int input);
	public:
		//запуск приложения
		static void ProcApp();
	};
}