#pragma once
#include <string>
#include "Common.h"
#include "Database.h"
using namespace commonBack;

namespace userCodeBack
{
	class CodeCell
	{
	private:
		Point pos;
		// �������� �������
		std::string* command;
		// ���������� ����������� ��������� ������
		// true - ������������ ������ � ���������� ������;
		// false - ������������� ������ � ���������� ������.
		bool muted;
		/// ����������, ����� �� �������������� ������ � ���� (���������� �� � ������������)
		/// ���� ������ �� ������������, ��� ����� ������� ����� �������� ����
		/// true - ������ �� ������������;
		/// false - ������ ������������.
		bool fantom;
		int paragraph;
	public:
		CodeCell();
		CodeCell(std::string* command_, Point pos_, int paragraph_,bool mute = false, bool fantom_ = false);
		/// <summary>
		/// ������������� ����� ������
		/// </summary>
		/// <param name="command_">������ �������</param>
		/// <param name="pos_">�������, ������� � (0;0)</param>
		/// <param name="paragraph_">�������� ������ ������</param>
		/// <param name="mute">���������� ����������� ��������� ������</param>
		void Initialize(std::string* command_, Point pos_, int paragraph_, bool mute = false, bool fantom_ = false);
		/// <summary>
		/// �������� ���� �������, ���� ������ �� ���������
		/// </summary>
		/// <param name="pos_">�������, ������� � (0;0)</param>
		/// <returns>true - ������ ��������;
		/// false - ��������� ����������</returns>
		bool setPos(Point pos_);
		/// <summary>
		/// �������� ���� �������, ���� ������ �� ���������
		/// </summary>
		/// <param name="command_">������ �������</param>
		/// <returns>true - ������ ��������;
		/// false - ��������� ����������</returns>
		bool setCommand(std::string* command_);
		/// <summary>
		/// ������� ������� ������
		/// </summary>
		/// <param name="x_offset">�������� �� ���������</param>
		/// <param name="y_offset">�������� �� �����������</param>
		/// <returns>����� ���������� ��������� ������</returns>
		Point Shift(int x_offset, int y_offset);
		/// <returns>true - ������������ ������ � ���������� ������;  
		/// false - ������������� ������ � ���������� ������.</returns>
		bool isMuted();
		/// <summary>
		/// ���������� ������� ������
		/// </summary>
		Point getPos();
		/// <summary>
		/// ���������� ������� ������
		/// </summary>
		std::string* getCommand();
		/// <summary>
		/// ���������� �������� ������ ������
		/// </summary>
		int getParagraph();
		CodeCell operator=(CodeCell other);
		bool operator >(CodeCell other);
		bool operator <(CodeCell other);
		bool operator ==(CodeCell other);
	};
}