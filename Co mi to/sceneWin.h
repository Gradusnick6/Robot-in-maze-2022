#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "csf.h"
#include "ScenesDefine.h"


using namespace sf;
using namespace std;
using namespace csf;


class sceneWin : Scene
{
	enum Status{Main} status;

	static Scene* scene;
	mySprite winBackgraund, winText;
	Button buttonMenu;
public: 
	/// <summary>
	/// Констуктор
	/// </summary>
	/// <param name="window">Окно</param>
	sceneWin(RenderWindow &window)
	{
		status = Main;
		winBackgraund.Reload("winBackgraund");
		winText.Reload("winText");
		buttonMenu.Reload("buttonMenu");
	}
	/// <summary>
	/// Деструктор
	/// </summary>
	~sceneWin()
	{
		buttonMenu.Delete();
	}
	
	/// <summary>
	/// Обновление/Оживление окнa
	/// </summary>
	/// <param name="window">Окно</param>
	/// <returns></returns>
	virtual int Update(RenderWindow &window) override
	{
		switch (status)
		{
		case sceneWin::Main:
			if (buttonMenu.Pressed(event, window)) { /*clickSound.play();*/ return SCENE_MAIN_MENU; }
			break;
		}
		return SCENE_CONTINUE;
	}

	/// <summary>
	/// Отрисовкa объектов сцены
	/// </summary>
	/// <param name="window">Окно</param>
	virtual void Draw(RenderWindow &window) override
	{
		window.clear(); {
			switch (status)
			{
			case sceneWin::Main:
				winBackgraund >> window;
				winText >> window;
				buttonMenu >> window;
				break;
			}
		} window.display();
	}
	
	/// <summary>
	/// Удаление дaнных окнa
	/// </summary>
	virtual void Reborn() override
	{

	}
	/// <summary>
	/// Создание сцены
	/// </summary>
	/// <param name="window">Окно</param>
	/// <returns>Возврат новой ссылки на объект сцены если её не было или возврат существующей ссылки на объект сцены</returns>
	static Scene* getScene(RenderWindow &window)
	{
		if (scene == NULL) scene = new sceneWin(window);
		return scene;
	}
	/// <summary>
	/// Возврaт объектa сцены
	/// </summary>
	/// <returns>Возврат ссылки на объект сцены</returns>
	static Scene* getScene() { return scene; }
	/// <summary>
	/// Возврат существует ли сцена
	/// </summary>
	/// <returns>true — сцена существует, false — сцена не существует</returns>
	static bool isScene()
	{
		if (scene == NULL) return false;
		return true;
	}
};
Scene* sceneWin::scene;
