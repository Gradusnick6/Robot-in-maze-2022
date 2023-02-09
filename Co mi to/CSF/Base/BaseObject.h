#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

namespace csf
{
	/// <summary>
	/// Объект
	/// </summary>
	class BaseObject
	{
	public:
		/// <summary>
		/// Тип активации при наведении
		/// nonAwakening — без активации,
		/// ChangeColor — смена цвета,
		/// ChangeFrame — смена изображения,
		/// Scale — изменение масштаба,
		/// Outline — обводка,
		/// Other — другое
		/// </summary>
		enum AwakeningTypes {nonAwakening, ChangeColor, ChangeFrame, ChangeScale, Outline, Other};
	
	protected:
		AwakeningTypes AwakeningType;

		Color color;
		Color colorAwakening;

		Vector2f location;
		Vector2f originLocation;
		Vector2f maskLocation;
		Vector2f realLocation;

		Vector2f originalDimensions;
		Vector2f scaleDimensions;
		Vector2f realDimensions;
		
		String name;
		bool visible;
		bool enable;
		bool awakening;

		Vector2f origin;
		float rotate;

		Vector2f scale;
		Vector2f scaleAwakening;

		FloatRect textureRect;
		FloatRect maskRect;
		FloatRect maskTextureRect;


		/// <summary>
		/// Конструктор
		/// </summary>
		BaseObject();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		/// <param name="name">Имя объекта</param>
		BaseObject(float x, float y, string name);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="location">Позиция</param>
		/// <param name="name">Имя объекта</param>
		BaseObject(Vector2f location, string name);

		/// <summary>
		/// Вернуть изменения цвета. Если канал равен -1, то он не меняется
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		/// <returns>Изменения цвета</returns>
		virtual Color getUpdateColor(Color prev, int red, int green, int blue, int alpha);
		/// <summary>
		/// Возврат точки с координатами, полученными поворотом искомой точки
		/// </summary>
		/// <param name="pos">искомая точка</param>
		/// <param name="centre">точка, относительно которой осуществлеяется поворт</param>
		/// <param name="angle">угол поворота</param>
		Vector2f Rotate(Vector2f pos, Vector2f centre, float angle);

		/// <summary>
		/// Смена цвета при активации
		/// !!! ФУНКЦИЯ ПУСТЫШКА. НЕОБХОДИМО ПЕРЕОПРЕДЕЛЕНИЕ !!!
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningChangeColor(bool awakening);
		/// <summary>
		/// Смена изображения при активации
		/// !!! ФУНКЦИЯ ПУСТЫШКА. НЕОБХОДИМО ПЕРЕОПРЕДЕЛЕНИЕ !!!
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningChangeFrame(bool awakening);
		/// <summary>
		/// Смена масштаба при активации
		/// !!! ФУНКЦИЯ ПУСТЫШКА. НЕОБХОДИМО ПЕРЕОПРЕДЕЛЕНИЕ !!!
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningChangeScale(bool awakening);
		/// <summary>
		/// Обводка при активации
		///  !!! ФУНКЦИЯ ПУСТЫШКА. НЕОБХОДИМО ПЕРЕОПРЕДЕЛЕНИЕ !!!
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningOutline(bool awakening);
		/// <summary>
		/// Другое при активации
		///  !!! ФУНКЦИЯ ПУСТЫШКА. НЕОБХОДИМО ПЕРЕОПРЕДЕЛЕНИЕ !!!
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningOther(bool awakening);

	public:
		/// <summary>
		/// Вывод в окно без анимации
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void operator>(RenderWindow & window) = 0;
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setPosition(float x, float y) = 0;
		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		virtual void setColor(int red, int green, int blue, int alpha = -1) = 0;
		/// <summary>
		/// Ввод точки позиции объекта
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setOrigin(float x, float y) = 0;
		/// <summary>
		/// Ввод масштаба объекта
		/// </summary>
		/// <param name="x">Масштаба по x</param>
		/// <param name="y">Масштаба по y</param>
		virtual void setScale(float x, float y) = 0;
		/// <summary>
		/// Ввод поворота объекта
		/// </summary>
		/// <param name="angle">Угол поворота в градусах</param>
		virtual void setRotate(float angle) = 0;
		/// <summary>
		/// Ввести прямоугольник текстуры
		/// </summary>
		/// <param name="textureRect">Прямоугольник тектуры</param>
		virtual void setTextureRect(FloatRect textureRect) {};

