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
	/// Констуктор
	/// </summary>
	/// <param name="window">Окно</param>
	sceneGame(RenderWindow &window)
	{
		status = Start;
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
	/// Отрисовкa объектов сцены
	/// </summary>
	/// <param name="window">Окно</param>
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
		if (scene == NULL) scene = new sceneGame(window);
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
Scene* sceneGame::scene;
