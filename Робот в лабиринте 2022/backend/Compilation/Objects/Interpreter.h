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
		// ����������� end � ����
		// true ������������ if
		// false ������������ while
		std::stack <bool> endsActive;
		/// <summary>
		/// �������� ������� �� ����������� ������ while
		/// </summary>
		std::stack <int> whileActiveIndexes;
		// ����������� while � ����
		// true - ���� ������������
		// false - ���� �����������
		std::stack <bool> whileLock;
		// ���������� else � ����
		// true - ���������� else
		// false - ���������� else
		bool elseLock;
		TypeOperation getCurOperation();
		/// <summary>
		/// ���������� ������ value � array
		/// ���� value ���������� � array, ���������� -1
		/// </summary>
		int getIndex(std::vector <int> array, int value);
		/// <summary>
		/// ���������� ������ ������ command, ����������� �������
		/// </summary>
		int findPrevCommand(std::string command);
		/// <summary>
		/// ��������� ���������� �������� (����)
		/// </summary>
		/// <returns>
		/// true - ��������� ������ �������;  
		/// false - ��������� ������ � ����
		///</returns>
		bool MakeStep(bool route);
		/// <summary>
		/// ��������� ��������� ���������
		/// </summary>
		/// <returns>
		/// true - ��������� ������ �������;  
		/// false - ��������� ������ � ����
		///</returns>
		bool ProcIfOperator(Maze& map, Robot& robot);
		/// <summary>
		/// ��������� else ���������
		/// </summary>
		/// <returns>
		/// true - ��������� ������ �������;  
		/// false - ��������� ������ � ����
		///</returns>
		bool ProcElseOperator();
		/// <summary>
		/// ��������� ��������� �����
		/// </summary>
		/// <returns>
		/// true - ��������� ������ �������;  
		/// false - ��������� ������ � ����
		///</returns>
		bool ProcWhileOperator(Maze& map, Robot& robot);
		/// <summary>
		/// ��������� ��������� end
		/// </summary>
		/// <returns>
		/// true - ��������� ������ �������;  
		/// false - ��������� ������ � ����
		///</returns>
		bool ProcEndOperator();
		/// <summary>
		/// ��������� ������ error; ��������� ������ ������ � �����
		/// </summary>
		/// <param name="typeError">��� ������</param>
		/// <returns>false</returns>
		bool ProcError(int typeError);
		/// <summary>
		/// ���������� ������� ������� ����� s
		/// ���� ���� ������, ���������� -1
		/// </summary>
		int getTop(std::stack <int> s);
	public:
		Interpreter();
		/// <summary>
		/// �������������� ���� �������
		/// </summary>
		/// <param name="commands_">������ ����� � ���������</param>
		/// <returns>true - ��� ������ ��������� ���������� (�� commandLine);   
		/// false - ��� �� ������ ��������� ���������� </returns>
		bool Initialize(std::list<std::string>* commands_);
		/// <summary>
		/// ��������� ������� �������
		/// </summary>
		/// <returns>
		/// true - ������� ������� ����������;   
		/// false - ������ � ���� (��������� GameError)</returns>
		bool ProcCommand(Maze& map, Robot& robot);
		/// <returns>
		/// true - ������� �����������;  
		/// false - ������� �� �����������
		///</returns>
		bool isEndComamnds();
		/// <summary>
		/// ���������� ���������� �������� ������ ������������ ������� ����� (����� ������������ "-")
		/// ��������� ������� ������������
		/// </summary>
		int getCountActiveCommand();
		/// <summary>
		/// ���������� ������ ����������� �������
		/// </summary>
		int getIndexCurrentCommand();
		/// <summary>
		/// ���������� ������ ����������� �������
		/// </summary>
		int getIndexLastCommand();
	};
}