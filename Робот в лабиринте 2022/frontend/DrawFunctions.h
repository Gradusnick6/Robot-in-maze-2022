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
		// �������� str � ������� �������
		static std::string Upper(std::string str);
		// ���������� ���������������� ������� � ������� (�������)_UP_RUS_STRING
		// �������� UC_(�������)
		static std::string getRusCommand(int input);
		// ������� �������
		// count - ���������� ��������
		static void PrintSpace(int count);
	public:

		/////////������� ������ ���������� ��� ������� ����������/////////
		
		// ����� ���������� ��� ������ �������� ����
		static void PrintMainMenu();
		// ����� ���������� ��� ������ �� ����������/ � ������� ����
		static void PrintExit_UC();
		// ����� ���������� ��� ������ ������������ ��������� � ������
		static void PrintMazeRobot_UC();
		// ����� ���������� ��� ������ ������������ ��������������
		static void PrintInterpreter_UC();
		// ����� ���������� ��� ������ ������������ ����������������� ����
		static void PrintUserCode_UC();
		// ����� ���������� ��� ����� ������
		static void PrintCommands_UC();


		/// <summary>
		/// ������������ �������� � �������
		/// </summary>
		/// <param name="withStart">���������� ������ ������ � ��������� (true - ����������)</param>
		/// <param name="withFinish">���������� ������ ������ � ��������� (true - ����������)</param>
		/// <param name="withRobot">���������� �������������� ������ � ��������� (true - ����������)</param>
		static void DrawMaze(Maze& map, Robot robot, bool withStart = true, bool withFinish = true, bool withRobot = true);
		//������� ��������� ����������� ��������� �������
		static void PrintResult(Maze& map, Robot robot);

		// ������� ���������������� ���
		static void PrintUserCode(UserCode& uCode);
		/// <summary>
		/// ������� ���������������� ��� ������� � ������� ������� �������� �������
		/// </summary>
		/// <param name="iCommand">������ �������� �������</param>
		/// <param name="countActiveCommand">���������� �������� ������</param>
		static void PrintUserCode(UserCode& uCode, int iCommand, int countActiveCommand);
	};
}