#include "DrawFunctions.h"
using namespace backend;

std::string front::DrawFunctions::Upper(std::string str)
{
    std::string result = "";
    for (int i = 0; i < str.size(); i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            result.push_back((char)str[i] - 'a' + 'A');
        else
            result.push_back(str[i]);
    return result;
}

std::string front::DrawFunctions::getRusCommand(int input)
{
    switch (input)
    {
    case UC_UP: return UP_UP_RUS_STRING;
    case UC_DOWN: return DOWN_UP_RUS_STRING;
    case UC_LEFT: return LEFT_UP_RUS_STRING;
    case UC_RIGHT: return RIGHT_UP_RUS_STRING;
    case UC_IF: return IF_UP_RUS_STRING;
    case UC_ELSE: return ELSE_UP_RUS_STRING;
    case UC_WHILE: return WHILE_UP_RUS_STRING;
    case UC_END: return END_UP_RUS_STRING;
    case UC_THEN: return THEN_UP_RUS_STRING;
    case UC_IUP: return IUP_UP_RUS_STRING;
    case UC_ILEFT: return ILEFT_UP_RUS_STRING;
    case UC_IRIGHT: return IRIGHT_UP_RUS_STRING;
    case UC_IDOWN: return IDOWN_UP_RUS_STRING;
    case UC_BARRIER: return BARRIER_UP_RUS_STRING;
    case UC_LOOSE: return LOOSE_UP_RUS_STRING;
    case UC_OR: return OR_UP_RUS_STRING;
    case UC_AND: return AND_UP_RUS_STRING;
    default: return "";
    }
}

void front::DrawFunctions::PrintSpace(int count)
{
    for (int i = 0; i < count; i++)
    std::cout << " ";
}




void front::DrawFunctions::PrintMainMenu()
{
    std::cout << UC_MAZE_ROBOT << ": ������������ ��������� � ������\n";
    std::cout << UC_INTERPRETER << ": ������������ ��������������\n";
    std::cout << UC_USER_CODE << ": ������������ ����������������� ����\n";
    std::cout << std::endl << UC_EXIT << ": �����\n";
}

void front::DrawFunctions::PrintExit_UC()
{
    std::cout << UC_MAIN_MENU << ": ��������� � ����\n";
    std::cout << UC_EXIT << ": �����\n\n";
}

void front::DrawFunctions::PrintMazeRobot_UC()
{
    std::cout << "������� ���:";
    std::cout << "\n�����:" << RS_UP;
    std::cout << "\n����:" << RS_DOWN;
    std::cout << "\n�����: " << RS_LEFT;
    std::cout << "\n������: " << RS_RIGHT;
}

void front::DrawFunctions::PrintInterpreter_UC()
{
    std::cout << UC_DELETE_LAST_WORD << ". " << "������� ��������� �����" << std::endl;
    std::cout << UC_RUN << ". " << "��������� ������" << std::endl;

    std::string commandStr = "";
    std::cout << "\n������� ��� ������:" << std::endl;
    for (int i = UC_UP; i <= UC_AND; i++)
    {
        commandStr = i % 3 == 0 ? "\n" : "     ";
        std::cout << std::setw(10) << i << ". " << getRusCommand(i) << commandStr;
    }
}

void front::DrawFunctions::PrintUserCode_UC()
{
    std::cout << UC_IMPORT_CODE << ". " << "������������� ���\t\t";
    std::cout << UC_EXPORT_CODE << ". " << "�������������� ���" << std::endl;
    std::cout << UC_DELETE_WORD << ". " << "������� �������\t";
    std::cout << UC_ADD_WORD << ". " << "�������� �������\t";
    std::cout << UC_MOVE_WORD << ". " << "�������� ������ �������" << std::endl;
    std::cout << UC_COPY_WORDS << ". " << "����������� �������\t\t";
    std::cout << UC_PASTE_WORDS << ". " << "�������� �������" << std::endl;
    std::cout << UC_FORMAT_CODE << ". " << "������������� ���" << std::endl;
}



void front::DrawFunctions::DrawMaze(Maze& map, Robot robot, bool withStart, bool withFinish, bool withRobot)
{
    std::cout << "��������\n";
    int xRobot;
    int xStart;
    int xFinish;
    char temp;
    int size = map.getSize() * 2 + 1;
    for (int i = 0; i < size; i++)
    {
        xRobot = robot.getPos().x == i / 2 - 1 ? robot.getPos().x : -1;
        xStart = map.getStartPos().x == i / 2 - 1 ? map.getStartPos().x : -1;
        xFinish = map.getFinishPos().x == i / 2 - 1 ? map.getFinishPos().x : -1;
        if (i == 0)
        {
            for (int j = 0; j < map.getSize(); j++)
            {
                std::cout << '.';
                temp = map.getMapCell(i / 2, j).upWall ? '_' : ' ';
                std::cout << temp;
            }
            std::cout << ".\n";
            continue;
        }
        if (i % 2 == 0)
        {
            int index = i / 2 - 1;
            for (int j = 0; j < map.getSize(); j++)
            {
                std::cout << '.';
                if (xRobot != -1 && j == robot.getPos().y && withRobot)
                    temp = 'R';
                else
                    if (xFinish != -1 && j == map.getFinishPos().y && withFinish)
                        temp = 'F';
                    else
                        if (xStart != -1 && j == map.getStartPos().y && withStart)
                            temp = 'S';
                        else
                            temp = map.getMapCell(index, j).downWall ? '_' : ' ';
                std::cout << temp;
            }
            std::cout << ".\n";
            continue;
        }
        if (i % 2 == 1)
        {
            for (int j = 0; j < map.getSize(); j++)
            {
                temp = map.getMapCell(i / 2, j).leftWall ? '|' : ' ';
                std::cout << temp << ' ';
            }
            temp = map.getMapCell(i / 2, map.getSize() - 1).rightWall ? '|' : ' ';
            std::cout << temp;
            std::cout << "\n";
            continue;
        }
    }
}

void front::DrawFunctions::PrintResult(Maze& map, Robot robot)
{
    if (robot.isFinish(map))
    {
        DrawFunctions::DrawMaze(map, robot);
        std::cout << "\n����� ���������!!!\n";
    }
    else
        std::cout << "\n����� �������� :(\n";
    system("pause");
}

void front::DrawFunctions::PrintUserCode(UserCode& uCode, int iCommand, int countActiveCommand)
{
    if (uCode.getCodeCells().empty())
        return;
    int index = 0;
    int space = 6;
    //uCode.Format();
    std::list <CodeCell> cCell = uCode.getCodeCells();
    std::list<CodeCell>::iterator iter = cCell.begin();
    std::string command;
    for (int i = 0; i < uCode.getHeightSize(); i++)
    {
        for (int j = 0; j < uCode.getWightSize(); j++)
        {
            if (i == iter->getPos().x && j == iter->getPos().y)
            {
                command = index >= iCommand && index <= iCommand - countActiveCommand ? Upper(*iter->getCommand()) : *iter->getCommand();
                std::cout << command << "(" << index++<<")";
                if (index > 10)
                    space = 5;
                PrintSpace(space - (*iter->getCommand()).length());
                j += 2;
                iter++;
                if (iter == cCell.end())
                    return;
            }
            else
                std::cout << "|_|";
        }
        std::cout << std::endl;
    }
}

void front::DrawFunctions::PrintUserCode(UserCode& uCode)
{
    if (uCode.getCodeCells().empty())
        return;
    int index = 0;
    int space = 6;
    //uCode.Format();
    std::list <CodeCell> cCell = uCode.getCodeCells();
    std::list<CodeCell>::iterator iter = cCell.begin();
    for (int i = 0; i < uCode.getHeightSize(); i++)
    {
        for (int j = 0; j < uCode.getWightSize(); j++)
        {
            if (i == iter->getPos().x && j == iter->getPos().y)
            {
                std::cout << *iter->getCommand() << "(" << index++ << ")";
                if (index > 10)
                    space = 5;
                PrintSpace(space - (*iter->getCommand()).length());
                j += 2;
                iter++;
                if (iter == cCell.end())
                    return;
            }
            else
                std::cout << "|_|";
        }
        std::cout << std::endl;
    }
}