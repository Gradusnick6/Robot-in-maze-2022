#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "csf.h"


#define WINDOW_CLOSE -1
#define SCENE_CONTINUE 0
#define SCENE_GAME_SITUATION_1 1


using namespace sf;
using namespace std;
using namespace csf;


class sceneGame : Scene
{
	enum Status{Start, Game, Final} status;

	static Scene* scene;

public: 
	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="window">����</param>
	sceneGame(RenderWindow &window)
	{
		status = Start;
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
		case sceneGame::Start:
			
			break;

		case sceneGame::Game:
			
			break;

		case sceneGame::Final:
			
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
			case sceneGame::Start:
				
				break;
			case sceneGame::Game:
				
				break;
			case sceneGame::Final:
				
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
		if (scene == NULL) scene = new sceneGame(window);
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
