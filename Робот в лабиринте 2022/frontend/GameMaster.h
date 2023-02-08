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
		// �������� �������� ������� �����
		static int status;
		static Maze map;
		static Robot robot;
		static UserCode uCode;

		/// <summary>
		/// ���������� ���������������� �������
		/// </summary>
		/// <param name="input">UC_UP, ...., UC_AND</param>
		static std::string getCommand(int input);

		/////////������� ��������� ����/////////

		// ��������� ���� �������� ����
		static void ProcMainMenu();
		// ��������� ���� ������������ ����������������� ��������� � ������
		static void ProcMazeRobot();
		// ��������� ���� ������������ ����������������� ��������������
		static void ProcInterpreter(); 
		// ��������� ���� ������������ ����������������� �������������� ��� ������� ��������� ����
		static void ProcRobotRun();
		// ��������� ���� ������������ ����������������� ����������������� ����
		static void ProcUserCode();


		/////////������� �������������/////////

		/// <summary>
		/// ��������� ������� �����������
		/// </summary>
		/// <returns>
		/// true - ����������� �����������;     
		/// false - ������� �� �����������</returns>
		static bool CopyCommands();
		/// <summary>
		/// ��������� ������� �������
		/// </summary>
		/// <returns>
		/// true - ������� �����������;     
		/// false - ������� ����������� ��������</returns>
		static bool PasteCommands();
		/// <summary>
		/// ��������� ������� ���������� ���������������� �������
		/// </summary>
		/// <returns>
		/// true - ���������� �����������;     
		/// false - ���������� ����������� ��������</returns>
		static bool AddCommand();
		/// <summary>
		/// ��������� ������� �������� ���������������� �������
		/// </summary>
		/// <returns>
		/// true - �������� �����������;     
		/// false - �������� ����������� ��������</returns>
		static bool DeleteCommand();
		/// <summary>
		/// ��������� ������� ����������� ���������������� �������
		/// </summary>
		/// <returns>
		/// true - ����������� �����������;     
		/// false - ����������� ����������� ��������</returns>
		static bool MoveCommand();
		/// <summary>
		/// ������� �� ������� ��������� � ���������� ������ x, y		
		/// ���������� Point(x, y)
		/// </summary>
		static Point ScanPoint();
		/// <returns>
		/// true - input ������������ �������� ������ �� ����/� ����;     
		/// false - input �� ������������ �������� ������ �� ����/� ����</returns>
		static bool isExitCommands(int input);
	public:
		//������ ����������
		static void ProcApp();
	};
}