#pragma once
#include "Functional.h"
#include "BaseObject.h"

namespace csf
{
	/// <summary>
	/// Функции перетаскивания объекта
	/// </summary>
	class PlateFunctional :public Functional
	{
		//friend Vector2f BaseObject::Rotate(Vector2f pos, Vector2f centre, float angle);
	protected:
		static BaseObject* MovingPlate;
		bool moving;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		PlateFunctional();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="Object">Указатель на объект</param>
		PlateFunctional(BaseObject* Object);

		/// <summary>
		/// Перетaскивание объектa
		/// </summary>
		/// <param name="window">Окно</param>
		/// <returns>Перетаскиваемый объект</returns>
		virtual BaseObject* MovePlate(RenderWindow& window);
		/// <summary>
		/// Возврат двигается ли объект
		/// </summary>
		/// <returns>true - объект двигается, false - объект не двигается</returns>
		bool getMoving();
		/// <summary>
		/// Возврат двигающегося объекта
		/// </summary>
		/// <returns>Двигающейся объект</returns>
		static BaseObject* getMovingPlate();
	};
}