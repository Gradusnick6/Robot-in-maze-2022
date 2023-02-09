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
	/// ����������
	/// </summary>
	/// <param name="window">����</param>
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
	/// ����������
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
	/// ����������/��������� ���a
	/// </summary>
	/// <param name="window">����</param>
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
	/// ��������a �������� �����
	/// </summary>
	/// <param name="window">����</param>
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
	/// �������� �a���� ���a
	/// </summary>
	virtual void Reborn() override
	{
		
	}
	/// <summary>
	/// �������� �����
	/// </summary>
	/// <param name="window">����</param>
	/// <returns>������� ����� ������ �� ������ ����� ���� � �� ���� ��� ������� ������������ ������ �� ������ �����</returns>
	static Scene* getScene(RenderWindow &window)
	{
		if (scene == NULL) scene = new sceneMainMenu(window);
		return scene;
	}
	/// <summary>
	/// �����a� ������a �����
	/// </summary>
	/// <returns>������� ������ �� ������ �����</returns>
	static Scene* getScene() { return scene; }
	/// <summary>
	/// ������� ���������� �� �����
	/// </summary>
	/// <returns>true � ����� ����������, false � ����� �� ����������</returns>
	static bool isScene()
	{
		if (scene == NULL) return false;
		return true;
	}
};
Scene* sceneMainMenu::scene;
