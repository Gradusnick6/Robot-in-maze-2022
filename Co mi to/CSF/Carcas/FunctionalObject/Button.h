#pragma once
#include "Carcas.h"
#include "ButtonFunctional.h"

namespace csf
{
	/// <summary>
	/// Кнопка
	/// </summary>
	class Button :public Carcas, public ButtonFunctional
	{
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		Button();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="Object">Указатель на объект</param>
		Button(BaseObject* Object);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя тектуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		Button(string name, float x = -1, float y = -1);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="Object">Указатель на объект</param>
		void Reload(BaseObject* Object);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="name">Имя тектуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		void Reload(string name, float x = -1, float y = -1);
		/// <summary>
		/// Ввод типа активации объекта
		/// </summary>
		/// <param name="i">Тип активации объекта</param>
		virtual void setAwakeningType(AwakeningTypes AwakeningType) override;
	};
}