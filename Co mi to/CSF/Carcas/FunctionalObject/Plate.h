#pragma once
#include "Carcas.h"
#include "PlateFunctional.h"

namespace csf
{
	/// <summary>
	/// Перетаскиваемый объект
	/// </summary>
	class Plate :public Carcas, public PlateFunctional
	{
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		Plate();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="Object">Указатель на объект</param>
		Plate(BaseObject* Object);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя тектуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		Plate(string name, float x = -1, float y = -1);
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