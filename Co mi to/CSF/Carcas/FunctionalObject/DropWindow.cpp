#include "DropWindow.h"
#include "Carcas.h"
#include "mySprite.h"

csf::DropWindow::DropWindow()
	:Carcas(), DropFunctional()
{
	Box = NULL;
}

csf::DropWindow::DropWindow(BaseObject* master, BaseObject* Box)
	:Carcas(Box), DropFunctional(master, this)
{
	this->Box = Box;
}
csf::DropWindow::DropWindow(BaseObject* master, string name, float x, float y)
{
	mySprite* temp = new mySprite(name, x, y);
	*this = DropWindow(master, temp);
	Object = this;
}

void csf::DropWindow::Reload(BaseObject* master, BaseObject* Box)
{
	Delete();
	*this = DropWindow(master, Box);
	Object = this;
}

void csf::DropWindow::Reload(BaseObject* master, string name, float x, float y)
{
	Delete();
	*this = DropWindow(master, name, x, y);
	Object = this;
}