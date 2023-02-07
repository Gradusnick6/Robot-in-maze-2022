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
		/// �������� �� command �������� ������������
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isRoute(std::string command);
		/// <summary>
		/// �������� �� command ���������� And ��� Or
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isLogicOperator(std::string command);
		/// <summary>
		/// �������� �� command �������� ����
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isStep(std::string command);
		/// <summary>
		/// �������� �� command ���������� If ��� While
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isIfOrWhile(std::string command);
		/// <summary>
		/// �������� �� command ���������� End ��� Else
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isEndOrElse(std::string command);
		/// <summary>
		/// �������� �� command �������� Wall ��� Loose
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isBarrier(std::string command);
		/// <summary>
		/// �������� �� command ���������� ����, If, While, Else ��� End
		/// </summary>
		/// <returns>
		/// true - ��������;   
		/// false - �� ��������</returns>
		static bool isOperation(std::string command);
		/// <summary>
		/// ��������� ������������ ��������� ������� � commands ������� � ������� index
		/// </summary>
		/// <returns>		
		/// true - ������� ���������;   
		/// false - ������� �� ���������</returns>
		static bool CheckSpellingCondition(std::vector<std::string*> commands, int index);
		/// <summary>
		/// ���������� ��������� ������� � commands ������� � ������� index_out
		/// </summary>
		/// <param name="cell">����������� ������ �����</param>
		/// <returns></returns>
		static bool CheckCondition(std::vector<std::string*> commands, int& index_out, MapCell cell);
		/// <summary>
		/// ���������� ��������� ������� ( "route" "barrier" )
		/// </summary>
		/// <param name="cell">����������� ������ �����</param>
		/// <returns></returns>
		static bool CheckPartCondition(std::string route, std::string barrier, MapCell cell);
	};
}