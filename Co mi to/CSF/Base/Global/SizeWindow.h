#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Параметры окна
	/// </summary>
	class SizeWindow
	{
	private:
		static string sizeWindow;
		static string failName;
		static Vector2i originalDimentions;
		static Vector2i	realDimentions;
		static int isFullScreen, isAdmin;
		static Vector2f scaleAdapting;
		

	public:
		static RenderWindow* window;

		/// <summary>
		/// Ввести размеры окна
		/// </summary>
		/// <param name="Dimentions">Размеры окна</param>
		static void setSizeWindow(Vector2i Dimentions);
		/// <summary>
		/// Ввести размеры окна
		/// </summary>
		/// <param name="Dimentions">Размеры окна</param>
		/// <param name="isFullScreen">Полный экран</param>
		static void setSizeWindow(Vector2i Dimentions, bool isFullScreen);
		/// <summary>
		/// 
		/// </summary>
		/// <param name="originalDimentions">Исходный размер</param>
		/// <param name="realDimentions">Реальный размер</param>
		/// <param name="isFullScreen">Полный экран</param>
		static void setSizeWindow(Vector2i originalDimentions, Vector2i realDimentions, bool isFullScreen);
		/// <summary>
		/// Вернуть размеры окна
		/// </summary>
		/// <returns>Размеры окна</returns>
		static string getSizeWindow();
		/// <summary>
		/// Вернуть изначальные размеры окна
		/// </summary>
		/// <returns>Размеры окна по х</returns>
		static Vector2i getOriginalDimentions();
		/// <summary>
		/// Вернуть реальные размеры окна
		/// </summary>
		/// <returns>Размеры окна по х</returns>
		static Vector2i getRealDimentions();
		/// <summary>
		/// Ввести полный экран
		/// </summary>
		/// <param name="isFullScreen">Полный экран</param>
		static void setIsFullScreen(bool isFullScreen);
		/// <summary>
		/// Ввести режим админа
		/// </summary>
		/// <param name="isAdmin">Режим админа</param>
		static void setIsAdmin(bool isAdmin);
		/// <summary>
		/// Вернуть полный экран
		/// </summary>
		/// <returns>true - полный экран, false - не полный экран</returns>
		static int getIsFullScreen();
		/// <summary>
		/// Вернуть режим админа
		/// </summary>
		/// <returns>true - режим админа, false - не режим админа</returns>
		static int getIsAdmin();
		/// <summary>
		/// Вернуть масштаб адаптации
		/// </summary>
		/// <returns>Масштаб объекта</returns>
		static Vector2f getScaleAdapting();
	};
	
}