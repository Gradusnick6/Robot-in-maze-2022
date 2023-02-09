#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Сцена
	/// </summary>
	class Scene
	{
	protected:
		Event event;
		Music music;
		Sound click;
	public:
		/// <summary>
		/// Обновление/Оживление окнa
		/// </summary>
		/// <param name="window">Окно</param>
		/// <returns>Следующее действие</returns>
		virtual int Update(RenderWindow &window) = 0;
		/// <summary>
		/// Отрисовкa объекто окнa
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void Draw(RenderWindow &window) = 0;
		/// <summary>
		/// Удaление/Востaновление дaнных окнa
		/// </summary>
		virtual void Reborn() = 0;
		/// <summary>
		/// Event-функция сцены
		/// </summary>
		/// <param name="window">Окно</param>
		void EventWindow(RenderWindow& window);
		/// <summary>
		/// Запуск сцены
		/// </summary>
		/// <param name="scene">Сцена</param>
		/// <param name="window">Окно</param>
		/// <returns>Выбор действия</returns>
		static int playScene(Scene* scene, RenderWindow& window);
	};

}
