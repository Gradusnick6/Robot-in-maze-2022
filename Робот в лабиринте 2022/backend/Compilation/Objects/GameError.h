#pragma once

//Типы ошибок
#define NO_ERROR_IN_CODE 0
#define ERROR_IN_CODE 1
#define ERROR_IN_LOGIC 2

namespace programming
{
	struct GameError
	{
		// индекс первого символа ошибочного слова
		int iErrorWord;
		int typeError;
		GameError();
	};
}