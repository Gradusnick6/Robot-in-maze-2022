#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "BaseObject.h"

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Функционал
	/// </summary>
	class Functional
	{
	protected:
		BaseObject* Object;

		/// <summary>
		/// Возврат точки с координатами, полученными поворотом искомой точки
		/// </summary>
		/// <param name="pos">искомая точка</param>
		/// <param name="centre">точка, относительно которой осуществлеяется поворт</param>
		/// <param name="angle">угол поворота</param>
		Vector2f Rotate(Vector2f pos, Vector2f centre, float angle);
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		Functional();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="Object">Указатель на объект</param>
		Functional(BaseObject* Object);
	};
}

