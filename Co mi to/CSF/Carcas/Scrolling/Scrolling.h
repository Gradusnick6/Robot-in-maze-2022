#pragma once
#include "Carcas.h"
#include "Button.h"
#include "Plate.h"
#include "mySprite.h"

namespace csf
{
	class Scrolling :public Carcas
	{
	protected:
		class ScrollPlate :public Plate
		{
		protected:
			BaseObject* master;
		public:
			/// <summary>
			/// Констуктор
			/// </summary>
			ScrollPlate();
			/// <summary>
			/// Конструктор
			/// </summary>
			/// <param name="master">Указатель на объект мастера</param>
			/// <param name="name">Имя текстуры</param>
			/// <param name="x">Позиция по х</param>
			/// <param name="y">Позиция по y</param>
			ScrollPlate(BaseObject* master, string name);
			/// <summary>
			/// Обновить данные
			/// </summary>
			/// <param name="master">Указатель на объект мастера</param>
			/// <param name="name">Имя текстуры</param>
			/// <param name="x">Позиция по х</param>
			/// <param name="y">Позиция по y</param>
			void Reload(BaseObject* master, string name);
			
			/// <summary>
			/// Перетaскивание объектa
			/// </summary>
			/// <param name="window">Окно</param>
			/// <returns>Указатель на объект плашки</returns>
			//virtual Plate* MovePlate(RenderWindow& window) override;
			
			/// <summary>
			/// Обработка движения колёсиком мыши
			/// </summary>
			/// <param name="percent">Процент скроллинга</param>
			virtual void WheelScrolled(float percent);
			
			/// <summary>
			/// Ввод новой позиции
			/// </summary>
			/// <param name="x">Позиция по х</param>
			/// <param name="y">Позиция по y</param>
			virtual void setPosition(float x, float y) override = 0;
			/// <summary>
			/// Ввод новыой позиции в процентaх
			/// </summary>
			/// <param name="percent">Процент скроллинга</param>
			virtual void setPosition(float percent) = 0;
			/// <summary>
			/// Возврaт процентa скрллинга
			/// </summary>
			/// <returns>Процент скроллинга</returns>
			virtual float getScrolling() = 0;
		} *scrollPlate;

		mySprite* master;

		mySprite* Box;
		Button* upScrollButton;
		Button*	downScrollButton;

	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		Scrolling();

		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="master">Указатель на объект мастера</param>
		/// <param name="Box">Указатель на объект рамки</param>
		/// <param name="upScrollButton">Указатель на объект кнопки вверх</param>
		/// <param name="downScrollButton">Указатель на объект кнопки вниз</param>
		Scrolling(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton);

		/// <summary>
		/// Обработка скролинга
		/// </summary>
		/// <param name="event">События окна</param>
		/// <param name="window">Окно</param>
		/// <returns>0 - произошло действие, -1 - действия не было</returns>
		virtual int Update(Event& event, RenderWindow& window);
		/// <summary>
		/// Обновление позиции
		/// </summary>
		virtual void updatePosition() = 0;
		/// <summary>
		/// Возврат процента скролинга
		/// </summary>
		/// <returns>Процент скроллинга</returns>
		virtual float getScrolling();
	};
}

