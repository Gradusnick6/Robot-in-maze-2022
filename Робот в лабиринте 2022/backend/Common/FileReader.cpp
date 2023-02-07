#include "FileReader.h"

using namespace commonBack;

bool FileReader::isNewItem(std::string str, char firstSimbol)
{
	if (str.length() < 3) return false;

	if (str[0] != firstSimbol || str[1] != '.')
		return false;

	for (int i = 2; i < (int)str.length(); i++)
	{
		if ((int)str[i] < '0' || (int)str[i] > '9')
			return false;
	}
	return true;
}

int FileReader::getNumber(std::string str, int startIndex, int endIndex)
{
	std::string buf = "";
	for (int i = startIndex; i <= endIndex; i++)
		buf.push_back(str[i]);
	int result = -1;
	result = std::stoi(buf);
	return result;
}

std::string FileReader::getDetermDifficult(int levelDifficulty)
{
	if (levelDifficulty == DL_EASY) return "_easy.txt";
	else if (levelDifficulty == DL_MIDDLE) return "_middle.txt";
	else if (levelDifficulty == DL_PROFESSIONAL) return "_proffesional.txt";
	return ".txt";
}

bool FileReader::findMapOnFile(std::ifstream& file, int mapNumber)
{
	file.seekg(0, std::ios::beg);
	std::string ptr;
	do {
		do
		{
			if (file.eof())
				return false;

			file >> ptr;
		} while (!isNewItem(ptr, 'M'));
	} while (getNumber(ptr, 2, (int) ptr.length() - 1) != mapNumber);

	return true;
}

bool FileReader::isWithTxt(std::string fileName)
{
	int length = fileName.length();
	return fileName[length - 1] == 't' && fileName[length - 2] == 'x' && 
		   fileName[length - 3] == 't' && fileName[length - 4] == '.';
}