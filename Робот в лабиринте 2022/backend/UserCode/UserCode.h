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

////////ТИПЫ СМЕЩЕНИЯ ОТСТУПА В НОВОМ АБЗАЦЕ//////////

#define PARAGRAPH_NO 0
#define PARAGRAPH_RIGHT 1
#define PARAGRAPH_LEFT 2

namespace backend
{
	class UserCode
	{
	private:
		/////////РАЗМЕРЫ/////////
		
		// количество ячеек для кода в ширину
		int wSize = 16;
		// количество ячеек для кода в высоту
		int hSize = 54;

		// стандартный отступ в ширину между двумя соседними командами
		const int standartStep = 3;

		/////////ПОКАЗАТЕЛИ ФОРМАТИРОВАНИЯ/////////
		int lastHeight;
		int lastWight;
		int curParagraph;

		/////////ПАМЯТЬ ДЛЯ КОМАНД/////////

		std::list<CodeCell> codeCells;
		std::list<std::string> commands;
		std::list<std::string> clipboard;

		/////////ОБЩЕЕ/////////
		
		/// <summary>
		/// перевод команды (command) на русском языке в команду интерпретатора системы
		/// </summary>
		std::string getRussianCommand(std::string command);
		/// <returns>
		/// true - paragraph имеет максимальное значение;     
		/// false - paragraph имеет не максимальное значение</returns>
		bool isMaxParagraph();
		/// <summary>
		/// добавляет элемент в codeCells
		/// </summary>
		std::list<CodeCell>::iterator AddCell(Point p, std::string* command);
		/// <summary>
		/// удаляет элемент из codeCells с позицией pos_
		/// </summary>
		void DeleteCell(Point pos_);
		/// <summary>
		/// удаляет элементы из списков codeCells (количество - countCell) и commands (количество - clipboard.size())
		/// </summary>
		/// <param name="lastCell">иттератор на последнюю удаляемую ячейку</param>
		/// <param name="firstCommand">иттератор на первую удаляемую команду</param>
		/// <returns>false</returns>
		bool DeleteCommandsAfterPaste(std::list<CodeCell>::iterator lastCell, int countCell, std::list<std::string>::iterator firstCommand);
		/// <summary>
		/// возвращает иттератор на элемент с позицией раней позиции pos.
		/// если таких элементо нет, возвращает codeCells.end()
		/// </summary>
		std::list<CodeCell>::iterator getPrevCell(Point pos);

		

		//////////////////ФОРМАТИРОВАНИЕ КОДА///////////////////////

		/// <summary>
		/// изменяет показатели форматирования для команды curCommand
		/// </summary>
		/// <returns>
		/// true - форматирование прошло успешно;     
		/// false - ошибка форматирования/// </returns>
		bool FormatCurCommand(std::list<std::string>::iterator curCommand);
		/// <summary>
		/// смещает позицию всех ячеек, начиная с firstCell на countLine строчек вниз
		/// </summary>
		/// <returns>
		/// true - операция успешно завершена;      
		/// false - операция завершилась ошибкой</returns>
		bool ShiftCodeDown(std::list<CodeCell>::iterator firstCell, int countLine);
		/// <summary>
		/// возвращает рассчитанное количество строчек для смещения ячеек
		/// </summary>
		/// <param name="countCommands">количество команд, для которых нужно выделить строчки</param>
		int getCountLine(int countCommands);

		/////////ПРАВИЛА ФОРМАТИРОВАНИЯ РАЗНЫХ ТИПОВ КОМАНД/////////

