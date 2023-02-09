#pragma once
#include "PopUpWindow.h"
#include "Button.h"

#define POPUPNO 3
#define POPUPYES 4
#define POPUPCONTINUE 5

namespace csf
{
	class PopUpWindowУesNo :public PopUpWindow
	{
	protected:
		BaseObject* Question;
		Button* Yes; 
		Button* No;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		PopUpWindowУesNo();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		/// <param name="question">Ссылка на объект вопроса</param>
		/// <param name="yes">Ссылка на объект кнопки "да"</param>
		/// <param name="no">Ссылка на объект кнопки "нет"</param>
		PopUpWindowУesNo(mySprite* background, BaseObject* question, Button* yes, Button* no);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя тектуры</param>
		PopUpWindowУesNo(string name);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="name">Имя тектуры</param>
		void Reload(string name);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		/// <param name="question">Ссылка на объект вопроса</param>
		/// <param name="yes">Ссылка на объект кнопки "да"</param>
		/// <param name="no">Ссылка на объект кнопки "нет"</param>
		void Reload(mySprite* background, BaseObject* question, Button* yes, Button* no);
		
		/// <summary>
		/// Обновление/Оживление окнa
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>Нажата кнопка Yes - POPUPYES. Нажата кнопка No - POPUPNO. Не нажата кнопка - POPUPCONTINUE</returns>
		virtual int Update(Event& event, RenderWindow& window) override;
	};
}