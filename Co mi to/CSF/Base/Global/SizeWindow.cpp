#include "SizeWindow.h"
#include <fstream>

namespace csf
{
	string SizeWindow::sizeWindow;
	Vector2i SizeWindow::originalDimentions;
	Vector2i SizeWindow::realDimentions;
	int SizeWindow::isFullScreen = true;
	int SizeWindow::isAdmin = false;
	Vector2f SizeWindow::scaleAdapting = Vector2f(1, 1);

	void SizeWindow::setSizeWindow(Vector2i Dimentions)
	{
		setSizeWindow(Dimentions, Dimentions, false);
	}

	void SizeWindow::setSizeWindow(Vector2i Dimentions, bool isFullScreen)
	{
		setSizeWindow(Dimentions, Dimentions, isFullScreen);
	}
	void SizeWindow::setSizeWindow(Vector2i originalDimentions, Vector2i realDimentions, bool isFullScreen)
	{
		SizeWindow::originalDimentions = originalDimentions;
		SizeWindow::realDimentions = realDimentions;
		SizeWindow::scaleAdapting.x = (float)realDimentions.x / (float)originalDimentions.x;
		SizeWindow::scaleAdapting.y = (float)realDimentions.y / (float)originalDimentions.y;
		SizeWindow::isFullScreen = isFullScreen;
		sizeWindow = to_string(realDimentions.x) + "_" + to_string(realDimentions.y) + "/";
	}
	string SizeWindow::getSizeWindow()
	{
		return sizeWindow;
	}
	Vector2i SizeWindow::getOriginalDimentions()
	{
		return originalDimentions;
	}
	Vector2i SizeWindow::getRealDimentions()
	{
		return realDimentions;
	}
	void SizeWindow::setIsFullScreen(bool isFullScreen)
	{
		SizeWindow::isFullScreen = isFullScreen;
	}
	void SizeWindow::setIsAdmin(bool isAdmin)
	{
		SizeWindow::isAdmin = isAdmin;
	}
	int SizeWindow::getIsFullScreen()
	{
		return isFullScreen;
	}
	int SizeWindow::getIsAdmin()
	{
		return isAdmin;
	}
	Vector2f SizeWindow::getScaleAdapting()
	{
		return scaleAdapting;
	}
}
