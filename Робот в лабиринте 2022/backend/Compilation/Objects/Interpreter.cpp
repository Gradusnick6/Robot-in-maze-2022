#include "Interpreter.h"
using namespace programming;
using namespace backend;

TypeOperation Interpreter::getCurOperation()
{
	if (*cLine.commands[iCommand] == UP_STRING) return TypeOperation::TO_UP;
	else if (*cLine.commands[iCommand] == DOWN_STRING) return TypeOperation::TO_DOWN;
	else if (*cLine.commands[iCommand] == LEFT_STRING) return TypeOperation::TO_LEFT;
	else if (*cLine.commands[iCommand] == RIGHT_STRING) return TypeOperation::TO_RIGHT;
	else if (*cLine.commands[iCommand] == IF_STRING) return TypeOperation::TO_IF;
	else if (*cLine.commands[iCommand] == ELSE_STRING) return TypeOperation::TO_ELSE;
	else if (*cLine.commands[iCommand] == WHILE_STRING) return TypeOperation::TO_WHILE;
	else if (*cLine.commands[iCommand] == END_STRING) return TypeOperation::TO_END;
	else return TypeOperation::TO_ERROR;
}

bool Interpreter::isEndComamnds() { return iCommand >= cLine.length();  }

int Interpreter::getIndex(std::vector <int> array, int value)
{
	for (int i = 0; i < array.size(); i++)
		if (value == array[i]) 
			return i;
	return -1;
}

int Interpreter::findPrevCommand(std::string command)
{
	for (int i = iCommand - 1; i >= 0; i--)
		if (*(cLine.commands[i]) == command)
			return i;
	return -1;
}

bool Interpreter::MakeStep(bool route)
{
	if (route)
		iCommand++;
	else
		return ProcError(ERROR_IN_LOGIC);
	return true;
}


Interpreter::Interpreter()
{
	iCommand = 0;
	countActiveCommand = 0;
	elseLock = true;
	iLastCommand = 0;
}

bool Interpreter::Initialize(std::list<std::string>* commands_)
{
	std::vector<std::string*> commandsVec;
	for (std::list<std::string>::iterator ptr = commands_->begin(); ptr != commands_->end(); ptr++)
		commandsVec.push_back(&(*ptr));
	iCommand = 0;
	iLastCommand = 0;
	countActiveCommand = 0;
	elseLock = true;
	cLine.Initialize(commandsVec);
	return cLine.PrimaryCompilation();
}

bool Interpreter::ProcCommand(Maze& map, Robot& robot)
{
	if (!cLine.isNULL())
	{
		iLastCommand = iCommand;
		countActiveCommand = 0;
		TypeOperation typeOp = getCurOperation();
		if (!isEndComamnds())
		{
			switch (typeOp)
			{
			case TypeOperation::TO_UP: return MakeStep(robot.MakeStep(map, RS_UP));
			case TypeOperation::TO_DOWN: return MakeStep(robot.MakeStep(map, RS_DOWN));
			case TypeOperation::TO_LEFT: return MakeStep(robot.MakeStep(map, RS_LEFT));
			case TypeOperation::TO_RIGHT: return MakeStep(robot.MakeStep(map, RS_RIGHT));

			case TypeOperation::TO_IF: return ProcIfOperator(map, robot);
			case TypeOperation::TO_ELSE: return ProcElseOperator();
			case TypeOperation::TO_WHILE: return ProcWhileOperator(map, robot);
			case TypeOperation::TO_END: return ProcEndOperator();

			case TypeOperation::TO_ERROR: return ProcError(ERROR_IN_CODE);
			}
		}
	}
	return false;
}

