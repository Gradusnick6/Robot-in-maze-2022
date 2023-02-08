#include "GameMaster.h"
using namespace front;
using namespace backend;

int GameMaster::status = GS_MAIN_MENU;
Maze GameMaster::map;
Robot GameMaster::robot;
UserCode GameMaster::uCode;

std::string GameMaster::getCommand(int input)
{
	switch (input)
	{
	case UC_UP: return UP_STRING;
	case UC_DOWN: return DOWN_STRING;
	case UC_LEFT: return LEFT_STRING;
	case UC_RIGHT: return RIGHT_STRING;
	case UC_IF: return IF_STRING;
	case UC_ELSE: return ELSE_STRING;
	case UC_WHILE: return WHILE_STRING;
	case UC_END: return END_STRING;
	case UC_THEN: return THEN_STRING;
	case UC_IUP: return IUP_STRING;
	case UC_ILEFT: return ILEFT_STRING;
	case UC_IRIGHT: return IRIGHT_STRING;
	case UC_IDOWN: return IDOWN_STRING;
	case UC_BARRIER: return BARRIER_STRING;
	case UC_LOOSE: return LOOSE_STRING;
	case UC_OR: return OR_STRING;
	case UC_AND: return AND_STRING;
	default: return "";
	}
}


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
	std::list<CodeCell>::iterator iter = uCode.getCodeCells().end();
	Point lastPos = uCode.getCodeCells().empty() ? Point(0, -3) :(--iter)->getPos();

	status = GS_INTERPRETER;
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
		if (input >= UC_UP && input <= UC_AND)
		{
			if (lastPos.y + 3 >= uCode.getWightSize())
				lastPos.setPoint(lastPos.x + 1, 0);
			else
				lastPos.setPoint(lastPos.x, lastPos.y + 3);
			uCode.AddCommand(lastPos, getCommand(input));
			continue;
		}
		switch (input)
		{
		case UC_DELETE_LAST_WORD: uCode.DeleteCommand(uCode.getCommands()->size() - 1); break;
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
	std::list<std::string>* l = uCode.getCommands();
	if (inter.Initialize(l))
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
	status = GS_USER_CODE;
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
		case UC_IMPORT_CODE: uCode.Import(map, "database\\code\\test.txt"); break;
		case UC_EXPORT_CODE: uCode.Export(map, "database\\trash\\trash.txt"); break;
		case UC_DELETE_WORD: DeleteCommand();  break;
		case UC_DELETE_ALL: uCode.ClearCommands(); break;
		case UC_ADD_WORD: AddCommand(); break;
		case UC_MOVE_WORD: MoveCommand(); break;
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
	std::cout << "\n\n¬ведите индексы позиции, в которую нужно вставить команды из буфера:";
	Point p = ScanPoint();
	return uCode.Paste(p);
}

bool GameMaster::AddCommand()
{
	int inputCommand;
	std::cout << std::endl << std::endl;
	DrawFunctions::PrintCommands_UC();
	std::cout << "\n¬ведите номер команды: ";
	std::cin >> inputCommand;
	std::cout << "\n¬ведите индексы позиции, в которую нужно добавить команду:";
	return uCode.AddCommand(ScanPoint(), getCommand(inputCommand)) != uCode.getCodeCellsEnd();
}

bool GameMaster::DeleteCommand()
{
	int inputCommand;
	std::cout << "\n\n¬ведите номер удал€емой команды: ";
	std::cin >> inputCommand;
	return uCode.DeleteCommand(inputCommand);
}

bool GameMaster::MoveCommand()
{
	int inputCommand;
	std::cout << "\n¬ведите номер перемещаемой команды: ";
	std::cin >> inputCommand;
	std::cout << "\n¬ведите индексы позиции, в которую нужно переместить команду:";
	return uCode.MoveCommand(inputCommand, ScanPoint());
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
	ProcUserCode();
}