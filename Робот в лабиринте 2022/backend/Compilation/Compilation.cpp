#include "Compilation.h"
using namespace programming;
using namespace mapBack;

bool Compilation::isRoute(std::string command)
{
	return command == IUP_STRING || command == IDOWN_STRING || 
		command == ILEFT_STRING || command == IRIGHT_STRING;
}

bool Compilation::isLogicOperator(std::string command)
{
	return command == AND_STRING || command == OR_STRING;
}

bool Compilation::isStep(std::string command)
{
	return command == UP_STRING || command == DOWN_STRING || 
		command == LEFT_STRING || command == RIGHT_STRING;
}

bool Compilation::isIfOrWhile(std::string command)
{
	return command == WHILE_STRING || command == IF_STRING;
}

bool Compilation::isEndOrElse(std::string command)
{
	return command == END_STRING || command == ELSE_STRING;
}

bool Compilation::isBarrier(std::string command)
{
	return command == LOOSE_STRING || command == BARRIER_STRING;
}

bool Compilation::isOperation(std::string command)
{
	return isStep(command) || isIfOrWhile(command) || isEndOrElse(command);
}

bool Compilation::CheckSpellingCondition(std::vector<std::string*> commands, int index)
{
	index++;
	if (index == commands.size())
		return false;
	while (*commands[index] != THEN_STRING)
	{
		if (index + 2 >= commands.size()) 
			return false;

		if (isRoute(*commands[index]))
			index++;
		else
			return false;

		if (isBarrier(*commands[index]))
			index++;
		else
			return false;

		if (*commands[index] == THEN_STRING)
			{ index++; break; }

		if (isLogicOperator(*commands[index]))
			index++;
		else
			return false;
	}
	return true;
}

bool Compilation::CheckCondition(std::vector<std::string*> commands, int& index_out, MapCell cell)
{
	bool condition = false;
	int iPtr = index_out;
	bool curCondition;
	while (*commands[iPtr] != THEN_STRING)
	{
		iPtr++;
		curCondition = CheckPartCondition(*commands[iPtr], *commands[iPtr + 1], cell);
		// если это не первая часть условия
		if (isLogicOperator(*commands[iPtr - 1]))
			if (*commands[iPtr - 1] == AND_STRING)
				condition = condition && curCondition;
			else 
				condition = condition || curCondition;
		else 
			condition = curCondition;
		iPtr += 2;
	}

	index_out = iPtr + 1;
	return condition;
}

bool Compilation::CheckPartCondition(std::string route, std::string barrier, MapCell cell)
{
	bool isWall = barrier == BARRIER_STRING;

	if (route == ILEFT_STRING) return cell.leftWall == isWall;
	if (route == IUP_STRING) return cell.upWall == isWall;
	if (route == IRIGHT_STRING) return cell.rightWall == isWall;
	if (route == IDOWN_STRING) return cell.downWall == isWall;
	return false;
}