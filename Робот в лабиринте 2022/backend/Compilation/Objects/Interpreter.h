#pragma once
#include <list>
#include "CommandLine.h"
#include "Compilation.h"
#include "GameError.h"
#include "TypeOperation.h"
#include "Maze.h"
#include "Robot.h"
using namespace programming;

namespace backend
{
	class Interpreter
	{
	private:
		int countActiveCommand;
		int iLastCommand;
		int iCommand;
		CommandLine cLine;
		GameError error;
		// блокираторы end в коде
		// true соответсвует if
		// false соответсвует while
		std::stack <bool> endsActive;
		/// <summary>
		/// содержит индексы не завершенных команд while
		/// </summary>
		std::stack <int> whileActiveIndexes;
		// блокираторы while в коде
		// true - цикл продолжается
		// false - цикл завершается
		std::stack <bool> whileLock;
		// блокиратор else в коде
		// true - пропустить else
		// false - обработать else
		bool elseLock;
		TypeOperation getCurOperation();
		/// <summary>
		/// возвращает индекс value в array
		/// если value отсутсвует в array, возвращает -1
		/// </summary>
		int getIndex(std::vector <int> array, int value);
		/// <summary>
		/// возвращает индекс первой command, иттерируясь обратно
		/// </summary>
		int findPrevCommand(std::string command);
		/// <summary>
		/// обработка операторов действия (шага)
		/// </summary>
		/// <returns>
		/// true - обработка прошла успешно;  
		/// false - произошла ошибка в коде
		///</returns>
		bool MakeStep(bool route);
		/// <summary>
		/// Обработка условного оператора
		/// </summary>
		/// <returns>
		/// true - обработка прошла успешно;  
		/// false - произошла ошибка в коде
		///</returns>
		bool ProcIfOperator(Maze& map, Robot& robot);
		/// <summary>
		/// Обработка else оператора
		/// </summary>
		/// <returns>
		/// true - обработка прошла успешно;  
		/// false - произошла ошибка в коде
		///</returns>
		bool ProcElseOperator();
		/// <summary>
		/// Обработка оператора цикла
		/// </summary>
		/// <returns>
		/// true - обработка прошла успешно;  
		/// false - произошла ошибка в коде
		///</returns>
		bool ProcWhileOperator(Maze& map, Robot& robot);
		/// <summary>
		/// Обработка оператора end
		/// </summary>
		/// <returns>
		/// true - обработка прошла успешно;  
		/// false - произошла ошибка в коде
		///</returns>
		bool ProcEndOperator();
		/// <summary>
		/// заполняет объект error; переводит индекс команд в конец
		/// </summary>
		/// <param name="typeError">тип ошибки</param>
		/// <returns>false</returns>
		bool ProcError(int typeError);
		/// <summary>
		/// возвращает крайний элемент стека s
		/// если стек пустой, возвращает -1
		/// </summary>
		int getTop(std::stack <int> s);
	public:
		Interpreter();
		/// <summary>
		/// инициализирует поля объекта
		/// </summary>
		/// <param name="commands_">список строк с командами</param>
		/// <returns>true - код прошёл первичную компиляцию (см commandLine);   
		/// false - код не прошёл первичную компиляцию </returns>
		bool Initialize(std::list<std::string>* commands_);
		/// <summary>
		/// выполняет текущую команду
		/// </summary>
		/// <returns>
		/// true - команда успешно обработана;   
		/// false - ошибка в коде (подробнее GameError)</returns>
		bool ProcCommand(Maze& map, Robot& robot);
		/// <returns>
		/// true - команды закончились;  
		/// false - команды не закончились
		///</returns>
		bool isEndComamnds();
		/// <summary>
		/// возвращает количество активных команд относительно текущей точки (нужно использовать "-")
		/// последняя команда включительно
		/// </summary>
		int getCountActiveCommand();
		/// <summary>
		/// возвращает индекс исполняемой команды
		/// </summary>
		int getIndexCurrentCommand();
		/// <summary>
		/// возвращает индекс исполненной команды
		/// </summary>
		int getIndexLastCommand();
	};
}