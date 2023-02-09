#pragma once
#include "Carcas.h"
#include "DisappearingFunctional.h"

namespace csf
{
	/// <summary>
	/// Кнопка
	/// </summary>
	class DisappearingObject :public Carcas, public DisappearingFunctional
	{
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		DisappearingObject();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="object">Главный объект</param>
		/// <param name="orientation">Ориентация полёта</param>
		/// <param name="flightSpeed">Скорость полёта</param>
		/// <param name="vanishingRate">Скорость исчезания</param>
		DisappearingObject(BaseObject* object, Orientation orientation, float flightSpeed, float vanishingRate);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="object">Главный объект</param>
		/// <param name="orientation">Ориентация полёта</param>
		/// <param name="flightSpeed">Скорость полёта</param>
		/// <param name="vanishingRate">Скорость исчезания</param>
		void Reload(BaseObject* object, Orientation orientation, float flightSpeed, float vanishingRate);
	};
}