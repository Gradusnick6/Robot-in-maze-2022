#include "GameMaster.h"
using namespace front;
using namespace backend;

int GameMaster::status = GS_MAIN_MENU;
Maze GameMaster::map;
Robot GameMaster::robot;
UserCode GameMaster::uCode;

void GameMaster::ProcMainMenu()
{
	system("cls");
	status = GS_MAIN_MENU;
	DrawFunctions::PrintMainMenu();
	std::cout << "¬ведите команду: ";
	int input;
	std::cin >> input;
	switch (input)
	{
	case UC_MAZE_ROBOT: { status = GS_MAZE_ROBOT; ProcMazeRobot(); break; }
	case UC_INTERPRETER: { status = GS_INTERPRETER; ProcInterpreter(); break; }
	case UC_USER_CODE: { status = GS_USER_CODE; ProcUserCode(); break; }
	case UC_EXIT: return;
	default: ProcMainMenu();
	}
}

void GameMaster::ProcMazeRobot()
{
	int input = UC_MAIN_MENU;
	while (!robot.isFinish(map))
	{
		system("cls");
		DrawFunctions::PrintExit_UC();
		DrawFunctions::DrawMaze(map, robot);
		DrawFunctions::PrintMazeRobot_UC();
		std::cout << "\n¬ведите число: ";
		std::cin >> input;
		if (input < 1 || input > 4)
			if (!robot.MakeStep(map, input))
				break;
	}
	system("cls");
	if (input >= 1 && input <= 4)
		front::DrawFunctions::PrintResult(map, robot);
	if (input == UC_MAIN_MENU)
		ProcMainMenu();
}

void GameMaster::ProcInterpreter()
{
	int input = UC_MAIN_MENU;
	while (status == GS_INTERPRETER)
	{
		system("cls");
		DrawFunctions::PrintExit_UC();
		DrawFunctions::DrawMaze(map, robot);
		DrawFunctions::PrintInterpreter_UC();
		std::cout << "\n¬аша программа:\n";
		DrawFunctions::PrintUserCode(uCode);
		std::cout << "\n¬ведите число: ";
		std::cin >> input;
		if (isExitCommands(input))
			break;
		switch (input)
		{
		case UC_DELETE_LAST_WORD: break;
		case UC_RUN: ProcRobotRun(); break;
		}	
	}
	if (input == UC_MAIN_MENU)
		ProcMainMenu();
}

void GameMaster::ProcRobotRun()
{
	system("cls");
	uCode.Initialize();
	Interpreter inter;
	std::list<std::string>* vec = uCode.getCommands();
	if (inter.Initialize(vec))
	{
		DrawFunctions::PrintUserCode(uCode);
		int trash = 0;
		while (!inter.isEndComamnds())
		{
			if (trash == 1000)
				break;
			system("cls");
			DrawFunctions::DrawMaze(map, robot);
			if (!inter.ProcCommand(map, robot))
				break;
			DrawFunctions::PrintUserCode(uCode, inter.getIndexLastCommand(), inter.getCountActiveCommand());
			std::cout << "\n¬ведите 1000, чтобы завершить (или любое другое число, чтобы продолжить) - ";
			std::cin >> trash;
		}
	}
	Sleep(700);
	status = GS_INTERPRETER;

	system("cls");
	front::DrawFunctions::PrintResult(map, robot);
}

void GameMaster::ProcUserCode()
{
	int input = UC_MAIN_MENU;
	while (status == GS_USER_CODE)
	{
		system("cls");
		DrawFunctions::PrintExit_UC();
		DrawFunctions::DrawMaze(map, robot);
		DrawFunctions::PrintUserCode_UC();
		std::cout << "\n¬аша программа:\n";
		DrawFunctions::PrintUserCode(uCode);
		std::cout << "\n¬ведите число: ";
		std::cin >> input;
		if (isExitCommands(input))
			break;
		switch (input)
		{
		case UC_IMPORT_CODE: { uCode.Import(map, "database\\code\\test.txt"); uCode.Format(); break; }
		case UC_EXPORT_CODE: uCode.Export(map, "database\\trash\\trash.txt"); break;
		case UC_DELETE_WORD: break;
		case UC_ADD_WORD: break;
		case UC_MOVE_WORD: break;
		case UC_COPY_WORDS: CopyCommands(); break;
		case UC_PASTE_WORDS: PasteCommands(); break;
		case UC_FORMAT_CODE: uCode.Format(); break;
		}
	}
	if (input == UC_MAIN_MENU)
		ProcMainMenu();
}



bool GameMaster::CopyCommands()
{
	int first, second;
	std::cout << "\n\n¬ведите индекс первой копируемой команды: ";
	std::cin >> first;

	std::cout << "\n\n¬ведите индекс последней копируемой команды: ";
	std::cin >> second;

	if (first < 0 || first >= uCode.getCommands()->size() || second < 0 || second >= uCode.getCommands()->size())
		return false;
	if (first > second)
		std::swap(first, second);

	std::list<std::string> l;
	std::list<std::string> commands = *uCode.getCommands();
	std::list<std::string>::iterator iter = commands.begin();
	for (int i = 0; i < first; i++)
		iter++;
	for (; first <= second; first++, iter++)
		l.push_back(*iter);
	uCode.Copy(l);
	return true;
}

bool GameMaster::PasteCommands()
{
	int x, y;
	std::cout << "\n\n¬ведите индексы позиции, в которую нужно вставить команды из буфера:";
	Point p = ScanPoint();
	return uCode.Paste(p);
}

Point GameMaster::ScanPoint()
{
	int x, y;
	std::cout << "\nx: ";
	std::cin >> x;
	std::cout << "\ny: ";
	std::cin >> y;
	return Point(x, y);
}

bool GameMaster::isExitCommands(int input)
{
	switch (input)
	{
	case UC_MAIN_MENU: status = GS_MAIN_MENU; return true;
	case UC_EXIT: status = GS_EXIT; return true;
	}
	return false;
}



void GameMaster::ProcApp()
{
	map.Initialize(3, 1);
	robot.Initialize(map.getStartPos());
	ProcMainMenu();
}