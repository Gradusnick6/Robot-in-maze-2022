#include "CodeCell.h"
using namespace userCodeBack;
using namespace commonBack;

CodeCell::CodeCell()
{
	command = nullptr;
	pos.setPoint(-1, -1);
	paragraph = 0;
	muted = false;
	fantom = false;
}

CodeCell::CodeCell(std::string* command_, Point pos_, int paragraph_, bool mute, bool fantom_) {
	Initialize(command_, pos_, paragraph_, mute, fantom_);
}

void CodeCell::Initialize(std::string* command_, Point pos_, int paragraph_, bool mute, bool fantom_)
{
	command = command_;
	pos = pos_;
	paragraph = paragraph_;
	muted = mute;
	fantom = fantom_;
}

bool CodeCell::setPos(Point pos_)
{
	if (!muted)
		pos = pos_;
	return !muted;
}

bool CodeCell::setCommand(std::string* command_)
{
	if (!muted)
		command = command_;
	return !muted;
}

Point CodeCell::Shift(int x_offset, int y_offset)
{
	pos.setPoint(pos.x + x_offset, pos.y + y_offset);
	return pos;
}

bool CodeCell::isMuted() { return muted; }

Point CodeCell::getPos() { return pos; }

std::string* CodeCell::getCommand() { return command; }

int CodeCell::getParagraph() { return paragraph; }

CodeCell CodeCell::operator=(CodeCell other)
{
	command = other.command;
	pos = other.pos;
	paragraph = other.paragraph;
	muted = other.muted;
	fantom = other.fantom;
	return *this;
}

bool CodeCell::operator >(CodeCell other)
{
	Point pO = other.getPos();
	return pos.x > pO.x || pos.x == pO.x && pos.y > pO.y;
}

bool CodeCell::operator <(CodeCell other)
{
	Point pO = other.getPos();
	return pos.x < pO.x || pos.x == pO.x && pos.y < pO.y;
}

bool CodeCell::operator ==(CodeCell other)
{
	Point pO = other.getPos();
	return pos.x == pO.x && pos.y == pO.y;
}