bool Interpreter::ProcIfOperator(Maze& map, Robot& robot)
{
	if (Compilation::CheckSpellingCondition(cLine.commands, iCommand))
	{
		endsActive.push(true);
		countActiveCommand = iCommand;

		MapCell mCell = map.getMapCell(robot.getPos().x, robot.getPos().y);
		if (Compilation::CheckCondition(cLine.commands, iCommand, mCell))
		{
			if (Compilation::isStep(*cLine.commands[iCommand]) || Compilation::isIfOrWhile(*cLine.commands[iCommand]))
			{
				++countActiveCommand -= iCommand;
				return true;
			}
			else
				return ProcError(ERROR_IN_CODE);
		}
		else
		{
			int prevIf = findPrevCommand(IF_STRING);
			if (prevIf == -1)
				return ProcError(ERROR_IN_CODE);

			int NextCommand; 
			int prevOperator = getIndex(cLine.iWhileIfCommand, prevIf);
			if (prevOperator == -1) return ProcError(ERROR_IN_CODE);
			if (cLine.iElseCommand[prevOperator] != -1)
				NextCommand = cLine.iElseCommand[prevOperator];
			else
				NextCommand = cLine.iEndCommand[prevOperator];

			do {
				iCommand++;
				// проверка на отсутсвие оператора End для применяемого If в коде пользователя
				if (iCommand == cLine.length())
					return ProcError(ERROR_IN_CODE);
				// проверка на наличие Else после условия
				if (*cLine.commands[iCommand] == ELSE_STRING)
				{
					elseLock = false;
					break;
				}
			} while (iCommand != NextCommand);
		}
		++countActiveCommand -= iCommand;
		return true;
	}
	else return ProcError(ERROR_IN_CODE);
}

bool Interpreter::ProcElseOperator()
{
	if (cLine.iEndCommand.size() != 0)
	{
		if (elseLock)
		{
			int prevIf = findPrevCommand(IF_STRING);
			int ifIndex = getIndex(cLine.iWhileIfCommand, prevIf);
			if (ifIndex == -1) return ProcError(ERROR_IN_CODE);
			int nextCommand = cLine.iEndCommand[ifIndex];
			do {
				iCommand++;

				if (iCommand == cLine.length())
					return ProcError(ERROR_IN_CODE);
			} while (iCommand != nextCommand);
		}
		else
		{
			iCommand++;
			elseLock = true;
		}
		return true;
	}
	return false;
}

bool Interpreter::ProcWhileOperator(Maze& map, Robot& robot)
{
	if (Compilation::CheckSpellingCondition(cLine.commands, iCommand))
	{
		countActiveCommand = iCommand;
		//если это первое вхождение
		if (getTop(whileActiveIndexes) != iCommand)
		{
			whileActiveIndexes.push(iCommand);
			endsActive.push(false);
			whileLock.push(false);
		}

		MapCell mCell = map.getMapCell(robot.getPos().x, robot.getPos().y);
		if (Compilation::CheckCondition(cLine.commands, iCommand, mCell))
		{
			whileLock.top() = true;

			if (Compilation::isStep(*cLine.commands[iCommand]) || Compilation::isIfOrWhile(*cLine.commands[iCommand]))
			{
				++countActiveCommand -= iCommand;
				return true;
			}
			else 
				return ProcError(ERROR_IN_CODE);
		}
		else
		{
			whileLock.top() = false;

			int prevWhile = findPrevCommand(WHILE_STRING);
			if (prevWhile == -1)
				return ProcError(ERROR_IN_CODE);

			int endIndex = getIndex(cLine.iWhileIfCommand, prevWhile);
			if (endIndex == -1) return ProcError(ERROR_IN_CODE);
			while (iCommand != cLine.iEndCommand[endIndex])
			{
				iCommand++;
				if (iCommand == cLine.length())
					return ProcError(ERROR_IN_CODE);
			}
		}
		++countActiveCommand -= iCommand;
		return true;
	}
	else 
		return ProcError(ERROR_IN_CODE);
}

bool Interpreter::ProcEndOperator()
{
	if (!endsActive.empty())
	{
		if (endsActive.top())//конец if оператора
		{
			endsActive.pop();
			iCommand++;
			return true;
		}
		else //конец while оператора
		{
			if (whileLock.top())//while продолжается
			{
				int endIndex = getIndex(cLine.iEndCommand, iCommand);
				if(endIndex == -1) return ProcError(ERROR_IN_CODE);
				do { iCommand--; } while (iCommand != cLine.iWhileIfCommand[endIndex]);
				return true;
			}
			else//while завершается
			{
				whileActiveIndexes.pop();
				endsActive.pop();
				whileLock.pop();
				iCommand++;
				return true;
			}
		}
	}
	else 
		return ProcError(ERROR_IN_CODE);
}

bool Interpreter::ProcError(int typeError)
{
	error.iErrorWord = iCommand;
	iCommand = cLine.length();
	error.typeError = typeError;
	return false;
}

int Interpreter::getTop(std::stack <int> s)
{
	if (s.empty())
		return -1;
	return s.top();
}



int Interpreter::getCountActiveCommand() { return countActiveCommand; }

int Interpreter::getIndexCurrentCommand() { return iCommand; }

int Interpreter::getIndexLastCommand() { return iLastCommand; }
