#include <SFML/Graphics.hpp>
#include <ctime>
#include "sceneMainMenu.h"
#include "sceneGame.h"
#include "sceneWin.h"

using namespace sf;
using namespace std;

Music mainMusic;

void mainWindow(RenderWindow& window)
{
	TextureBank* textureBank = new TextureBank;
	textureBank->setTextureBank("resources/Image/1920_1080/");
	mySprite::setÑurrentTextureBank(textureBank);
	bool isTextureLoadedMainMenu = false, isTextureLoadedGame = false, isTextureLoadedWin = false;

	int choise = SCENE_MAIN_MENU;
	int choiseDifficulty = 2;
	while (window.isOpen())
	{
		switch (choise)
		{
		case SCENE_MAIN_MENU:
			if (!isTextureLoadedMainMenu)
			{
				textureBank->setTextureBank("resources/Image/1920_1080/SceneMainMenu/");
				isTextureLoadedMainMenu = true;
			}
			choise = Scene::playScene(sceneMainMenu::getScene(window), window);
			break;
		case SCENE_GAME_EASY:
			choiseDifficulty = 1;
			choise = SCENE_GAME;
			break;
		case SCENE_GAME_MEDIUM:
			choiseDifficulty = 2;
			choise = SCENE_GAME;
			break;
		case SCENE_GAME_HARD:
			choiseDifficulty = 3;
			choise = SCENE_GAME;
			break;
		case SCENE_GAME: 
			if (!isTextureLoadedGame)
			{
				textureBank->setTextureBank("resources/Image/1920_1080/SceneGame/");
				isTextureLoadedGame = true;
			}
			choise = Scene::playScene(sceneGame::getScene(window, choiseDifficulty), window);
			break;
		case SCENE_WIN:
			if (!isTextureLoadedWin)
			{
				textureBank->setTextureBank("resources/Image/1920_1080/SceneWin/");
				isTextureLoadedWin = true;
			}
			choise = Scene::playScene(sceneWin::getScene(window), window);
			break;
		case WINDOW_CLOSE: window.close(); break;
		default: window.close(); break;
		}
	}
	if (sceneGame::isScene() != NULL) delete sceneMainMenu::getScene();
	if (sceneGame::isScene() != NULL) delete sceneGame::getScene();
	if (sceneGame::isScene() != NULL) delete sceneWin::getScene();

	delete textureBank;
}


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	SizeWindow::setSizeWindow(Vector2i(1920, 1080), Vector2i(1366, 768), false);
	
	View view;
	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	
	RenderWindow window;
	window.create(VideoMode(SizeWindow::getRealDimentions().x, SizeWindow::getRealDimentions().y), L"Windows Name",
		SizeWindow::getIsFullScreen() ? sf::Style::Fullscreen : sf::Style::Close);
	
	Font font; font.loadFromFile("resources/font.ttf");
	myText::setFont(font);
	
	window.setView(view);
	mainWindow(window);
	
	return 0;
}
