#pragma once
#include <string>
#include <list>
#include "Maze.h"
#include "LexicalUnits.h"
#include "Compilation.h"
#include "FileReader.h"
#include "CodeCell.h"
using namespace mapBack;
using namespace userCodeBack;

////////���� �������� ������� � ����� ������//////////

#define PARAGRAPH_NO 0
#define PARAGRAPH_RIGHT 1
#define PARAGRAPH_LEFT 2

namespace backend
{
	class UserCode
	{
	private:
		/////////�������/////////
		
		// ���������� ����� ��� ���� � ������
		int wSize = 16;
		// ���������� ����� ��� ���� � ������
		int hSize = 54;

		// ����������� ������ � ������ ����� ����� ��������� ���������
		const int standartStep = 3;

		/////////���������� ��������������/////////
		Point lastPos;
		int curParagraph;

		/////////������ ��� ������/////////

		std::list<CodeCell> codeCells;
		std::list<std::string> commands;
		std::list<std::string> clipboard;

		/////////�����/////////
		
		/// <summary>
		/// ������� ������� (command) �� ������� ����� � ������� �������������� �������
		/// </summary>
		std::string getRussianCommand(std::string command);
		/// <returns>
		/// true - paragraph ����� ������������ ��������;     
		/// false - paragraph ����� �� ������������ ��������</returns>
		bool isMaxParagraph();
		/// <summary>
		/// ��������� ������� � codeCells
		/// </summary>
		/// <param name="mute">���������� ����������� ��������� ���������� ������</param>
		/// <param name="fantom">���������� ����������� ������</param>
		std::list<CodeCell>::iterator AddCell(Point p, std::string* command, bool mute, bool fantom);
		/// <summary>
		/// �������� �������
		/// </summary>
		/// <param name="p">������� ������ � ��������</param>
		/// <param name="command">������ �������</param>
		/// <param name="mute">���������� ����������� ��������� ���������� ������</param>
		/// <param name="fantom">���������� ����������� ������</param>
		/// <returns>��������� ������ ���� � ����������� ���������;		
		/// ���� ���������� �� �����������, ���������� codeCells.end()</returns>
		std::list<CodeCell>::iterator AddCommand(Point p, std::string command, bool mute, bool fantom);
		/// <summary>
		/// ������� �������� �� ������� codeCells (���������� - countCell) � commands (���������� - clipboard.size())
		/// </summary>
		/// <param name="lastCell">��������� �� ��������� ��������� ������</param>
		/// <param name="firstCommand">��������� �� ������ ��������� �������</param>
		/// <returns>false</returns>
		bool DeleteCommandsAfterPaste(std::list<CodeCell>::iterator lastCell, int countCell, std::list<std::string>::iterator firstCommand);
		/// <summary>
		/// ���������� ��������� �� ������� � �������� ����� ������� pos.
		/// ���� ����� �������� ���, ���������� codeCells.end()
		/// </summary>
		std::list<CodeCell>::iterator getPrevCell(Point pos);

		

		//////////////////�������������� ����///////////////////////

		/// <summary>
		/// �������� ���������� �������������� ��� ������� curCommand
		/// </summary>
		/// <returns>
		/// true - �������������� ������ �������;     
		/// false - ������ ��������������/// </returns>
		bool FormatCurCommand(std::list<std::string>::iterator curCommand);
		/// <summary>
		/// ������� ������� ���� �����, ������� � firstCell �� countLine ������� ����
		/// </summary>
		/// <returns>
		/// true - �������� ������� ���������;      
		/// false - �������� ����������� �������</returns>
		bool ShiftCodeDown(std::list<CodeCell>::iterator firstCell, int countLine);
		/// <summary>
		/// ���������� ������������ ���������� ������� ��� �������� �����
		/// </summary>
		/// <param name="countCommands">���������� ������, ��� ������� ����� �������� �������</param>
		int getCountLine(int countCommands);

		/////////������� �������������� ������ ����� ������/////////

		/// <summary>
		/// �������������� ������� �� ������� "���������� ������� else ��� then"
		/// </summary>
		/// <returns>
		/// true - �������������� ������ �������
		/// false - ������ ��������������/// </returns>
		bool PrevElseThenFormat();
		/// <summary>
		/// �������������� ������� �� ������� "������� ������� If ��� While"
		/// </summary>
		/// <returns>
		/// true - �������������� ������ �������     
		/// false - ������ ��������������/// </returns>
		bool IfWhileFormat();
		/// <summary>
		/// �������������� ������� �� ������� "������� ����� ������������� � ���� �������"
		/// </summary>
		/// <returns>
		/// true - �������������� ������ �������     
		/// false - ������ ��������������/// </returns>
		bool OnLineFormat();
		/// <summary>
		/// �������������� ������� �� ������� "������� ������� Else ��� End"
		/// </summary>
		/// <returns>
		/// true - �������������� ������ �������     
		/// false - ������ ��������������/// </returns>
		bool ElseEndFormat();
		/// <summary>
		/// �������������� ������� �� ������� "������� ������� "������""
		/// </summary>
		/// <param name="curCommand">��������� �������������� ������� � ������� commands</param>
		/// <returns>
		/// true - �������������� ������ �������     
		/// false - ������ ��������������/// </returns>
		bool EmptyFormat(std::list<std::string>::iterator curCommand);

