#pragma once
#include <fstream>
#include <vector>
#include "Database.h"
#include "Common.h"
#include "MapCell.h"

namespace commonBack
{
	class FileReader
	{
	public:
		/// <summary>
		/// возвращает соответсвует ли строка str структуре firstSimbol.(число)
		/// </summary>
		/// <param name="firstSimbol">возможные значения: A D</param>
		/// <returns>
		/// true - строка соответсвует структуре;  false - строка не соответсвует структуре;</returns>
		static bool isNewItem(std::string str, char firstSimbol);
		/// <summary>
		/// возвращает число из конструкции "(число)" из str
		/// </summary>
		/// <param name="startIndex">левая граница диапазона в str (включительно)</param>
		/// <param name="endIndex">правая граница диапазона в str (включительно)</param>
		static int getNumber(std::string str, int startIndex, int endIndex);
		/// <summary>
		/// возращает часть пути к файлу с картами в зависимости от levelDifficulty (Database)
		/// </summary>
		static std::string getDetermDifficult(int levelDifficulty);
		/// <summary>
		/// перемещения указателя в файле (file) к карте по указанному номеру mapNumber
		/// </summary>
		/// <returns>true - поиск прошел успешно;
		/// false - поиск завершился ошибкой </returns>
		static bool findMapOnFile(std::ifstream& file, int mapNumber);
		/// <summary>
		/// содержит ли название файла окончание ".txt"
		/// </summary>
		/// <returns>
		/// true - содержит;     
		/// false - не содержит</returns>
		static bool isWithTxt(std::string fileName);
	};
}