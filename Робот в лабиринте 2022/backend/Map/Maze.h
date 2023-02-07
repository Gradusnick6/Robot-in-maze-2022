#pragma once
#include <time.h>
#include "FileReader.h"
using namespace commonBack;
using namespace mapBack;

namespace backend
{
	class Maze
	{
	private:
		
		int size;
		int mapNumber;
		MapCell** map;
		/// <summary>
		/// ������� ��������� ������
		/// </summary>
		Point startPos;
		/// <summary>
		/// ������� �������� ������
		/// </summary>
		Point finishPos;
		/// <summary>
		/// �������� ������ �����
		/// </summary>
		void clearMap();
		/// <summary>
		/// ���������� ���������� ���� ������ ��������� levelDifficulty � �����
		/// </summary>
		/// <returns>true - ���������� ������ �������;
		/// false - ���������� ����������� ������� </returns>
		static bool getMapCount(int levelDifficulty, int& mapCount_out);
		/// <summary>
		/// ��������� ������ ����� ������� �� �����
		/// </summary>
		/// <param name="levelDifficulty">������� ��������� �����</param>
		/// <returns>true - ���������� ������ �������;
		/// false - ���������� ����������� ������� </returns>
		bool setMap(int levelDifficulty);
		/// <summary>
		/// ���������� ����� ����� ���������� mapStr
		/// </summary>
		void setMapByCell(std::vector<std::string> mapStr);
		/// <summary>
		/// ��������� ����� pos_out, ���� � ������ ������ � ��������� (x;y) ����������� symbol 
		/// </summary>
		/// <param name="str">������ � ���������</param>
		/// <param name="symbol">���������� ��� ����� (START_SYMBOL, FINISH_SYMBOL)</param>
		void setPos(std::vector<std::string> str, char symbol, int x, int y, Point& pos_out);
	public:
		Maze();
		/// <summary>
		/// �������������� ���� ������
		/// </summary>
		/// <param name="levelDifficulty">����� ������ ���������</param>
		/// <returns>true - ������������� ������ �������;
		/// false - ������������� ����������� �������</returns>
		bool Initialize(int levelDifficulty);
		/// <summary>
		/// �������������� ���� ������
		/// </summary>
		/// <param name="levelDifficulty">����� ������ ���������</param>
		/// <param name="number">����� �����</param>
		/// <returns>true - ������������� ������ �������;
		/// false - ������������� ����������� �������</returns>
		bool Initialize(int levelDifficulty, int mapNumber);
		/// <summary>
		/// ���������� ������ ���������� ������� �� ������ ���������
		/// </summary>
		int getSize();
		/// <summary>
		/// ���������� ����� �����
		/// </summary>
		int getNumber();
		/// <summary>
		/// ��������� ���� number ��������� value
		/// </summary>
		void setNumber(int value);
		/// <summary>
		/// ���������� ������� ��������� �������
		/// </summary>
		Point getStartPos();
		/// <summary>
		/// ���������� ������� �������� �������
		/// </summary>
		Point getFinishPos();
		/// <summary>
		/// ���������� ������ �����
		/// </summary>
		/// <param name="x">������ ������ ������</param>
		/// <param name="y">������ ������ ������</param>
		MapCell getMapCell(int x, int y);
		/// <summary>
		/// ���� �� ����� �� ����������� route
		/// </summary>
		/// <param name="x">���������� �������� �����</param>
		/// <param name="y">���������� �������� �����</param>
		/// <param name="route">����������� �������� (RS_....)</param>
		/// <returns>true - �� ���� �����;
		/// false - �� ���� ��������</returns>
		bool isWallOnRoute(int x, int y, int route);
		~Maze();
	};
}