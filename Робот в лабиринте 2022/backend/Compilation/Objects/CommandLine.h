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
		/// ��������� ��������� ���� (����� commands)
		/// </summary>
		void FillIndexVectors();
		/// <summary>
		/// ������������ ����� value � array
		/// </summary>
		/// <returns>true - ������� ������;   
		/// false - ������� ����������</returns>
		bool find(std::vector<int> array, int value);
	public:
		std::vector<std::string*> commands;
		// �������� ������� ������� ���������  End � ����
		std::vector <int> iEndCommand;
		// �������� ������� ������� �� ����������  While � If � ����
		std::vector <int> iWhileIfCommand;
		// �������� ������� ������� �� ����������  Else � ����
		std::vector <int> iElseCommand;
		CommandLine();
		CommandLine(std::vector<std::string*> commands_);
		void Initialize(std::vector<std::string*> commands_);
		/// <returns>
		/// true - ������ �� ���������������;  
		/// false - ������ ���������������
		///</returns>
		bool isNULL();
		/// <summary>
		/// �������� ����������� ���������� ���������� if � while � ��������� end
		/// </summary>
		/// <returns>
		/// true - �������� ��������; 
		/// false - �������� �� ��������</returns>
		bool PrimaryCompilation();
		int length();
	};
}