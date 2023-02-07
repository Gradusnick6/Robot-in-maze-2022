#include "Maze.h"
using namespace mapBack;
using namespace backend;

void Maze::clearMap()
{
	if (map != nullptr)
	{
		for (int i = 0; i < size; i++)
			delete[] map[i];
		delete[] map;
		map = nullptr;
	}
}

bool Maze::getMapCount(int levelDifficulty, int& mapCount_out)
{
	mapCount_out = 0;
	std::string fileName = PATH_TO_MAPS + FileReader::getDetermDifficult(levelDifficulty);
	std::ifstream file(fileName);
	if (!file)
	{
		file.close();
		return false;
	}

	file.seekg(0, std::ios::beg);
	std::string ptr;
	do {
		do
		{
			if (file.eof()) break;

			file >> ptr;
		} while (!FileReader::isNewItem(ptr, 'M'));

		if (file.eof()) break;
		mapCount_out++;
	} while (true);

	file.close();
	return true;
}

bool Maze::setMap(int levelDifficulty)
{
	std::string fileName = PATH_TO_MAPS + FileReader::getDetermDifficult(levelDifficulty);
	std::ifstream file(fileName);
	if (!file)
		return false;

	if (!FileReader::findMapOnFile(file, mapNumber))
	{
		mapNumber = 1;
		if (FileReader::findMapOnFile(file, mapNumber))
		{
			file.close();
			return false;
		}
	}

	std::string temp;
	size = 0;
	do {
		if (file.eof())
		{
			file.close();
			return false;
		}
		file >> temp;
		if (FileReader::isNewItem(temp, 'S'))
			size = FileReader::getNumber(temp, 2, (int) temp.length() - 1);

	} while (size == 0);

	if (map == nullptr)
		map = new MapCell * [size];
	for (int i = 0; i < size; i++)
		map[i] = new MapCell[size];

	int i = 0;
	int strCount = size * 2 + 1;
	// строка для считывания с файла информации и переноса её в массив MAP
	std::vector<std::string> mapStr;
	while (i != strCount)
	{
		mapStr.push_back("");
		file >> mapStr[i];
		if (commonBack::checkStringOnInt(mapStr[i]))
			i++;
		else
		{
			file.close();
			return false;
		}
	}
	file.close();

	setMapByCell(mapStr);

	return true;
}

void Maze::setMapByCell(std::vector<std::string> mapStr)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			bool leftWall = 0, upWall = 0, rightWall = 0, downWall = 0;
			int iIndex = 2 * (i + 1);

			leftWall = ((int)mapStr[iIndex - 1][j] - '0') > 0 ? true : false;
			rightWall = ((int)mapStr[iIndex - 1][j + 1] - '0') > 0 ? true : false;
			upWall = ((int)mapStr[iIndex - 2][j] - '0') > 0 ? true : false;
			downWall = ((int)mapStr[iIndex][j] - '0') > 0 ? true : false;

			setPos(mapStr, START_SYMBOL, i, j, startPos);
			setPos(mapStr, FINISH_SYMBOL, i, j, finishPos);

			MapCell bufMap(leftWall, upWall, rightWall, downWall);
			map[i][j] = bufMap;
		}
}

void Maze::setPos(std::vector<std::string> str, char symbol, int x, int y, Point& pos_out)
{
	x++;
	bool LeftAndRight = str[x * 2 - 1][y] == symbol || str[x * 2 - 2][y] == symbol;
	bool UpAndDown = str[x * 2 - 1][y + 1] == symbol || str[x * 2][y] == symbol;
	if (UpAndDown || LeftAndRight)
	{
		pos_out.x = x - 1;
		pos_out.y = y;
	}
}

Maze::Maze()
{
	size = 0;
	mapNumber = 0;
	map = nullptr;
	startPos.setPoint(0, 0);
	finishPos.setPoint(0, 0);
}

bool Maze::Initialize(int levelDifficulty)
{
	clearMap();

	int mapCount;
	if (!getMapCount(levelDifficulty, mapCount))
		return false;

	srand((unsigned int)time(NULL));
	mapNumber = rand() % mapCount + 1;
	return setMap(levelDifficulty);
}

bool Maze::Initialize(int levelDifficulty, int mapNumber_)
{
	clearMap();

	int mapCount;
	if (!getMapCount(levelDifficulty, mapCount))
		return false;
	if (mapNumber > mapCount)
		return false;

	mapNumber = mapNumber_;
	return setMap(levelDifficulty);
}

int Maze::getSize() { return size; }

int Maze::getNumber() { return mapNumber; }

void Maze::setNumber(int value) { mapNumber = value; }

Point Maze::getStartPos() { return startPos; }

Point Maze::getFinishPos() { return finishPos; }

MapCell Maze::getMapCell(int x, int y)
{ 
	if (map != nullptr && x < size && y < size)
		return map[x][y];
	else
		return MapCell();
}

bool Maze::isWallOnRoute(int x, int y, int route)
{
	switch (route)
	{
	case RS_LEFT: return map[x][y].leftWall;
	case RS_UP: return map[x][y].upWall;
	case RS_RIGHT: return map[x][y].rightWall;
	case RS_DOWN: return map[x][y].downWall;
	default:
		return false;
	}
}

Maze::~Maze()
{
	clearMap();
}