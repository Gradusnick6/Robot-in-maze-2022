#include "UserCode.h"
using namespace backend;
using namespace userCodeBack;
using namespace programming;

std::string UserCode::getRussianCommand(std::string command)
{
	if (command == UP_LOW_RUS_STRING || command == UP_UP_RUS_STRING) return UP_STRING;
	if (command == DOWN_LOW_RUS_STRING || command == DOWN_UP_RUS_STRING) return DOWN_STRING;
	if (command == LEFT_LOW_RUS_STRING || command == LEFT_UP_RUS_STRING) return LEFT_STRING;
	if (command == RIGHT_LOW_RUS_STRING || command == RIGHT_UP_RUS_STRING) return RIGHT_STRING;
	if (command == IF_LOW_RUS_STRING || command == IF_UP_RUS_STRING) return IF_STRING;
	if (command == ELSE_LOW_RUS_STRING || command == ELSE_UP_RUS_STRING) return ELSE_STRING;
	if (command == WHILE_LOW_RUS_STRING || command == WHILE_UP_RUS_STRING) return WHILE_STRING;
	if (command == END_LOW_RUS_STRING || command == END_UP_RUS_STRING) return END_STRING;
	if (command == THEN_LOW_RUS_STRING || command == THEN_UP_RUS_STRING) return THEN_STRING;
	if (command == IUP_LOW_RUS_STRING || command == IUP_UP_RUS_STRING) return IUP_STRING;
	if (command == IDOWN_LOW_RUS_STRING || command == IDOWN_UP_RUS_STRING) return IDOWN_STRING;
	if (command == ILEFT_LOW_RUS_STRING || command == ILEFT_UP_RUS_STRING) return ILEFT_STRING;
	if (command == IRIGHT_LOW_RUS_STRING || command == IRIGHT_UP_RUS_STRING) return IRIGHT_STRING;
	if (command == BARRIER_LOW_RUS_STRING || command == BARRIER_UP_RUS_STRING) return BARRIER_STRING;
	if (command == LOOSE_LOW_RUS_STRING || command == LOOSE_UP_RUS_STRING) return LOOSE_STRING;
	if (command == OR_LOW_RUS_STRING || command == OR_UP_RUS_STRING) return OR_STRING;
	if (command == AND_LOW_RUS_STRING || command == AND_UP_RUS_STRING) return AND_STRING;
	return command;
}

bool UserCode::isMaxParagraph() { return curParagraph > 0.4 * wSize; }

std::list<CodeCell>::iterator UserCode::AddCell(Point p, std::string* command, bool mute, bool fantom)
{
	CodeCell newCell(command, p, curParagraph, mute, fantom);
	if (codeCells.empty())
		return codeCells.insert(codeCells.end(), newCell);
	
	std::list<CodeCell>::iterator iter = getPrevCell(p);
	if (iter != codeCells.end())
		iter++;

	return codeCells.insert(iter, newCell);
}

std::list<CodeCell>::iterator UserCode::AddCommand(Point p, std::string command, bool mute, bool fantom)
{
	if (find(p) != codeCells.end())
		return codeCells.end();

	std::list<CodeCell>::iterator iterCell = getPrevCell(p);
	std::list<std::string>::iterator iterCommand;
	if (iterCell == codeCells.end())
	{
		commands.push_front(command);
		iterCommand = commands.begin();
	}
	else
		iterCommand = commands.insert(++find(iterCell->getCommand()), command);
	iterCell = AddCell(p, &*iterCommand, mute, fantom);
	if (iterCell == codeCells.end())
	{
		iterCommand->erase();
		return codeCells.end();
	}
	return iterCell;
}

bool UserCode::DeleteCommandsAfterPaste(std::list<CodeCell>::iterator lastCell, int countCell, std::list<std::string>::iterator firstCommand)
{
	for (int i = 0; i < countCell; lastCell--, i++)
		codeCells.erase(lastCell);
	for (int j = 0; j < clipboard.size(); j++, firstCommand++)
		commands.erase(firstCommand);
	return false;
}

std::list<CodeCell>::iterator UserCode::getPrevCell(Point pos)
{
	if (codeCells.empty())
		return codeCells.end();

	std::list<CodeCell>::iterator iter;
	for (int i = pos.x; i >= 0; i--)
		for (int j = i == pos.x ? pos.y - 1 : wSize; j >= 0; j--)
		{
			iter = find(Point(i, j));
			if (iter != codeCells.end())
				return iter;
		}
	return codeCells.end();
}

