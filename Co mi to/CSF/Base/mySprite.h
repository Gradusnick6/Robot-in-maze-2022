#pragma once
#include "BaseObject.h"
#include "TextureBank.h"

namespace csf
{
	/// <summary>
	/// Графический объект
	/// </summary>
	class mySprite :public BaseObject
	{
	protected:
		enum TypeForm{ useSprite,useShape } typeForm;
		/// <summary>
		/// Банк текстур
		/// </summary>
		static TextureBank* textureBank;

		Shape* shape;
		Sprite sprite;
		
		/// <summary>
		/// Обновление размеров
		/// </summary>
		virtual void updateDimentions();
		/// <summary>
		/// Обновление позиции
		/// </summary>
		virtual void updateLocation();
		/// <summary>
		/// Смена цвета при активации
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningChangeColor(bool awakening) override;
		/// <summary>
		/// Смена изображения при активации
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningChangeFrame(bool awakening) override;
		/// <summary>
		/// Смена масштаба при активации
		/// </summary>
		/// <param name="Awakening">Активация объекта</param>
		virtual void AwakeningChangeScale(bool awakening) override;
	public:
		/// <summary>
		/// Конструктор
		/// </summary>
		mySprite();
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		mySprite(string name, float x = -1, float y = -1);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="location">Позиция</param>
		mySprite(string name, Vector2f location);
		/// <summary>
		/// Конструктор
		/// </summary>
		/// <param name="name">Спрайт</param>
		mySprite(const Sprite& sprite);
		/// <summary>
		/// Конструктор
		/// !!! НЕОБХОДИМО ВЫЗЫВАТЬ МЕТОД DELETE ДЛЯ ОЧИЩЕНИЯ ДИНАМИЧЕСКОЙ ПАМЯТИ !!!
		/// </summary>
		/// <param name="name">Указатель на фигуру. </param>
		mySprite(Shape* shape);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="x">Позиция по х</param>
		/// <param name="y">Позиция по y</param>
		void Reload(string name, float x = -1, float y = -1);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		/// <param name="location">Позиция</param>
		void Reload(string name, Vector2f location);
		/// <summary>
		/// Обновить данные
		/// </summary>
		/// <param name="name">Спрайт</param>
		void Reload(const Sprite& sprite);
		/// <summary>
		/// Обновить данные
		/// !!! НЕОБХОДИМО ВЫЗЫВАТЬ МЕТОД DELETE ДЛЯ ОЧИЩЕНИЯ ДИНАМИЧЕСКОЙ ПАМЯТИ !!!
		/// </summary>
		/// <param name="name">Указатель на фигуру. </param>
		void Reload(Shape* shape);
		/// <summary>
		/// Вывод в окно без анимации
		/// </summary>
		/// <param name="window">Окно</param>
		virtual void operator>(RenderWindow & window) override;
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="x">Позиция по x</param>
		/// <param name="y">Позиция по y</param>
		virtual void setPosition(float x, float y);
		/// <summary>
		/// Ввод позиции
		/// </summary>
		/// <param name="_location">Позиция</param>
		virtual void setPosition(Vector2f _location);
		/// <summary>6n                           
		/// Ввод новой текстуры
		/// </summary>
		/// <param name="name">Имя текстуры</param>
		virtual void setTexture(string name);
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
		virtual void setOrigin(float x, float y) override;
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
		virtual void setTextureRect(FloatRect textureRect) override;
		/// <summary>
		/// Ввод типа активации объекта
		/// </summary>
		/// <param name="i">Тип активации объекта</param>
		virtual void setAwakeningType(AwakeningTypes AwakeningType) override;
		/// <summary>
		/// Вернуть спрайт
		/// </summary>
		/// <returns>Спрайт</returns>
		virtual Sprite getSprite();
		/// <summary>
		/// Ввод банка текстур
		/// </summary>
		/// <param name="external">Ввести банк текстур</param>
		static void setСurrentTextureBank(TextureBank* external);
		/// <summary>
		/// Удаление всех объектов из динамической памяти
		/// Необходим при использовании Shape
		/// </summary>
		virtual void Delete();
		/// <summary>
		/// Возврат банка текстур
		/// </summary> 
		/// <param name="external">Банк текстур</param>
		/// <returns></returns>
		static TextureBank* getСurrentTextureBank(TextureBank* external);
	};
}
