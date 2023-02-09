#pragma once
#include "Carcas.h"
#include "myText.h"
namespace csf
{
	/// <summary>
	/// Многострочный текст
	/// </summary>
	class MultilineText :public myText, public Carcas
	{
		friend myText;
	protected:
		vector<myText*> Texts;
		float lineSpacing;

		/// <summary>
		/// Расчёт размеров
		/// </summary>
		virtual void updateDimensions();
		/// <summary>
		/// Расчёт размеров
		/// </summary>
		virtual void setDimensions();
		/// <summary>
		/// Обновить позицию
		/// </summary>
		virtual void updatePosition();
		/// <summary>
		/// Возврат части строки между startIndex и endIndex
		/// </summary>
		/// <param name="str">Строка</param>
		/// <param name="startIndex">Индекс начала (включительно)</param>
		/// <param name="endIndex">Индекс конца (включительно)</param>
		/// <returns>Часть строки между startIndex и endIndex</returns>
		virtual String getStringPart(String str, int startIndex, int endIndex);
		/// <summary>
		/// Вернуть индекс ближайшего к центру пробела в строке
		/// </summary>
		/// <param name="text">Строка</param>
		/// <returns>Индекс ближайшего к центру пробела в строке</returns>
		int getIndexCentralSpace(String str);
		/// <summary>
		/// Добавить один абзац
		/// </summary>
		/// <returns>true - абзац добавлен, false - абзац не добавлен</returns>
		virtual bool DivideIntoParagraphs();
		/// <summary>
		/// Разделить текст
		/// </summary>
		virtual void SplitText();
		/// <summary>
		/// Очистить векторы
		/// </summary>
		virtual void deleteTexts();

	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		MultilineText();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		/// <param name="name">Текст</param>
		/// <param name="size">Размер шрфта</param>
		/// <param name="lineSpacing">Межстрочный интервал</param>
		MultilineText(float x, float y, String name, int size, float lineSpacing);

		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="name">Текст</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		void Reload(String name, float x = -1, float y = -1);
		/// <summary>
		/// Обновление данных
		/// </summary>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		/// <param name="name">Текст</param>
		/// <param name="size">Размер шрфта</param>
		/// <param name="lineSpacing">Межстрочный интервал</param>
		void Reload(float x, float y, String name, int size, float lineSpacing);

		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		virtual void setColor(int red, int green, int blue, int alpha = -1);
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
		virtual void setPosition(Vector2f _location) override;
		/// <summary>
		/// Ввод нового размера шрифта
		/// </summary>
		/// <param name="size">Размер шрифта</param>
		virtual void setSize(int size) override;
		/// <summary>
		/// Ввод нового текста
		/// </summary>
		/// <param name="name">Текст</param>
		virtual void setString(String name) override;
		/// <summary>
		/// Ввод с клавиатуры (НЕ РАБОТАЕТ)
		/// </summary>
		/// <param name="event"></param>
		/// <returns>true - ввод закончен, false - ввод продолжается</returns>
		virtual bool Input(Event& event) override;
		/// <summary>
		/// Очистка текста
		/// </summary>
		virtual void Clear() override;
		/// <summary>
		/// Возврат количества символов
		/// </summary>
		/// <returns>Количество символов</returns>
		virtual int getLength() override;
		/// <summary>
		/// Возврат текста
		/// </summary>
		/// <returns>Текст</returns>
		virtual String getString() override;
		/// <summary>
		/// Обновить данные
		/// </summary>
		virtual void Refresh() override;
		/// <summary>
		/// Ввод максимума символов
		/// </summary>
		/// <param name="maxLenght">Максимум символов</param>
		virtual void setMaxLenght(int maxLenght) override;
		/// <summary>
		/// Возврaт указателя на объект
		/// </summary>
		/// <returns>Указатель на объект</returns>
		virtual BaseObject* operator*() override;
		/// <summary>
		/// Выровнять текстовое поле по рамке
		/// </summary>
		/// <param name="sizeBox">Размер рамка</param>
		/// <returns>true - текст выравнен, false - текст не выравнен</returns>
		virtual bool AlignTextBox(Vector2f sizeBox) ;
		/// <summary>
		/// Выровнять текстовое поле по рамке
		/// </summary>
		/// <param name="sizeBox">Размер рамка</param>
		/// <param name="isSaveLine">Сохранить количество строчек</param>
		/// <param name="isSaveSize">Сохранить размер шрифта</param>
		/// <param name="isSaveLineSpacing">Сохранить межстрочный интервал</param>
		/// <returns>true - текст выравнен, false - текст не выравнен</returns>
		virtual bool AlignTextBox(Vector2f sizeBox, bool isSaveLine, bool isSaveSize, bool isSaveLineSpacing);
		/// <summary>
		/// Возврaт позиции
		/// </summary>
		/// <returns>Позиция</returns>
		virtual Vector2f getPosition() override;
		/// <summary>
		/// Возврaт видимости
		/// </summary>
		/// <returns>Видимость</returns>
		virtual bool getVisible() override;
		/// <summary>
		/// Возврaт цвета
		/// </summary>
		/// <returns>Цвет</returns>
		virtual Color getColor() override;
		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="color">Цвет</param>
		virtual void setColor(Color color) override;
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
		/// Возврaт межстрочного интервала
		/// </summary>
		/// <returns>Межстрочный интервал</returns>
		virtual float getLineSpacing();
		/// <summary>
		/// Ввод межстрочного интервала
		/// </summary>
		/// <param name="lineSpacing">Межстрочный интервал</param>
		virtual void setLineSpacing(float lineSpacing);
		/// <summary>
		/// Возврaт размера
		/// </summary>
		/// <returns>Размер</returns>
		virtual Vector2f getOriginalDimensions() override;
		/// <summary>
		/// Возврaт размера
		/// </summary>
		/// <returns>Размер</returns>
		virtual Vector2f getScaleDimensions() override;
		/// <summary>
		/// Возврaт размера
		/// </summary>
		/// <returns>Размер</returns>
		virtual Vector2f getRealDimensions() override;
	};
}