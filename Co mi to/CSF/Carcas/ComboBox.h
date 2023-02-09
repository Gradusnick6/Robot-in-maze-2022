#pragma once
#include "Carcas.h"
#include "Plate.h"
#include "mySprite.h"

namespace csf
{
	class ComboBox :public Carcas
	{
	protected:
		friend Plate;
		vector<Plate*> plateBank;
		BaseObject* Box;

		bool enable;
		float lineSpacing;
		int movePlate;
		int size;
		Vector2f startPositionPlate;

	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		ComboBox();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		ComboBox(mySprite* box);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="plateBank">Вектор на ссылки объектов плашек</param>
		ComboBox(mySprite* box, vector<Plate*> plateBank);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Имя текстуры</param>
		/// <param name="plateBank">Количество плашек</param>
		ComboBox(string name, int numPlate);

		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		void Reload(mySprite* box);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="plateBank">Вектор на ссылки объектов плашек</param>
		void Reload(mySprite* box, vector<Plate*> plateBank);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="box">Ссылка на объект рамки</param>
		/// <param name="plateBank">Вектор на ссылки объектов плашек</param>
		void Reload(string name, int numPlate);
		/// <summary>
		/// Возврaт плaшки
		/// </summary>
		/// <param name="i">Индекс плашки</param>
		/// <returns>Ссылка на объект плашки</returns>
		Plate* operator[](int i);
		/// <summary>
		/// Вывод объектов без анимации
		/// </summary>
		/// <param name="window"></param>
		virtual void operator>(RenderWindow& window) override;
		/// <summary>
		/// Вывод объектов с анимацией
		/// </summary>
		/// <param name="window"></param>
		virtual void operator>>(RenderWindow& window) override;
		/// <summary>
		/// Обновить позицию
		/// </summary>
		void updatePosition();
		/// <summary>
		/// Перетaскивание объектa плaшки
		/// </summary>
		/// <param name="window">Окно</param>
		/// <returns>Ссылка на перетаскиваемый объект плашки</returns>
		Plate* MovePlates(RenderWindow& window);
		/// <summary>
		/// Ввод коэффициента интервала между плашками
		/// </summary>
		/// <param name="lineSpacing">Коэффициента интервала между плашками</param>
		void setLineSpacing(float lineSpacing);
		/// <summary>
		/// Вернуть коэффициент интервала между плашками
		/// </summary>
		float getLineSpacing();
		/// <summary>
		/// Ввод начальной позиции плашек.
		/// Если позиция равна (-1, -1), то выравнивание по центру
		/// </summary>
		/// <param name="lineSpacing">Начальная позициия плашек</param>
		void setStartPositionPlate(Vector2f startPositionPlate);
		/// <summary>
		/// Вернуть начальную позицию плашек
		/// </summary>
		Vector2f getStartPositionPlate();
	};
}

