#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
 

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Текстура
	/// </summary>
	class myTexture
	{
	private:
		/// <summary>
		/// Текстура
		/// </summary>
		Texture texture;
		/// <summary>
		/// Имя текстуры
		/// </summary>
		string name;
		/// <summary>
		/// Позиция
		/// </summary>
		Vector2f location;
		/// <summary>
		/// Размеры
		/// </summary>
		Vector2f dimensions;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		myTexture();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="way">Путь к тектуре</param>
		/// <param name="name">Имя текстуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y/param>
		myTexture(string way, string name, int x, int y);
		/// <summary>
		/// Возврат текстуры
		/// </summary>
		/// <returns>Текстура</returns>
		Texture& getTexture(){ return texture; }
		/// <summary>
		/// Вернуть имя текстуры
		/// </summary>
		/// <returns>Имя текстуры</returns>
		string& getName(){ return name; }
		/// <summary>
		/// вернуть позицию
		/// </summary>
		/// <returns>Позицыя</returns>
		Vector2f getPosition(){ return location; }
		/// <summary>
		/// Вернуть размеры
		/// </summary>
		/// <returns>Размеры</returns>
		Vector2f getDimensions(){ return dimensions; }
	};
}

