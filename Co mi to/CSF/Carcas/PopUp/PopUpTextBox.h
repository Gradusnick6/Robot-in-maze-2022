#pragma once
#include "PopUpWindow.h"
#include "myText.h"
#include "Button.h"

#define TEXTBOXCLOSE 0
#define TEXTBOXAPPLY 1
#define TEXTBOXCONTINUE 2

namespace csf
{
	class PopUpTextBox :public PopUpWindow
	{
	protected:
		myText* text;
		Button* Close;
		Button* Apply;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		PopUpTextBox();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		/// <param name="text">Ссылка на объект текста</param>
		/// <param name="close">Ссылка на объект кнопки закрыть</param>
		/// <param name="apply">Ссылка на объект кнопки подтвердить</param>
		PopUpTextBox(mySprite* background, myText* text, Button* close, Button* apply);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="maxLenght">Максимум символов</param>
		PopUpTextBox(string name, int maxLenght = 10);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="maxLenght">Максимум символов</param>
		void Reload(string name, int maxLenght = 10);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="background">Ссылка на объект фона</param>
		/// <param name="text">Ссылка на объект текста</param>
		/// <param name="close">Ссылка на объект кнопки закрыть</param>
		/// <param name="apply">Ссылка на объект кнопки подтвердить</param>
		void Reload(mySprite* background, myText* text, Button* close, Button* apply);
		/// <summary>
		/// Обновление/Оживление окнa
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>Нажата кнопка Apply - TEXTBOXAPPLY. Нажата кнопка Close - TEXTBOXCLOSE. Не нажата кнопка - TEXTBOXCONTINUE</returns>
		virtual int Update(Event& event, RenderWindow& window) override;
	};
}