		/// <summary>
		/// Возврaт позиции левого вехнего угла объекта
		/// </summary>
		/// <returns>Позиция</returns>
		virtual Vector2f getPosition();
		/// <summary>
		/// Возврaт позиции
		/// </summary>
		/// <returns>Позиция</returns>
		virtual Vector2f getOriginPosition();
		/// <summary>
		/// Возврaт позиции с учётом маски
		/// </summary>
		/// <returns>Позиция</returns>
		virtual Vector2f getMaskPosition();
		/// <summary>
		/// Возврaт позиции
		/// </summary>
		/// <returns>Позиция</returns>
		virtual Vector2f getRealPosition();
		/// <summary>
		/// Вывод в окно без активации
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void Draw(RenderWindow& window);
		/// <summary>
		/// Вывод в окно с активацией
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void DrawAwakening(RenderWindow& window);
		/// <summary>
		/// Возврaт указателя на объект
		/// </summary>
		/// <returns>Указатель на объект</returns>
		virtual BaseObject* operator*();
		/// <summary>
		/// Проверка попал ли курсор на объект
		/// </summary>
		/// <param name="window">окно</param>
		/// <returns>true - курсор на объекте, false - курсор не на объекте</returns>
		virtual bool operator<(RenderWindow& window);
		/// <summary>
		/// Проверка попал ли пользователь на кнопку с активацией
		/// </summary>
		/// <param name="window">Окно</param>
		/// <returns>true - курсор на объекте, false - курсор не на объекте</returns>
		virtual bool operator<<(RenderWindow& window);
		/// <summary>
		/// Вывод в окно с активацией
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void operator>>(RenderWindow& window);
		/// <summary>
		/// Проверка попал ли курсор на объект
		/// </summary>
		/// <param name="window">окно</param>
		/// <returns>true - курсор на объекте, false - курсор не на объекте</returns>
		virtual bool isCursorOnObject(RenderWindow& window);
		/// <summary>
		/// Проверка попал ли пользователь на кнопку со сменой кадра
		/// </summary>
		/// <param name="window">окно</param>
		/// <returns>true - курсор на объекте, false - курсор не на объекте</returns>
		virtual bool isCursorOnObjectAwakening(RenderWindow& window);
		/// <summary>
		/// Ввод видимости
		/// </summary>
		/// <param name="visible">Видимость</param>
		virtual void setVisible(bool visible);
		/// <summary>
		/// Возврaт видимости
		/// </summary>
		/// <returns>Видимость</returns>
		virtual bool getVisible();
		/// <summary>
		/// Возврат активности объекта
		/// </summary>
		/// <returns>Активность объекта</returns>
		virtual bool getEnable();
		/// <summary>
		/// Ввод активности объекта
		/// </summary>
		/// <param name="enable">Активность объекта</param>
		virtual void setEnable(bool enable);
		/// <summary>
		/// Ввод имени объекта
		/// </summary>
		/// <param name="name">Имя объекта</param>
		virtual void setName(String name);
		/// <summary>
		/// Возврaт имени объекта
		/// </summary>
		/// <returns>Имя объекта</returns>
		virtual String getName();
		/// <summary>
		/// Ввод цвета активации
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		virtual void setColorAwakening(int red, int green, int blue, int alpha = -1);
		/// <summary>
		/// Ввод цвета активации
		/// </summary>
		/// <param name="color">Цвет</param>
		virtual void setColorAwakening(Color color);
		/// <summary>
		/// Возврaт цвета активации
		/// </summary>
		/// <returns>Цвет</returns>
		virtual Color getColorAwakening();
		/// <summary>
		/// Ввод масштаба активации
		/// </summary>
		/// <param name="scale">Масштаб</param>
		virtual void setScaleAwakening(Vector2f scale);
		/// <summary>
		/// Возврaт масштаба активации
		/// </summary>
		/// <returns>Масштаб</returns>
		virtual Vector2f getScaleAwakening();
		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="color">Цвет</param>
		virtual void setColor(Color color);
		/// <summary>
		/// Возврaт цвета
		/// </summary>
		/// <returns>Цвет</returns>
		virtual Color getColor();
		/// <summary>
		/// Ввод точки позции объекта
		/// </summary>
		/// <param name="origin">Точка позции объекта</param>
		virtual void setOrigin(Vector2f origin);
		/// <summary>
		/// Ввод масштаба объекта
		/// </summary>
		/// <param name="scale">Масштаб объекта</param>
		virtual void setScale(Vector2f scale);
		/// <summary>
		/// Вернуть точку позции объекта
		/// </summary>
		/// <returns>Точка позции объекта</returns>
		virtual Vector2f getOrigin();
		/// <summary>
		/// Вернуть масштаб объекта
		/// </summary>
		/// <returns>Масштаб объекта</returns>
		virtual Vector2f getScale();
		/// <summary>
		/// Вернуть поворот
		/// </summary>
		/// <returns>Угол поворота</returns>
		virtual float getRotate();
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="_location">Позиция</param>
		virtual void setPosition(Vector2f _location);
		/// <summary>
		/// Возврaт исходных рaзмеров
		/// </summary>
		/// <returns>Размер</returns>
		virtual Vector2f getOriginalDimensions();
		/// <summary>
		/// Возврaт рaзмеров с учётом масштаба. 
		/// Без учёта масштаба адаптации
		/// </summary>
		/// <returns>Размер</returns>
		virtual Vector2f getScaleDimensions();
		/// <summary>
		/// Возврaт реальных рaзмеров в окне
		/// </summary>
		/// <returns>Размер</returns>
		virtual Vector2f getRealDimensions();
		/// <summary>
		/// Скролинг
		/// !!! ФУНКЦИЯ ПУСТЫШКА. НЕОБХОДИМО ПЕРЕОПРЕДЕЛЕНИЕ !!!
		/// </summary>
		/// <param name="scrolling">процент скролинга</param>
		/// <returns>false</returns>
		virtual bool setScrolling(float scrolling);
		/// <summary>
		/// Ввод активации объекта
		/// </summary>
		/// <param name="awakening">Активация объекта</param>
		virtual void setAwakening(bool awakening);
		/// <summary>
		/// Ввод типа активации объекта
		/// </summary>
		/// <param name="AwakeningType">Тип активации объекта</param>
		virtual void setAwakeningType(AwakeningTypes AwakeningType);
		/// <summary>
		/// Ввести прямоугольник маски.
		/// Не работает при загрзки Shape или при повороте.
		/// </summary>
		/// /// <param name="maskRect">Прямоугольник маски</param>
		virtual void setMaskRect(FloatRect maskRect);
		/// <summary>
		/// Возврaт рaтипа активации объекта
		/// </summary>
		/// <returns>Тип активации объекта</returns>
		virtual AwakeningTypes getAwakeningType();
		/// <summary>
		/// Вернуть прямоугольник в исходном размере
		/// </summary>
		/// <returns></returns>
		virtual FloatRect getOriginalRect();
		/// <summary>
		/// Вернуть прямоугольник с учётом масштаба. 
		/// Без учёта масштаба адаптации
		/// </summary>
		/// <returns></returns>
		virtual FloatRect getScaleRect();
		/// <summary>
		/// Вернуть прямоугольник в реальных размерах окна
		/// </summary>
		/// <returns></returns>
		virtual FloatRect getRealRect();
		/// <summary>
		/// Вернуть прямоугольник текстуры
		/// </summary>
		/// <returns>Прямоугольник текстуры</returns>
		virtual FloatRect getTextureRect();
		/// <summary>
		/// Вернуть прямоугольник текстуры маски
		/// </summary>
		/// <returns>Прямоугольник маски</returns>
		virtual FloatRect getMaskTextureRect();
		/// <summary>
		/// Вернуть прямоугольник маски
		/// </summary>
		/// <returns>Прямоугольник маски</returns>
		virtual FloatRect getMaskRect();
		/// <summary>
		/// Вернуть левую верхнюю точку объекта в реальных координатах.
		/// Левая верхняя точка — это левая верхняя точка объекта при повороте 0 градусов
		/// </summary>
		/// <returns>Координаты левой верхней точки</returns>
		virtual Vector2f getRealPositionLeftUpper();
		/// <summary>
		/// Вернуть правую верхнюю точку объекта в реальных координатах.
		/// Правая верхняя точка — это правая верхняя точка объекта при повороте 0 градусов
		/// </summary>
		/// <returns>Координаты правой верхней точки</returns>
		virtual Vector2f getRealPositionRightUpper();
		/// <summary>
		/// Вернуть левую нижнюю точку объекта в реальных координатах.
		/// Левая нижняя точка — это левая нижняя точка объекта при повороте 0 градусов
		/// </summary>
		/// <returns>Координаты левой нижней точки</returns>
		virtual Vector2f getRealPositionLeftDown();
		/// <summary>
		/// Вернуть правую нижнюю точку объекта в реальных координатах.
		/// Правая нижняя точка — это правая нижняя точка объекта при повороте 0 градусов
		/// </summary>
		/// <returns>Координаты правой нижней точки</returns>
		virtual Vector2f getRealPositionRightDown();
		/// <summary>
		/// Удаление всех объектов из динамической памяти
		/// В данном случае ничего не делает
		/// </summary>
		virtual void Delete();
	};
}