#pragma once
#include "BaseObject.h"

namespace csf
{
	/// <summary>
	/// Однострочный текст
	/// </summary>
	class myText :public BaseObject
	{
		enum HorizontalAlignmentType { Left, HCentre, Right, HNoAlignment};
		enum VerticalAlignmentType { Up, VCentre, Down, VNoAlignment};
	protected:
		static Font font;

		HorizontalAlignmentType horizontalAlignmentType;
		VerticalAlignmentType verticalAlignmentType;
		Text::Style style;

		Text text;

		Color outlineColor;
		float outlineThickness;
		int size;
		float letterSpacing;

		int maxLenght;
		bool m_textChanged;

		/// <summary>
		/// Перевод из строки в целое число
		/// </summary>
		/// <param name="s">Строка</param>
		/// <returns></returns>
		virtual int strToNum(string s);
		/// <summary>
		/// Перевод из строки в вещественное число
		/// </summary>
		/// <param name="s">Строка</param>
		/// <returns></returns>
		float strToNum_f(string s);
		/// <summary>
		/// Меньше ли ширина текста в box
		/// </summary>
		/// <param name="box">Ширина рамки</param>
		/// <returns>true - ширина текста меньше box, false - ширина текста больше box</returns>
		virtual bool getFitInBoxWidth(int widthBox);
		/// <summary>
		/// Меньше ли высота текста в box
		/// </summary>
		/// <param name="box">Высота рамки</param>
		/// <returns>true - высота текста меньше box, false - высота текста больше box</returns>
		virtual bool getFitInBoxHeight(int heightBox);
		/// <summary>
		/// Меньше ли размер текста в box
		/// </summary>
		/// <param name="box">Размер рамки</param>
		/// <returns>true - размер текста меньше box, false - размер текста больше box</returns>
		virtual bool getFitInBox(Vector2f sizeBox);
		/// <summary>
		/// Удалить абзацы в строке
		/// </summary>
		/// <param name="name">Строка</param>
		/// <returns>Строка без абзацев</returns>
		virtual String DeleteParagraphs(String name);
		/// <summary>
		/// Обновление размеров
		/// </summary>
		virtual void updateDimentions();
		/// <summary>
		/// Обновление позиции
		/// </summary>
		virtual void updateLocation();
	public:
		/// <summary>
		/// Ввод шрифта
		/// </summary>
		/// <param name="newFont">Новый шрифт</param>
		static void setFont(Font& newFont);
		/// <summary>
		/// Возврат шрифта
		/// </summary>
		/// <returns>Шрифт</returns>
		static Font getFont();

