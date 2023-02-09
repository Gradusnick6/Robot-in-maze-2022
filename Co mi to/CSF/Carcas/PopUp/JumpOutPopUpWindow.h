#pragma once
#include "PopUpWindow.h"
#include "Button.h"

#define JUMPPOPUPCONTINUE 0

namespace csf
{
	/// <summary>
	/// Всплывающее окно
	/// </summary>
	class JumpOutPopUpWindow :public PopUpWindow
	{
	public:
		/// <summary>
		/// Ориентация перемещения
		/// </summary>
		enum Orientation { Up, Down, Left, Right };
	protected:
		Orientation orientation;
		Button* Close;
		int numberClockCycles;

	public:
		/// <summary>
		/// Констурктор
		/// </summary>
		JumpOutPopUpWindow();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		/// <param name="close">Ссылка на объект кнопки закрытия</param>
		/// <param name="orientation">Ориентация перемещения</param>
		/// <param name="numberClockCycles">Количество тактовых циклов за которое всплывает окно</param>
		JumpOutPopUpWindow(mySprite* background, Button* close, Orientation orientation, int numberClockCycles);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="orientation">Ориентация перемещения</param>
		/// <param name="numberClockCycles">Количество тактовых циклов за которое всплывает окно</param>
		JumpOutPopUpWindow(string name, Orientation orientation, int numberClockCycles);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="orientation">Ориентация перемещения</param>
		/// <param name="numberClockCycles">Количество тактовых циклов за которое всплывает окно</param>
		void Reload(string name, Orientation orientation, int numberClockCycles);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		/// <param name="close">Ссылка на объект кнопки закрытия</param>
		/// <param name="orientation">Ориентация перемещения</param>
		/// <param name="numberClockCycles">Количество тактовых циклов за которое всплывает окно</param>
		void Reload(mySprite* background, Button* close, Orientation orientation, int numberClockCycles);

		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		/// <param name="window"></param>
		virtual void setPosition(float x, float y, RenderWindow& window);
		/// <summary>
		/// Обновление/Оживление окнa
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>JUMPPOPUPCONTINUE</returns>
		virtual int Update(Event& event, RenderWindow& window) override;
		/// <summary>
		/// Выключение окнa
		/// </summary>
		virtual void TurnOff() override;
		/// <summary>
		/// Включение окнa
		/// </summary>
		virtual void TurnOn() override;
	};
}