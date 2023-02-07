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



//��������� ����
#define ROBOT_WORK 0
#define ROBOT_REST 1
#define	ROBOT_INDEPENDENT 2
#define EXIT 3

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