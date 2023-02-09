#pragma once
#include "Functional.h"

namespace csf
{
	/// <summary>
	/// Функции выпадающего окна
	/// </summary>
	class DropFunctional :public Functional
	{
	protected:
		/// <summary>
		/// Ввод новых координат
		/// </summary>
		/// <param name="mousePosition">Позиция мыши в координатах</param>
		/// <param name="window">Окно</param>
		void setPosition(Vector2f mousePosition, RenderWindow& window);

		BaseObject* master;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		DropFunctional();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="master">Объект Мастер</param>
		/// <param name="name">Имя текстуры</param>
		DropFunctional(BaseObject* master, BaseObject* Object);

		/// <summary>
		/// Вывод в окно без анимации
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void Update(Event& event, RenderWindow& window);
		/// <summary>
		/// Ввод объекта Мастера
		/// </summary>
		/// <param name="master">Объект Мастер</param>
		virtual void setMaster(BaseObject* master);
	};
}