		/////////��������� ����������� ��������������/////////

		/// <summary>
		/// �������� ���������� �������������� � ������ ������������� �������� �� ����� ������
		/// </summary>
		/// <param name="typeParagraph">�������� ������� � ����� ������ (PARAGRAPH...)</param>
		/// <returns>
		/// true - ��������� ������ �������     
		/// false - ��������� ����������/// </returns>
		bool OnNewParagraph(int typeParagraph = PARAGRAPH_NO);
		/// <summary>
		/// �������� ���������� �������������� ��� ����� ������������� �������� �� ����� ������
		/// </summary>
		/// <returns>
		/// true - ��������� ������ �������;     
		/// false - ��������� ����������/// </returns>
		bool OnLine();

		/////////������ � �������� ���������� ��������////////

		/// <summary>
		/// ���������� ��������� ������ ����� � �������������� pos. 
		/// ���� ������ �������� �� ����������, ���������� end()
		/// </summary>
		std::list<CodeCell>::iterator find(Point pos);

		/// <summary>
		/// ���������� ��������� ������ ������ � �������������� command. 
		/// ���� ������ �������� �� ����������, ���������� end()
		/// </summary>
		std::list<std::string>::iterator find(std::string* command);

	public:
		UserCode();
		void Initialize();

		/// <summary>
		/// �������� �������
		/// </summary>
		/// <param name="p">������� ������ � ��������</param>
		/// <returns>��������� ������ ���� � ����������� ���������;		
		/// ���� ���������� �� �����������, ���������� codeCells.end()</returns>
		std::list<CodeCell>::iterator AddCommand(Point p, std::string command);
		/// <summary>
		/// ������� �������
		/// </summary>
		/// true - ������� �������;     
		/// false - �������� �� �����������/// </returns>
		bool DeleteCommand(std::string* command);
		/// <summary>
		/// ������� �������
		/// </summary>
		/// <param name="index">������ ��������� �������</param>
		/// true - ������� �������;     
		/// false - �������� �� �����������/// </returns>
		bool DeleteCommand(int index);
		/// <summary>
		/// �������� ��������� �������
		/// </summary>
		/// <param name="iterCell">��������� �� ������������� ������</param>
		/// <param name="newPos">����� ������� �������</param>
		/// true - ������� ����������;     
		/// false - ������� �� ����������/// </returns>
		bool MoveCommand(std::list<CodeCell>::iterator iterCell, Point newPos);
		/// <summary>
		/// �������� ��������� �������
		/// </summary>
		/// <param name="index">������ ��������� �������</param>
		/// <param name="newPos">����� ������� �������</param>
		/// true - ������� ����������;     
		/// false - ������� �� ����������/// </returns>
		bool MoveCommand(int index, Point newPos);
		/// <summary>
		/// ������� ��� �������
		/// </summary>
		void ClearCommands();




		/// <summary>
		/// ���������� ������� codeCells �� �������� ��������������
		/// </summary>
		/// <returns>
		/// true - �������������� ������ �������;     
		/// false - ������ �������������� </returns>
		bool Format();

		/// <summary>
		/// ����������� ������� �� ����� � ������ commands
		/// </summary>
		/// <param name="map_out">��� ���������� ������ �����</param>
		/// <param name="fileName">�������� �� ���������, ���� � ����� ��� ������ ������ ���������</param>
		/// <returns>
		/// true - ������ ������ �������;            
		/// false - ������ �� ���������� </returns>
		bool Import(Maze& map_out, std::string fileName = "database\\code\\code.txt", int mapNumber = -1);
		/// <summary>
		/// ������������ ������� � ���� � ������ fileName
		/// </summary>
		/// <returns>
		/// true - ������� ������ �������;            
		/// false - ������� �� ����������</returns>
		bool Export(Maze& map, std::string fileName);

		/// <summary>
		/// ������� clipboard � ��������� ������� commands_
		/// </summary>
		void Copy(std::list<std::string> commands_);

		/// <summary>
		/// ��������� ������� �� ������ ������ � ���� ��� ���� (� ����������� ��������������)
		/// </summary>
		/// <param name="pos">������� ������ �� ����������� ������</param>
		/// <returns>
		/// true - �������� ������� ���������;      
		/// false - �������� ����������� �������</returns>
		bool Paste(Point pos);

		/// <returns>
		/// true - ����� ������ ����;      
		/// false - ����� ������ �������� �������</returns>
		bool isClipboardEmpty();

		////////////GET////////////

		int getWightSize();
		int getHeightSize();
		std::list<CodeCell> getCodeCells();
		std::list<CodeCell>::iterator getCodeCellsEnd();
		std::list<std::string>* getCommands();
	};
}