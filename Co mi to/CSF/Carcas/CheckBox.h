#pragma once
#include "Carcas.h"
#include "ButtonFunctional.h"
#include "mySprite.h"
#include "Button.h"

namespace csf
{
	class CheckBox :public Carcas
	{
	protected:

		BaseObject* Box;
		ButtonFunctional* buttonFunctional;
		BaseObject* Check;

		bool isCheck;

	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		CheckBox();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Указатель на объект рамки</param>
		/// <param name="buttonFunctional">Указатель на объект функционал кнопки (box и buttonFunctional это один и тот же указатель)</param>
		/// <param name="Check">Указател  на объект галочки</param>
		CheckBox(BaseObject* box, ButtonFunctional* buttonFunctional, BaseObject* Check);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="button">Указатель на объект кнопки</param>
		/// <param name="Check">Указател  на объект галочки</param>
		CheckBox(Button* button, BaseObject* Check);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="isCheck">Поставлена ли галочка</param>
		/// <param name="enable">Активность</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		CheckBox(string name, bool isCheck, float x = -1, float y = -1);

		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="box">Указатель на объект рамки</param>
		/// <param name="buttonFunctional">Указатель на объект функционал кнопки</param>
		/// <param name="Check">Указател  на объект галочки</param>
		void Reload(BaseObject* box, ButtonFunctional* buttonFunctional, BaseObject* Check);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="button">Указатель на объект кнопки</param>
		/// <param name="Check">Указател  на объект галочки</param>
		void Reload(Button* button, BaseObject* Check);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="isCheck">Поставлена ли галочка</param>
		/// <param name="enable">Активность</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		void Reload(string name, bool isCheck, float x = -1, float y = -1);

		/// <summary>
		/// Смена состояния CheckBox (нa спуск кнопки)
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>true - кнопка нажата, false - кнопка не нажата</returns>
		virtual bool Update(Event& event, RenderWindow& window);
		/// <summary>
		/// Ввод активности объекта
		/// </summary>
		/// <param name="enable">Активность объекта</param>
		bool getCheck();
		/// <summary>
		/// Ввод состояния CheckBox
		/// </summary>
		/// <param name="isCheck">Состояние</param>
		void setCheck(bool isCheck);
	};
}

