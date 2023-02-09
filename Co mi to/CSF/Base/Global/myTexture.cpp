#include "myTexture.h"


namespace csf
{
	myTexture::myTexture()
	{
		name = "Error";
		location.x = location.y = 0;
		dimensions.x = 660; dimensions.y = 600;
	}

	myTexture::myTexture(string way, string name, int x, int y)
	{
		this->name = name;
		texture.loadFromFile(way + name + ".png");
		Vector2u temp = texture.getSize();
		location.x = (float)x;
		location.y = (float)y;
		dimensions.x = (float)temp.x;
		dimensions.y = (float)temp.y;
		texture.setSmooth(true);
		texture.generateMipmap();
		texture.setRepeated(true);
	}
}