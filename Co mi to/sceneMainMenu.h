#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "csf.h"
#include "ScenesDefine.h"


using namespace sf;
using namespace std;
using namespace csf;


class sceneMainMenu : Scene
{
	enum Status{Main} status;

	static Scene* scene;

	mySprite WindowBackgraund, ChooseDifficulty, LogoFVS, NameGame, LogoTUSUR;
	Button buttonBeginner, buttonNormally, buttonProfessional, buttonExit;
	DropWindow dropWindowBeginner, dropWindowNormally, dropWindowProfessional;

public: 
	/// <summary>
	/// Констуктор
	/// </summary>
	/// <param name="window">Окно</param>
	sceneMainMenu(RenderWindow &window)
	{
		status = Main;

		WindowBackgraund.Reload("WindowBackgraund");
		ChooseDifficulty.Reload("ChooseDifficulty");
		LogoTUSUR.Reload("LogoTUSUR");
		LogoFVS.Reload("LogoFVS");
		NameGame.Reload("NameGame");

		buttonBeginner.Reload("buttonBeginner");
		buttonNormally.Reload("buttonNormally");
		buttonProfessional.Reload("buttonProfessional");
		buttonExit.Reload("buttonExit");

		dropWindowBeginner.Reload(*buttonBeginner, "dropWindowBeginner");
		dropWindowNormally.Reload(*buttonNormally, "dropWindowNormally");
		dropWindowProfessional.Reload(*buttonProfessional, "dropWindowProfessional");
	}
	/// <summary>
	/// Деструктор
	/// </summary>
	~sceneMainMenu()
	{
		buttonBeginner.Delete();
		buttonNormally.Delete();
		buttonProfessional.Delete();
		buttonExit.Delete();

		dropWindowBeginner.Delete();
		dropWindowNormally.Delete();
		dropWindowProfessional.Delete();
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
		case sceneMainMenu::Main:
			if (buttonBeginner.Pressed(event, window)) { /*clickSound.play();*/ return SCENE_WIN; } //SCENE_GAME_EASY; }
			if (buttonNormally.Pressed(event, window)) { /*clickSound.play();*/ return SCENE_GAME_MEDIUM; }
			if (buttonProfessional.Pressed(event, window)) { /*clickSound.play();*/ return SCENE_GAME_HARD; }
			if (buttonExit.Pressed(event, window) || Keyboard::isKeyPressed(Keyboard::Escape)) { return WINDOW_CLOSE; }

			dropWindowBeginner.Update(event, window);
			dropWindowNormally.Update(event, window);
			dropWindowProfessional.Update(event, window);
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
			case sceneMainMenu::Main:
				WindowBackgraund > window;
				ChooseDifficulty > window;
				LogoFVS > window;
				LogoTUSUR > window;
				NameGame > window;

				buttonBeginner >> window;
				buttonNormally >> window;
				buttonProfessional >> window;
				buttonExit >> window;

				dropWindowBeginner >> window;
				dropWindowNormally >> window;
				dropWindowProfessional >> window;
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
		if (scene == NULL) scene = new sceneMainMenu(window);
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
Scene* sceneMainMenu::scene;