bool UserCode::FormatCurCommand(std::list<std::string>::iterator curCommand)
{
	if (!codeCells.empty())
	{
		std::list<CodeCell>::iterator cur = find(Point(lastHeight, lastWight));
		if (cur == codeCells.end())
			cur = getPrevCell(Point(lastHeight, lastWight));
		if (cur != codeCells.end())
			if (*cur->getCommand() == THEN_STRING || *cur->getCommand() == ELSE_STRING)
				return PrevElseThenFormat();
	}

	if (Compilation::isIfOrWhile(*curCommand))
		return IfWhileFormat();

	if (Compilation::isStep(*curCommand) || Compilation::isLogicOperator(*curCommand) || Compilation::isRoute(*curCommand) ||
		Compilation::isBarrier(*curCommand) || *curCommand == THEN_STRING)
		return OnLineFormat();

	if (*curCommand == ELSE_STRING || *curCommand == END_STRING)
		return ElseEndFormat();

	if (*curCommand == EMPTY_STRING)
		return EmptyFormat(curCommand);

	return false;
}

bool UserCode::ShiftCodeDown(std::list<CodeCell>::iterator firstCell, int countLine)
{
	if (firstCell == codeCells.end())
		return true;
	Point p;
	std::list<CodeCell>::iterator iter = firstCell--;
	for (; iter != codeCells.end(); iter++)
	{
		p = iter->Shift(countLine, 0);
		if (p.x >= hSize)
		{
			for (; iter != firstCell; iter--)
				p = iter->Shift(-countLine, 0);
			return false;
		}
	}
	return true;
}

int UserCode::getCountLine(int countCommands)
{
	int countLine = 1;
	int countOnLine = (wSize - curParagraph - lastWight) / standartStep;
	if (countOnLine >= countCommands)
		return countLine;
	countCommands -= countOnLine;
	countOnLine = (wSize - curParagraph) / standartStep;
	if (countOnLine == 0)
		return countCommands;
	else
		countLine += countCommands / countOnLine;
	if (countCommands % countOnLine != 0)
		countLine++;
	return countLine;
}

bool UserCode::PrevElseThenFormat() { return OnNewParagraph(PARAGRAPH_RIGHT); }

bool UserCode::IfWhileFormat() { return OnNewParagraph(); }

bool UserCode::OnLineFormat() { return OnLine();  }

bool UserCode::ElseEndFormat() { return OnNewParagraph(PARAGRAPH_LEFT); }

bool UserCode::EmptyFormat(std::list<std::string>::iterator curCommand)
{
	if (curCommand != commands.begin())
	{
		curCommand--;
		if (Compilation::isIfOrWhile(*curCommand) || Compilation::isLogicOperator(*curCommand)
			|| Compilation::isBarrier(*curCommand))
			return OnLine();

		if (*curCommand == THEN_STRING || *curCommand == ELSE_STRING)
			return OnNewParagraph(PARAGRAPH_RIGHT);

		if (*curCommand == END_STRING)
			return OnNewParagraph(PARAGRAPH_LEFT);

		if (curCommand != commands.end())
		{
			++curCommand++;
			if (Compilation::isLogicOperator(*curCommand) || *curCommand == THEN_STRING)
				return OnLine();
		}
	}
	return OnNewParagraph();
}

bool UserCode::OnNewParagraph(int typeParagraph)
{
	if (!codeCells.empty())
	{
		lastHeight++;
		if (lastHeight == hSize)
			return false;
		if (typeParagraph == PARAGRAPH_RIGHT)
		{
			if (!isMaxParagraph())
				curParagraph++;
		}
		if (typeParagraph == PARAGRAPH_LEFT)
		{
			if (curParagraph > 0)
				curParagraph--;
		}
	}
	lastWight = curParagraph;
	return true;
}

bool UserCode::OnLine()
{
	if (codeCells.empty())
		return true;
	if (lastWight + standartStep >= wSize - standartStep + 1)
	{
		lastHeight++;
		if (lastHeight == hSize)
			return false;
		lastWight = curParagraph;
	}
	else
		lastWight += standartStep;
	return true;
}

