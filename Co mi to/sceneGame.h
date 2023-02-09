#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "csf.h"
#include "ScenesDefine.h"

using namespace sf;
using namespace std;
using namespace csf;

class sceneGame : Scene
{
	enum Status { Main, TextBox, ExportWindow, isExportWindow } status;
	enum RobotStatus { Write, Work, Start, Win } robotStatus;

	static Scene* scene;

	static int difficulty;

	mySprite backgraundGame;
	Button buttonToMenu;
	ComboBox comboboxMovement, comboboxOperators, comboboxCriterion;

public: 
	sceneGame(RenderWindow& window) :sceneGame(window, 2) {}
	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="window">����</param>
	sceneGame(RenderWindow &window, int difficulty_)
	{
		robotStatus = Write;
		status = Main;

		backgraundGame.Reload("backgraundGame");

		buttonToMenu.Reload("buttonToMenu");

		comboboxMovement.Reload("comboboxMovement", 4);
		comboboxOperators.Reload("comboboxOperators", 5);
		comboboxCriterion.Reload("comboboxCriterion", 6);

	}
	/// <summary>
	/// ����������
	/// </summary>
	~sceneGame()
	{
		buttonToMenu.Delete();
		comboboxMovement.Delete();
		comboboxOperators.Delete();
		comboboxCriterion.Delete();
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
		case sceneGame::Main:
			if (buttonToMenu.Pressed(event, window)) 
			{ /*clickSound.play();*/ return SCENE_MAIN_MENU; }
			break;
		case sceneGame::TextBox:
			break;
		case sceneGame::ExportWindow:
			break;
		case sceneGame::isExportWindow:
			break;
		default:
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
			case sceneGame::Main:
				backgraundGame > window;

				buttonToMenu >> window;

				comboboxMovement >> window;
				comboboxOperators >> window;
				comboboxCriterion >> window;

				if (Plate::getMovingPlate() != NULL) Plate::getMovingPlate()->operator>>(window);
				break;
			case sceneGame::TextBox:
				break;
			case sceneGame::ExportWindow:
				break;
			case sceneGame::isExportWindow:
				break;
			default:
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
	static Scene* getScene(RenderWindow &window, int difficulty_)
	{
		if (scene == NULL) scene = new sceneGame(window, difficulty_);
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
Scene* sceneGame::scene;
