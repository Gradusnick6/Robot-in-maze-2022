#pragma once
#include "Scrolling.h"

namespace csf
{
	class ScrollingHorizontal :public Scrolling
	{
	protected:
		class ScrollPlateHorizontal :public ScrollPlate
		{
		public:
			/// <summary>
			/// Конструктор
			/// </summary>
			ScrollPlateHorizontal();
			/// <summary>
			/// Конструктор
			/// </summary>
			/// <param name="master">Указатель на объект мастера</param>
			/// <param name="name">Имя текстуры</param>
			ScrollPlateHorizontal(BaseObject* master, string name);

			/// <summary>
			/// Ввод новых координат
			/// </summary>
			/// <param name="x">Позиция по х</param>
			/// <param name="y">Позиция по y</param>
			virtual void setPosition(float x, float y) override;
			/// <summary>
			/// Ввод новыой позиции в процентaх
			/// </summary>
			/// <param name="percent">Прцент скроллинга</param>
			virtual void setPosition(float percent) override;
			/// <summary>
			/// Возврaт процентa скроллинга
			/// </summary>
			/// <returns>Процент скроллинга</returns>
			virtual float getScrolling() override;
		};
	
		/// <summary>
		/// Обновить позиции объектов
		/// </summary>
		void updateConfiguration();
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		ScrollingHorizontal();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="master">Указатель на объект мастера</param>
		/// <param name="Box">Указатель на объект рамки</param>
		/// <param name="upScrollButton">Указатель на объект кнопки вверх</param>
		/// <param name="downScrollButton">Указатель на объект кнопки вниз</param>
		/// <param name="nameScrollPlate">Имя текстуры плашки скроллинга</param>
		ScrollingHorizontal(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton, string nameScrollPlate);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="master">Указатель на объект мастера</param>
		/// <param name="name">Имя текстуры</param>
		ScrollingHorizontal(mySprite* master, string name);

		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="master">Указатель на объект мастера</param>
		/// <param name="name">Имя текстуры</param>
		void Reload(mySprite* master, string name);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="master">Указатель на объект мастера</param>
		/// <param name="Box">Указатель на объект рамки</param>
		/// <param name="upScrollButton">Указатель на объект кнопки вверх</param>
		/// <param name="downScrollButton">Указатель на объект кнопки вниз</param>
		/// <param name="nameScrollPlate">Имя текстуры плашки скроллинга</param>
		void Reload(mySprite* master, mySprite* Box, Button* upScrollButton, Button* downScrollButton, string nameScrollPlate);
		/// <summary>
		/// Обновление позиции
		/// </summary>
		virtual void updatePosition();
	};
}