std::list<CodeCell>::iterator UserCode::find(Point pos)
{
	std::list<CodeCell>::iterator ptr = codeCells.begin();
	if (codeCells.empty() || ptr == codeCells.end())
		return codeCells.end();
	do
	{
		if (pos == ptr->getPos())
			return ptr;
		ptr++;
	} while (ptr != codeCells.end());
	return ptr;
}

std::list<std::string>::iterator UserCode::find(std::string* command)
{
	if (commands.empty())
		return commands.end();
	std::list<std::string>::iterator iter = commands.begin();
	do
	{
		if (command == &(*iter))
			return iter;
		iter++;
	} while (iter != commands.end());
	return iter;
}



UserCode::UserCode() { Initialize(); }

void UserCode::Initialize()
{
	curParagraph = 0;
	lastHeight = 0;
	lastWight = 0;
}

std::list<CodeCell>::iterator UserCode::AddCommand(Point p, std::string command) { return AddCommand(p, command, false, false); }

bool UserCode::DeleteCommand(std::string* command)
{
	std::list<std::string>::iterator iterCommand = find(command);
	if (iterCommand == commands.end())
		return false;

	std::list<CodeCell>::iterator iterCell = codeCells.end();
	for (std::list<CodeCell>::iterator ptr = codeCells.begin(); ptr != codeCells.end(); ptr++)
		if (ptr->getCommand() == command)
		{
			iterCell = ptr;
			break;
		}
	if (iterCell == codeCells.end())
		return false;
	if (iterCell->isMuted())
		return false;

	commands.erase(iterCommand);
	codeCells.erase(iterCell);
	return true;
}

bool UserCode::DeleteCommand(int index)
{
	if (index >= commands.size() || index < 0)
		return false;
	std::list<std::string>::iterator iterCommands = commands.begin();
	for (int i = 0; i != index; i++)
		iterCommands++;
	return DeleteCommand(&*iterCommands);
}

bool UserCode::MoveCommand(std::list<CodeCell>::iterator iterCell, Point newPos)
{
	CodeCell futureCell(nullptr, newPos, 0);
	if (iterCell == codeCells.end() || find(newPos) != codeCells.end())
		return false;
	if (iterCell->isMuted())
		return false;
	if (*iterCell == futureCell)
		return true;
	if (*iterCell > futureCell)
	{
		if (iterCell != codeCells.begin())
			if (*(--iterCell) < futureCell)
				return (++iterCell)->setPos(newPos);
		return iterCell->setPos(newPos);
	}
	else
		if (*iterCell < futureCell)
			if (*(++iterCell) > futureCell)
				return (--iterCell)->setPos(newPos);

	std::string newCommand = *iterCell->getCommand();
	DeleteCommand(iterCell->getCommand());
	AddCommand(newPos, newCommand);
	return true;
}

bool UserCode::MoveCommand(int index, Point newPos)
{
	if (find(newPos) != codeCells.end() || index >= commands.size() || index < 0)
		return false;
	std::list<CodeCell>::iterator iterCell = codeCells.begin();
	for (int i = 0; i != index; i++)
		iterCell++;
	return MoveCommand(iterCell, newPos);
}

void UserCode::ClearCommands()
{
	if (commands.empty() || codeCells.empty())
		return;
	std::list<CodeCell>::iterator iterCell = codeCells.begin(), deleteCell;
	std::list<std::string>::iterator iterCommand = commands.begin(), deleteCommand;
	for (; iterCommand != commands.end(); iterCell++, iterCommand++)
		if (!iterCell->isMuted())
		{
			deleteCell = iterCell--;
			deleteCommand = iterCommand--;
			commands.erase(deleteCommand);
			codeCells.erase(deleteCell);
		}
}





bool UserCode::Format()
{
	lastHeight = lastWight = curParagraph = 0;
	std::list<CodeCell>::iterator iterCell = codeCells.begin();
	std::list<std::string>::iterator iterCommand = commands.begin();
	Point p;
	for (; iterCell != codeCells.end(); iterCell++, iterCommand++)
	{
		if (!iterCell->isMuted())
		{
			if (FormatCurCommand(iterCommand))
			{
				p = Point(lastHeight, lastWight);
				CodeCell futureCell(nullptr, p, 0);
				if (find(p) == codeCells.end() && *(++iterCell) > futureCell)
					(--iterCell)->setPos(p);
				else
					--iterCell;
			}
			else
				return false;
		}
		else
		{
			lastHeight = iterCell->getPos().x;
			lastWight = iterCell->getPos().y;
			curParagraph = iterCell->getParagraph();
		}
	}
	return true;
}

