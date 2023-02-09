#pragma once
#include "Functional.h"

namespace csf
{
	/// <summary>
	/// Исчезающий объект
	/// </summary>
	class DisappearingFunctional : public Functional
	{
	public:
		/// <summary>
		/// Ориентация полёта
		/// </summary>
		enum Orientation { Up, Down, Left, Right, NotMove };

	protected:
		Orientation orientation;
		float flightSpeed, vanishingRate, alpha;
		Vector2f startLocation;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		DisappearingFunctional();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="object">Главный объект</param>
		/// <param name="orientation">Ориентация полёта</param>
		/// <param name="flightSpeed">Скорость полёта</param>
		/// <param name="vanishingRate">Скорость исчезания</param>
		DisappearingFunctional(BaseObject* object, Orientation orientation, float flightSpeed, float vanishingRate);

		/// <summary>
		/// Сброс данных
		/// </summary>
		virtual void Refresh();
		/// <summary>
		/// Оживление
		/// </summary>
		virtual void Update();
	};
}