		/// <summary>
		/// Конструктор
		/// </summary>
		myText();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		/// <param name="name">Текст</param>
		/// <param name="size">Размер текста</param>
		myText(float x, float y, String name, int size);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="location">Позиция</param>
		/// <param name="name">Текст</param>
		/// <param name="size">Размер текста</param>
		myText(Vector2f location, String name, int size);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="name">Текст</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		void Reload(String name, float x = -1, float y = -1);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		/// <param name="name">Текст</param>
		/// <param name="size">Размер текста</param>
		void Reload(float x, float y, String name, int size);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="location">Позиция</param>
		/// <param name="name">Текст</param>
		/// <param name="size">Размер текста</param>
		void Reload(Vector2f location, String name, int size);

		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		/// <returns>Изменения цвета</returns>
		virtual void setColor(int red, int green, int blue, int alpha = -1);
		/// <summary>
		/// Ввод точки позции объекта
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setOrigin(float x, float y);
		/// <summary>
		/// Вывод в окно без анимации
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void operator> (RenderWindow& window) override;
		/// <summary>
		/// Вывод в окно с анимацией
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void operator>> (RenderWindow& window) override;
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setPosition(float x, float y) override;
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="_location">Позиция</param>
		virtual void setPosition(Vector2f _location);
		/// <summary>
		/// Ввод нового размера шрифта
		/// </summary>
		/// <param name="size">Размер шрифта</param>
		virtual void setSize(int size);
		/// <summary>
		/// Ввод нового текста
		/// </summary>
		/// <param name="name">Текст</param>
		virtual void setString(String name);
		/// <summary>
		/// Ввод с клавиатуры
		/// </summary>
		/// <param name="event"></param>
		/// <returns>true - ввод закончен, false - ввод продолжается</returns>
		virtual bool Input(Event& event);
		/// <summary>
		/// Очистка строки
		/// </summary>
		virtual void Clear();
		/// <summary>
		/// Возврат количества символов
		/// </summary>
		/// <returns>Количество символов</returns>
		virtual int getLength();
		/// <summary>
		/// Возврат текста
		/// </summary>
		/// <returns>Текст</returns>
		virtual String getString();
		/// <summary>
		/// Обновить шрифт, цвет и позицию
		/// </summary>
		virtual void Refresh();
		/// <summary>
		/// Ввод максимума символов
		/// </summary>
		/// <param name="maxLenght">Максимум символов</param>
		virtual void setMaxLenght(int maxLenght);
		/// <summary>
		/// Выровнять текстовое поле по рамке
		/// </summary>
		/// <param name="textRect">Прямоугольник текстового поля</param>
		/// <returns>true - текст выравнен, false - текст не выравнен</returns>
		virtual void setTextRect(FloatRect textRect);
		/// <summary>
		/// Поиск подстроки в строке
		/// </summary>
		/// <param name="str">Подстрока</param>
		/// <param name="start">Индекс начала поиска</param>
		/// <returns>Индекс начала подстроки в строке. Если подстроки не нашлось - String::InvalidPos</returns>
		virtual size_t Find(String str, size_t start = 0);
		/// <summary>
		/// Ввод масштаба объекта
		/// </summary>
		/// <param name="x">Масштаба по x</param>
		/// <param name="y">Масштаба по y</param>
		virtual void setScale(float x, float y) override;
		/// <summary>
		/// Ввод поворота объекта
		/// </summary>
		/// <param name="angle">Угол поворота в градусах</param>
		virtual void setRotate(float angle) override;
		/// <summary>
		/// Ввод цвета контура текста
		/// </summary>
		/// <param name="outlineColor">Цвет контура текста</param>
		virtual void setOutlineColor(Color outlineColor);
		/// <summary>
		/// Возврат толщны контура ткста
		/// </summary>
		/// <param name="outlineColor">Толщины контура текста</param>
		virtual void setOutlineThickness(float outlineThickness);
		/// <summary>
		/// Ввод интервалла между буквами
		/// </summary>
		/// <param name="letterSpacing">Коэффициент интерваламежду буквами</param>
		virtual void setLetterSpacing(float letterSpacing);
		/// <summary>
		/// Ввод стиля текста
		/// </summary>
		/// <param name="style">Стиль текста</param>
		virtual void setStyle(Text::Style style);
		/// <summary>
		/// Ввод выравнивания по горизонтали
		/// </summary>
		/// <param name="horizontalAlignmentType">Выравнивания по горизонтали</param>
		virtual void setHorizontalAlignmentType(HorizontalAlignmentType horizontalAlignmentType);
		/// <summary>
		/// Ввод выравнивания по вертикали
		/// </summary>
		/// <param name="verticalAlignmentType">Выравнивания по вертикали</param>
		virtual void setVerticalAlignmentType(VerticalAlignmentType verticalAlignmentType);
		/// <summary>
		/// Ввод выравнивания
		/// </summary>
		/// <param name="horizontalAlignmentType">Выравнивания по горизонтали</param>
		/// <param name="verticalAlignmentType">Выравнивания по вертикали</param>
		virtual void setAlignmentType(HorizontalAlignmentType horizontalAlignmentType, VerticalAlignmentType verticalAlignmentType);
		/// <summary>
		/// Возврат цвета контура текста
		/// </summary>
		/// <returns>Цвет контура текста</returns>
		virtual Color getOutlineColor();
		/// <summary>
		/// Возврат толщны контура ткста
		/// </summary>
		/// <returns>Коэффициент интерваламежду буквами</returns>
		virtual float getOutlineThickness();
		/// <summary>
		/// Возврат интервалла между буквами
		/// </summary>
		/// <returns>Коэффициент интерваламежду буквами</returns>
		virtual float getLetterSpacing();
		/// <summary>
		/// Возврат стиля текста
		/// </summary>
		///  <returns>Стиль текста </returns>
		virtual Text::Style getStyle();
		/// <summary>
		/// Возврат выравнивания по горизонтали
		/// </summary>
		/// <returns>Выравнивания по горизонтали</returns>
		virtual HorizontalAlignmentType getHorizontalAlignmentType();
		/// <summary>
		/// Возврат выравнивания по вертикали
		/// </summary>
		/// <returns>Выравнивания по вертикали</returns>
		virtual VerticalAlignmentType getVerticalAlignmentType();
	};
}