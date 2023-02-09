#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>
#include "myTexture.h"

#define INFORMATIONFORIMAGE "AccompanyingInformation.txt"

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Банк текстур
	/// </summary>
	class TextureBank
	{
	private:
		vector <myTexture> texture;

	public:
		/// <summary>
		/// Ввести путь к текстурам
		/// </summary>
		/// <param name="Way">Путь к текстурам</param>
		void setTextureBank(string Way);
		/// <summary>
		/// Верунуть текстуру
		/// </summary>
		/// <param name="index">Индекс текстуры</param>
		/// <returns>Текстура</returns>
		myTexture& operator[](int index);
		/// <summary>
		/// Верунуть текстуру
		/// </summary>
		/// <param name="Name">Имя текстуры</param>
		/// <returns>Текстура</returns>
		myTexture& operator[](string Name);
		/// <summary>
		/// Верунуть текстуру
		/// </summary>
		/// <param name="index">Индекс текстуры</param>
		/// <returns>Текстура</returns>
		myTexture& getTexture(int index);
		/// <summary>
		/// Верунуть текстуру
		/// </summary>
		/// <param name="Name">Имя текстуры</param>
		/// <returns>Текстура</returns>
		myTexture& getTexture(string Name);
	};
	
}


