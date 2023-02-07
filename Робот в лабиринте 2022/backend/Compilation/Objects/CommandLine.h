#pragma once
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "LexicalUnits.h"

namespace programming
{
	class CommandLine
	{
	private:
		/// <summary>
		/// заполняет векторные поля (кроме commands)
		/// </summary>
		void FillIndexVectors();
		/// <summary>
		/// осуществляет поиск value в array
		/// </summary>
		/// <returns>true - элемент найден;   
		/// false - элемент отсутсвует</returns>
		bool find(std::vector<int> array, int value);
	public:
		std::vector<std::string*> commands;
		// содержит индексы каждого оператора  End в коде
		std::vector <int> iEndCommand;
		// содержит индексы каждого из операторов  While и If в коде
		std::vector <int> iWhileIfCommand;
		// содержит индексы каждого из операторов  Else в коде
		std::vector <int> iElseCommand;
		CommandLine();
		CommandLine(std::vector<std::string*> commands_);
		void Initialize(std::vector<std::string*> commands_);
		/// <returns>
		/// true - объект не инициализирован;  
		/// false - объект инициализирован
		///</returns>
		bool isNULL();
		/// <summary>
		/// проверка соответсвия количества операторов if и while и оператора end
		/// </summary>
		/// <returns>
		/// true - проверка пройдена; 
		/// false - проверка не пройдена</returns>
		bool PrimaryCompilation();
		int length();
	};
}