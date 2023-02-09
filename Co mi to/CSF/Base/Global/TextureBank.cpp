#include "TextureBank.h"


namespace csf
{
	void TextureBank::setTextureBank(string Way)
	{
		string buffer, name;
		int x, y;
		ifstream F(Way + INFORMATIONFORIMAGE);
		if (F)
		{
			do
			{
				F >> name;
				F >> buffer; x = stoi(buffer);
				F >> buffer; y = stoi(buffer);
				myTexture *bufferTexture = new myTexture(Way, name, x, y);
				texture.push_back(*bufferTexture);
				delete bufferTexture;
			} while (!F.eof());
			F.close();
		}
	}

	myTexture& TextureBank::operator[](int index)
	{
		return getTexture(index);
	}

	myTexture& TextureBank::operator[](string Name)
	{
		return getTexture(Name);
	}

	myTexture& TextureBank::getTexture(int index)
	{
		if (index <= 0 || index >= (int)texture.size())
			return texture[0];
		return texture[index];
	}

	myTexture& TextureBank::getTexture(string Name)
	{
		for (int i = 1; i < (int)texture.size(); i++)
		if (Name == texture[i].getName())
			return texture[i];
		return texture[0];
	}
}