		/// <summary>
		/// форматирование команды по правилу "Предыдущая команда else или then"
		/// </summary>
		/// <returns>
		/// true - форматирование прошло успешно
		/// false - ошибка форматирования/// </returns>
		bool PrevElseThenFormat();
		/// <summary>
		/// форматирование команды по правилу "Текущая команда If или While"
		/// </summary>
		/// <returns>
		/// true - форматирование прошло успешно     
		/// false - ошибка форматирования/// </returns>
		bool IfWhileFormat();
		/// <summary>
		/// форматирование команды по правилу "Команды могут располагаться в одну строчку"
		/// </summary>
		/// <returns>
		/// true - форматирование прошло успешно     
		/// false - ошибка форматирования/// </returns>
		bool OnLineFormat();
		/// <summary>
		/// форматирование команды по правилу "Текущая команда Else или End"
		/// </summary>
		/// <returns>
		/// true - форматирование прошло успешно     
		/// false - ошибка форматирования/// </returns>
		bool ElseEndFormat();
		/// <summary>
		/// форматирование команды по правилу "Текущая команда "Пустое""
		/// </summary>
		/// <param name="curCommand">иттератор обрабатываемой команды в массиве commands</param>
		/// <returns>
		/// true - форматирование прошло успешно     
		/// false - ошибка форматирования/// </returns>
		bool EmptyFormat(std::list<std::string>::iterator curCommand);

		/////////ИЗМЕНЕНИЕ ПОКАЗАТЕЛЕЙ ФОРМАТИРОВАНИЯ/////////

		/// <summary>
		/// изменяет показатели форматирования с учетом обязательного перехода на новую строку
		/// </summary>
		/// <param name="typeParagraph">смещение отступа в новом абзаце (PARAGRAPH...)</param>
		/// <returns>
		/// true - изменение прошло успешно     
		/// false - изменение невозможно/// </returns>
		bool OnNewParagraph(int typeParagraph = PARAGRAPH_NO);
		/// <summary>
		/// изменяет показатели форматирования без учета обязательного перехода на новую строку
		/// </summary>
		/// <returns>
		/// true - изменение прошло успешно;     
		/// false - изменение невозможно/// </returns>
		bool OnLine();

		/////////РАБОТА С ЯЧЕЙКАМИ СОЗДАННЫМИ СИСТЕМОЙ////////

		/// <summary>
		/// возвращает иттератор списка ячеек с соответсвующей pos. 
		/// Если такого элемента не существует, возвращает end()
		/// </summary>
		std::list<CodeCell>::iterator find(Point pos);

		/// <summary>
		/// возвращает иттератор списка команд с соответсвующей command. 
		/// Если такого элемента не существует, возвращает end()
		/// </summary>
		std::list<std::string>::iterator find(std::string* command);

	public:
		UserCode();
		UserCode(std::list<std::string> commands_);
		void Initialize();
		void Initialize(std::list<std::string> commands_);
		/// <summary>
		/// заполнение массива codeCells по правилам форматирования
		/// </summary>
		/// <returns>
		/// true - форматирование прошло успешно;     
		/// false - ошибка форматирования/// </returns>
		bool Format();

		/// <summary>
		/// импортирует команды из файла в массив commands
		/// </summary>
		/// <param name="map_out">для заполнения номера карты</param>
		/// <param name="fileName">значение по умолчанию, путь к кодам для лёгкого уровня сложности</param>
		/// <returns>
		/// true - импорт прошёл успешно;            
		/// false - импорт не произведен </returns>
		bool Import(Maze& map_out, std::string fileName = "database\\code\\code.txt", int mapNumber = -1);
		/// <summary>
		/// экспортирует команды в файл с именем fileName
		/// </summary>
		/// <returns>
		/// true - экспорт прошёл успешно;            
		/// false - экспорт не произведен</returns>
		bool Export(Maze& map, std::string fileName);

		/// <summary>
		/// очищает clipboard и заполняет строкой commands_
		/// </summary>
		void Copy(std::list<std::string> commands_);

		/// <summary>
		/// добавляет команды из буфера обмена в поле для кода (с применением форматирования)
		/// </summary>
		/// <param name="pos">позиция первой из добавляемых команд</param>
		/// <returns>
		/// true - операция успешно завершена;      
		/// false - операция завершилась ошибкой</returns>
		bool Paste(Point pos);

		/// <returns>
		/// true - буфер обмена пуст;      
		/// false - буфер обмена содержит команды</returns>
		bool isClipboardEmpty();

		////////////GET////////////

		int getWightSize();
		int getHeightSize();
		std::list<CodeCell> getCodeCells();
		std::list<std::string>* getCommands();
	};
}