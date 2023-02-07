#pragma once
#include <string>
#include <vector>
#include "LexicalUnits.h"
#include "MapCell.h"
using namespace mapBack;

namespace programming
{
	class Compilation
	{
	public:
		/// <summary>
		/// является ли command условным направлением
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isRoute(std::string command);
		/// <summary>
		/// является ли command оператором And или Or
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isLogicOperator(std::string command);
		/// <summary>
		/// является ли command командой шага
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isStep(std::string command);
		/// <summary>
		/// является ли command оператором If или While
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isIfOrWhile(std::string command);
		/// <summary>
		/// является ли command оператором End или Else
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isEndOrElse(std::string command);
		/// <summary>
		/// является ли command условием Wall или Loose
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isBarrier(std::string command);
		/// <summary>
		/// является ли command оператором шага, If, While, Else или End
		/// </summary>
		/// <returns>
		/// true - является;   
		/// false - не является</returns>
		static bool isOperation(std::string command);
		/// <summary>
		/// проверяет корректность написания условия в commands начиная с индекса index
		/// </summary>
		/// <returns>		
		/// true - условие корректно;   
		/// false - условие не корректно</returns>
		static bool CheckSpellingCondition(std::vector<std::string*> commands, int index);
		/// <summary>
		/// возвращает результат условия в commands начиная с индекса index_out
		/// </summary>
		/// <param name="cell">проверяемая ячейка карты</param>
		/// <returns></returns>
		static bool CheckCondition(std::vector<std::string*> commands, int& index_out, MapCell cell);
		/// <summary>
		/// возвращает результат условия ( "route" "barrier" )
		/// </summary>
		/// <param name="cell">проверяемая ячейка карты</param>
		/// <returns></returns>
		static bool CheckPartCondition(std::string route, std::string barrier, MapCell cell);
	};
}