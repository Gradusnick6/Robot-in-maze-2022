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
		/// ���������� ������������ �� ������ str ��������� firstSimbol.(�����)
		/// </summary>
		/// <param name="firstSimbol">��������� ��������: A D</param>
		/// <returns>
		/// true - ������ ������������ ���������;  false - ������ �� ������������ ���������;</returns>
		static bool isNewItem(std::string str, char firstSimbol);
		/// <summary>
		/// ���������� ����� �� ����������� "(�����)" �� str
		/// </summary>
		/// <param name="startIndex">����� ������� ��������� � str (������������)</param>
		/// <param name="endIndex">������ ������� ��������� � str (������������)</param>
		static int getNumber(std::string str, int startIndex, int endIndex);
		/// <summary>
		/// ��������� ����� ���� � ����� � ������� � ����������� �� levelDifficulty (Database)
		/// </summary>
		static std::string getDetermDifficult(int levelDifficulty);
		/// <summary>
		/// ����������� ��������� � ����� (file) � ����� �� ���������� ������ mapNumber
		/// </summary>
		/// <returns>true - ����� ������ �������;
		/// false - ����� ���������� ������� </returns>
		static bool findMapOnFile(std::ifstream& file, int mapNumber);
		/// <summary>
		/// �������� �� �������� ����� ��������� ".txt"
		/// </summary>
		/// <returns>
		/// true - ��������;     
		/// false - �� ��������</returns>
		static bool isWithTxt(std::string fileName);
	};
}