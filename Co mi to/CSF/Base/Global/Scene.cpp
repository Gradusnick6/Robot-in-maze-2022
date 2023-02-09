#include "Scene.h"

void csf::Scene::EventWindow(RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}

}

int csf::Scene::playScene(Scene* scene, RenderWindow& window)
{
	int Choise = 0;
	while (window.isOpen() && Choise == 0)
	{
		scene->EventWindow(window);
		Choise = scene->Update(window);
		scene->Draw(window);
	}
	scene->Reborn();
	return Choise;
}
