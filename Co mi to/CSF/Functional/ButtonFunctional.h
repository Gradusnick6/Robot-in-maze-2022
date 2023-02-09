#pragma once
#include "Functional.h"

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Функции кнопки
	/// </summary>
	class ButtonFunctional :public Functional
	{
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		ButtonFunctional();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="Object">Указатель на объект</param>
		ButtonFunctional(BaseObject* Object);
		/// <summary>
		/// Проверка нажата ли эта кнопка (нa спуск кнопки)
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>true - кнопка нажата, false - кнопка не нажата</returns>
		virtual bool Pressed(Event& event, RenderWindow& window);
		/// <summary>
		/// Проверка нажата ли эта кнопка (нa поднятие кнопки)
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>true - кнопка нажата, false - кнопка не нажата</returns>
		virtual bool Released(Event& event, RenderWindow& window);
		/// <summary>
		/// Проверка сделан ли двойной клик
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>true - двойной клик сделан, false - двойной клик не сделан</returns>
		virtual bool DoubleClick(Event& event, RenderWindow& window);
	};
}