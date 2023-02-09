#pragma once
#include "Carcas.h"
#include "mySprite.h"

namespace csf
{
	class PopUpWindow :public Carcas
	{
	protected:
		mySprite* Background;

	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		PopUpWindow();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		PopUpWindow(mySprite* background);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="background">Имя текстуры</param>
		PopUpWindow(string name);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		void Reload(mySprite* background);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="background">Имя текстуры</param>
		void Reload(string name);
		
		/// <summary>
		/// Выключение окнa
		/// </summary>
		virtual void TurnOff();
		/// <summary>
		/// Включение окнa
		/// </summary>
		virtual void TurnOn();
		/// <summary>
		/// Обновление/Оживление окнa
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns></returns>
		virtual int Update(Event& event, RenderWindow& window);
		/// <summary>
		/// Выставить позицию по центру окна
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void setPosition(RenderWindow& window);
	};
}

