#pragma once
#include "Carcas.h"
#include "mySprite.h"
#include "myText.h"

namespace csf
{
	/// <summary>
	/// Рамка для текста
	/// </summary>
	class BoxForText : public Carcas
	{
	protected:
		mySprite* Box;
		myText* text;
		Vector2f centre;
		Vector2f sizeBox;

	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		BoxForText();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="text">Ссылка на объект текста</param>
		BoxForText(mySprite* box, myText* text);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="text">Ссылка на объект текста</param>
		/// <param name="centre">Центр относительно объекта рамки</param>
		/// <param name="sizeBox">Размер рамки</param>
		BoxForText(mySprite* box, myText* text, Vector2f centre, Vector2f sizeBox);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="text">Ссылка на объект текста</param>
		/// <param name="centre">Центр относительно объекта рамки</param>
		/// <param name="sizeBox">Размер рамки</param>
		void Reload(mySprite* background, myText* text, Vector2f centre, Vector2f sizeBox);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="text">Ссылка на объект текста</param>
		void Reload(mySprite* background, myText* text);
		
		/// <summary>
		/// Вернуть размера рамки
		/// </summary>
		/// <returns>Размер рамки</returns>
		virtual Vector2f getSizeBox();
		/// <summary>
		/// Вернуть позицию центра
		/// </summary>
		/// <returns>Позиция центра</returns>
		virtual Vector2f getCentre();
		/// <summary>
		/// Ввод размера рамки
		/// </summary>
		/// <param name="sizeBox">Размер рамки</param>
		virtual void setSizeBox(Vector2f sizeBox);
		/// <summary>
		/// Ввод позиции центра
		/// </summary>
		/// <param name="centre">Позиция центра</param>
		virtual void setCentre(Vector2f centre);
		/// <summary>
		/// Обновить позицию
		/// </summary>
		virtual void updatePosition();
	};
}