bool UserCode::Import(Maze& map_out, std::string fileName, int mapNumber)
{
	if (!fileName.empty())
		if (!FileReader::isWithTxt(fileName))
			fileName += ".txt";
	std::ifstream file(fileName);
	if (!file) return false;

	commands.clear();
	codeCells.clear();

	if (mapNumber != -1)
	{
		FileReader::findMapOnFile(file, mapNumber);
		map_out.setNumber(mapNumber);
	}
	std::string buf;
	int brk = 0;
	lastHeight = lastWight = curParagraph = 0;
	file >> buf;
	commands.push_back(buf);
	std::list<std::string>::iterator iterCommand = commands.begin();
	FormatCurCommand(iterCommand);
	AddCell(Point(lastHeight, lastWight), &*iterCommand, true, false);
	do
	{
		file >> buf;
		if (buf == STOP_WORD) break;
		if (brk++ == 1000){
			file.close();
			return false;
		}
		commands.push_back(buf);
		iterCommand++;
		FormatCurCommand(iterCommand);
		AddCell(Point(lastHeight, lastWight), &*iterCommand, true, false);
	} while (true);

	file.close();
	return true;
}

bool UserCode::Export(Maze& map, std::string fileName)
{
	if (commands.empty()) return false;
	if (!FileReader::isWithTxt(fileName))
		fileName += ".txt";
	std::ofstream file(fileName);

	if (!file) return false;

	file << map.getNumber() << std::endl;

	for (std::list<std::string>::iterator i = commands.begin(); i != commands.end(); i++)
		file << *i << "\n";
	file << "\n" << STOP_WORD;

	file.close();
	return true;
}

void UserCode::Copy(std::list<std::string> commands_)
{
	clipboard.clear();
	clipboard = commands_;
}

bool UserCode::Paste(Point pos)
{
	if (find(pos) != codeCells.end() || clipboard.empty())
		return false;
	std::list<CodeCell>::iterator prevCells = getPrevCell(pos);
	std::string* prevCommand = prevCells->getCommand();
	std::list<std::string>::iterator iCommands = commands.insert(++find(prevCommand), clipboard.begin(), clipboard.end());
	if (prevCells != codeCells.end())
	{
		curParagraph = prevCells->getParagraph();
		if (*prevCommand == THEN_STRING || *prevCommand == ELSE_STRING || !isMaxParagraph())
			curParagraph++;
		if (*clipboard.begin() == END_STRING || curParagraph > 0)
			curParagraph--;
	}
	else curParagraph = 0;

	lastHeight = pos.x; lastWight = pos.y;
	std::list<CodeCell>::iterator oldCells = AddCell(Point(lastHeight, lastWight), &(*iCommands++), false, false);
	if (++oldCells == codeCells.end())// вставка в конец списка
	{
		for (int i = 1; i < clipboard.size(); i++, iCommands++)
			if (FormatCurCommand(iCommands))
				AddCell(Point(lastHeight, lastWight), &(*iCommands), false, false);
			else
				return DeleteCommandsAfterPaste(--oldCells, i - 1, ++find(prevCommand));
		return true;
	}
	// вставка в начало-середину списка
	int oneDimensPos_Old = oldCells->getPos().x * wSize + oldCells->getPos().y;
	for (int i = 1; i < clipboard.size(); i++, iCommands++)
	{
		if (FormatCurCommand(iCommands))
		{
			if (oneDimensPos_Old <= lastHeight * wSize + lastWight)
				if (!ShiftCodeDown(oldCells, getCountLine((int) clipboard.size() - i)))
					return DeleteCommandsAfterPaste(--oldCells, i, ++find(prevCommand));
			AddCell(Point(lastHeight, lastWight), &(*iCommands), false, false);
		}
		else
			return DeleteCommandsAfterPaste(--oldCells, i, ++find(prevCommand));
	}
	return true;
}


bool UserCode::isClipboardEmpty() { return clipboard.empty(); }


int UserCode::getWightSize() { return wSize; }

int UserCode::getHeightSize() { return hSize; }

std::list<CodeCell>::iterator UserCode::getCodeCellsEnd() { return codeCells.end(); }

std::list<CodeCell> UserCode::getCodeCells() { return codeCells; }

std::list<std::string>* UserCode::getCommands() { return &commands; }