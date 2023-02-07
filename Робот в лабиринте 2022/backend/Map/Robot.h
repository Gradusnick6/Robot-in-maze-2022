#pragma once
#include "Common.h"
#include "Maze.h"

namespace backend
{
	class Robot
	{
	private:
		Point pos;
	public:
		Robot();
		Robot(Point p);
		Robot(int x, int y);
		/// <summary>
		/// �������������� ���� ������
		/// </summary>
		/// <param name="pos_">������� ������</param>
		void Initialize(Point pos_);
		/// <summary>
		/// �������������� ���� ������
		/// </summary>
		/// <param name="x">������� ������ �� ��� x</param>
		/// <param name="y">������� ������ �� ��� y</param>
		void Initialize(int x, int y);
		/// <summary>
		/// ���������� ������� ������� ������
		/// </summary>
		Point getPos();
		/// <summary>
		/// ��������� ����������� ������ �� ���� ������
		/// </summary>
		/// <param name="rotateStep">����������� �������� (RS_....)</param>
		/// <returns>true - ����������� ������ �������;
		/// false - ����������� ����������</returns>
		bool MakeStep(Maze& map, int route);
		/// <summary>
		/// ��������� �� ����� � ��������� map
		/// </summary>
		/// <returns>
		/// true - ����� ������ ������;
		/// false - ����� �� ������ ������</returns>
		bool isFinish(Maze& map);
	};
}