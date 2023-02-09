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
	/// ����������
	/// </summary>
	/// <param name="window">����</param>
	sceneWin(RenderWindow &window)
	{
		status = Main;
		winBackgraund.Reload("winBackgraund");
		winText.Reload("winText");
		buttonMenu.Reload("buttonMenu");
	}
	/// <summary>
	/// ����������
	/// </summary>
	~sceneWin()
	{
		buttonMenu.Delete();
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
		case sceneWin::Main:
			if (buttonMenu.Pressed(event, window)) { /*clickSound.play();*/ return SCENE_MAIN_MENU; }
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
			case sceneWin::Main:
				winBackgraund >> window;
				winText >> window;
				buttonMenu >> window;
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
		if (scene == NULL) scene = new sceneWin(window);
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
Scene* sceneWin::scene;
