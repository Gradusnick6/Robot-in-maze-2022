#pragma once
#include "Carcas.h"
#include "DropFunctional.h"

namespace csf
{
	/// <summary>
	/// Выпадающее окно
	/// </summary>
	class DropWindow :public Carcas, public DropFunctional
	{
	protected:
		BaseObject* Box;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		DropWindow();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="master">Объект Мастер</param>
		/// <param name="Box">Указатель на объект</param>
		DropWindow(BaseObject* master, BaseObject* Box);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="master">Объект Мастер</param>
		/// <param name="name">Имя тектуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		DropWindow(BaseObject* master, string name, float x = -1, float y = -1);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="master">Объект Мастер</param>
		/// <param name="Box">Указатель на объект</param>
		void Reload(BaseObject* master, BaseObject* Box);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="master">Объект Мастер</param>
		/// <param name="name">Имя тектуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		void Reload(BaseObject* master, string name, float x = -1, float y = -1);
	};
}