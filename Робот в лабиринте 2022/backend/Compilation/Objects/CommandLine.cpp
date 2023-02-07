#include "CommandLine.h"
using namespace programming;

void CommandLine::FillIndexVectors()
{
	for (int i = commands.size() - 1; i >= 0; i--)
		if (*(commands[i]) == WHILE_STRING || *(commands[i]) == IF_STRING)
		{
			iWhileIfCommand.push_back(i);

			for (int j = i; j < commands.size(); j++)
			{
				if (*(commands[j]) == ELSE_STRING && !find(iElseCommand, j))
					iElseCommand.push_back(j);

				if (*(commands[j]) == END_STRING && !find(iEndCommand, j))
				{
					iEndCommand.push_back(j);
					if (iElseCommand.size() < iEndCommand.size()) iElseCommand.push_back(-1);
					break;
				}
			}
		}
}

bool CommandLine::find(std::vector<int> array, int value)
{
	for (int i = 0; i < array.size(); i++)
		if (value == array[i])
			return true;
	return false;
}

CommandLine::CommandLine(){	}

CommandLine::CommandLine(std::vector<std::string*> commands_){ Initialize(commands_); }

void CommandLine::Initialize(std::vector<std::string*> commands_)
{
	commands = commands_;

	if (!iEndCommand.empty()) iEndCommand.clear();
	if (!iWhileIfCommand.empty()) iWhileIfCommand.clear();
	if (!iElseCommand.empty()) iElseCommand.clear();

	FillIndexVectors();
}

bool CommandLine::isNULL(){ return commands.size() == 0; }

bool CommandLine::PrimaryCompilation(){ return iEndCommand.size() == iWhileIfCommand.size(); }

int CommandLine::length() { return commands.size(); }