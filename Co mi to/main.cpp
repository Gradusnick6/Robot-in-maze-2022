#include <SFML/Graphics.hpp>
#include "sceneGame.h"
#include <ctime>


using namespace sf;
using namespace std;

Music mainMusic;

void mainWindow(RenderWindow& window)
{
	int choise = SCENE_GAME_SITUATION_1;
	while (window.isOpen())
	{
		switch (choise)
		{
		case SCENE_GAME_SITUATION_1: choise = Scene::playScene(sceneGame::getScene(window), window); break;
		case WINDOW_CLOSE: window.close(); break;
		default: window.close(); break;
		}
	}
	if (sceneGame::isScene() != NULL) delete sceneGame::getScene();
}


int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	//SizeWindow::setSizeWindow(Vector2i(1366, 768)/*, Vector2i(683, 384), false*/);
	//
	//View view;
	//view.reset(sf::FloatRect(0, 0, 1366, 768));
	//
	////view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 2.f));
	//
	//RenderWindow window;
	//window.create(VideoMode(SizeWindow::getRealDimentions().x, SizeWindow::getRealDimentions().y), L"Windows Name",
	//	SizeWindow::getIsFullScreen() ? sf::Style::Fullscreen : sf::Style::Close);
	//
	//TextureBank* textureBank = new TextureBank;
	//textureBank->setTextureBank("resources/Image/test/");
	//mySprite::set—urrentTextureBank(textureBank);
	//
	//Font font; font.loadFromFile("resources/comic.ttf");
	//myText::setFont(font);
	//
	//window.setView(view);
	//FloatRect temp = view.getViewport();
	//mainWindow(window);
	//
	//delete textureBank;
	return 0;
}
