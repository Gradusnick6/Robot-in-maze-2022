#pragma once

//���� ������
#define NO_ERROR_IN_CODE 0
#define ERROR_IN_CODE 1
#define ERROR_IN_LOGIC 2

namespace programming
{
	struct GameError
	{
		// ������ ������� ������� ���������� �����
		int iErrorWord;
		int typeError;
		GameError();
	};
}