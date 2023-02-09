#pragma once
#include "BaseObject.h"
namespace csf
{
	/// <summary>
	/// Объединение объектов
	/// </summary>
	class Carcas : public BaseObject
	{
	protected:
		vector<BaseObject*> Objects;

		/// <summary>
		/// Расчёт реальных размеров каркаса
		/// </summary>
		virtual void updateRealDimensions();
		/// <summary>
		/// Расчёт размеров каркаса
		/// </summary>
		virtual void updateDimensions();
		/// <summary>
		/// Ввести позицию объекта, относительно главного объекта
		/// </summary>
		/// <param name="Object">Ссылка на объект</param>
		/// <param name="x">Позиция по х относительно главного объекта</param>
		/// <param name="y">Позиция по y относительно главного объекта</param>
		virtual void setPositionObject(BaseObject* Object, float x, float y);
		/// <summary>
		/// Ввести прямоугольник текстуры
		/// </summary>
		/// <param name="textureRect">Прямоугольник тектуры. Не используется, может быть любым</param>
		virtual void setTextureRect(FloatRect textureRect) override;
		/// <summary>
		/// Обновить позиции объектов. 
		/// Функция пустышка. 
		/// Необходимо переопределение
		/// </summary>
		void updateConfiguration();
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		Carcas();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="object">Главный объект</param>
		Carcas(BaseObject* object);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="object">Главный объект</param>
		void Reload(BaseObject* object);

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
		/// Ввод позиции
		/// </summary>
		/// <param name="_location">Позиция</param>
		virtual void setPosition(Vector2f _location);
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setPosition(float x, float y) override;
		/// <summary>
		/// Ввод цвета активации
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		virtual void setColorAwakening(int red, int green, int blue, int alpha = -1) override;
		/// <summary>
		/// Ввод масштаба активации
		/// </summary>
		/// <param name="scale">Масштаб</param>
		virtual void setScaleAwakening(Vector2f scale) override;
		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="red">Красный</param>
		/// <param name="green">Зелёный</param>
		/// <param name="blue">Синий</param>
		/// <param name="alpha">Прозрачность</param>
		virtual void setColor(int red, int green, int blue, int alpha = -1) override;
		/// <summary>
		/// Ввод точки позции объекта
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setOrigin(float x, float y);
		/// <summary>
		/// Ввод цвета
		/// </summary>
		/// <param name="color">Цвет</param>
		virtual void setColor(Color color) override;
		/// <summary>
		/// Ввод видимости
		/// </summary>
		/// <returns>Видимость</returns>
		virtual void setVisible(bool visible) override;
		/// <summary>
		/// Ввод активности объектов 
		/// </summary>
		/// <returns>Активность объектов</returns>
		virtual void setEnable(bool enable) override;
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
		/// Ввести прямоугольник текстуры
		/// </summary>
		/// <param name="textureRect">Прямоугольник тектуры</param>
		/// <param name="index">Индекс объекта</param>
		virtual void setTextureRect(FloatRect textureRect, int index);
		/// <summary>
		/// Ввести прямоугольник маски
		/// </summary>
		/// /// <param name="maskRect">Прямоугольник маски</param>
		virtual void setMaskRect(FloatRect maskRect);
		/// <summary>
		/// Добавить объект
		/// </summary>
		/// <param name="object">Ссылка на объект</param>
		virtual void setObject(BaseObject* object);
		/// <summary>
		/// Ввести позицию объекта, относительно главного объекта
		/// </summary>
		/// <param name="index">Индекс объекта</param>
		/// <param name="x">Позиция по х относительно главного объекта</param>
		/// <param name="y">Позиция по y относительно главного объекта</param>
		void setPositionObject(int index, float x, float y);/// <summary>
		/// Ввести позицию объекта, относительно главного объекта
		/// </summary>
		/// <param name="name">Имя объекта</param>
		/// <param name="x">Позиция по х относительно главного объекта</param>
		/// <param name="y">Позиция по y относительно главного объекта</param>
		void setPositionObject(string name, float x, float y);
		/// <summary>
		/// Удаление всех объектов из динамической памяти
		/// </summary>
		virtual void Delete() override;
	};
}