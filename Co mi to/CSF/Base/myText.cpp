#include "myText.h"

namespace csf
{
	Font myText::font;

	int myText::strToNum(string s)
	{
		int i;
		char temp[20];
		for (int i = 0; i < (int)s.length(); i++)
			temp[i] = s[i];
		temp[s.length()] = '\0';
		i = atoi(temp);
		return i;
	}

	float myText::strToNum_f(string s)
	{
		float i;
		char temp[20];
		for (int i = 0; i < (int)s.length(); i++)
			temp[i] = s[i];
		temp[s.length()] = '\0';
		i = (float)atof(temp);
		return i;
	}

	bool myText::getFitInBoxWidth(int widthBox)
	{
		if (widthBox > scaleDimensions.x) return true;
		return false;
	}

	bool myText::getFitInBoxHeight(int heightBox)
	{
		if (heightBox > scaleDimensions.y) return true;
		return false;
	}

	bool myText::getFitInBox(Vector2f sizeBox)
	{
		if (getFitInBoxWidth((int)sizeBox.x) && getFitInBoxHeight((int)sizeBox.y)) return true;
		return false;
	}

	String myText::DeleteParagraphs(String name)
	{
		size_t indexNextLine = name.find(L'\n');
		while (indexNextLine != String::InvalidPos)
		{
			indexNextLine = name.find(L'\n');
			if (indexNextLine != String::InvalidPos) name[indexNextLine] = L' ';
		}
		
		return name;
	}

	void myText::updateDimentions()
	{
		FloatRect frL = text.getLocalBounds();
		Vector2f temp;
		temp.x = (float)(frL.left + frL.width);
		temp.y = (float)size;
		originalDimensions.x = temp.x;
		originalDimensions.y = temp.y;

		scaleDimensions.x = originalDimensions.x * scale.x;
		scaleDimensions.y = originalDimensions.y * scale.y;
		FloatRect frG = text.getGlobalBounds();
		realDimensions.x = frG.width;
		realDimensions.y = frG.height;
		updateLocation();
	}

	void myText::updateLocation()
	{
		FloatRect fr = text.getGlobalBounds();
		realLocation.x = fr.left;
		realLocation.y = fr.top;
	}

	void myText::setFont(Font& newFont)
	{
		font = newFont;
	}

	Font myText::getFont()
	{
		return font;
	}

	myText::myText() 
		:BaseObject()
	{
		setPosition(0, 0);
		this->name = L"Error";
		this->size = 14;
		this->maxLenght = 100;
		horizontalAlignmentType = HNoAlignment;
		verticalAlignmentType = VNoAlignment;
	}

	myText::myText(float x, float y, String name, int size)
		:BaseObject(x, y, name)
	{
		this->name = name;
		this->size = size;
		horizontalAlignmentType = HNoAlignment;
		verticalAlignmentType = VNoAlignment;
		text.setFont(font);
		setSize(size);
		setStyle(Text::Regular);
		setColor(0, 0, 0);
		setString(this->name);
	}

	myText::myText(Vector2f location, String name, int size)
		:myText(location.x, location.y, name, size) {};

	void myText::Reload(String name, float x, float y)
	{
		*this = myText(x, y, name, 14);
	}

	void myText::Reload(float x, float y, String name, int size)
	{
		*this = myText(x, y, name, size);
	}

	void myText::Reload(Vector2f location, String name, int size)
	{
		*this = myText(location, name, size);
	}

	void myText::setColor(int red, int green, int blue, int alpha)
	{
		color = getUpdateColor(color, red, green, blue, alpha);
		text.setFillColor(color);
	}

	void myText::setOrigin(float x, float y)
	{
		origin.x = x;
		origin.y = y;
		originLocation = Vector2f(location.x + origin.x * scale.x, location.y + origin.y * scale.y);
	}

	void myText::operator>(RenderWindow& window)
	{
		text.setString(name);
		window.draw(text);
		m_textChanged = false;
	}

	void myText::operator>>(RenderWindow& window)
	{
		operator>(window);
	}

	void myText::setPosition(float x, float y)
	{
		originLocation = Vector2f(x, y);
		textureRect.left = x - origin.x * scale.x;
		textureRect.top = y - origin.y * scale.y;
		
		switch (horizontalAlignmentType)
		{
		case csf::myText::Left:
			location.x = textureRect.left;
			break;
		case csf::myText::HCentre:
			location.x = textureRect.left + textureRect.width * 0.5f - scaleDimensions.x * 0.5f;
			break;
		case csf::myText::Right:
			location.x = textureRect.left + textureRect.width - scaleDimensions.x;
			break;
		case csf::myText::HNoAlignment:
			location.x = textureRect.left;
			break;
		}

		switch (verticalAlignmentType)
		{
		case csf::myText::Up:
			location.y = textureRect.top;
			break;
		case csf::myText::VCentre:
			location.y = textureRect.top + textureRect.height * 0.5f - scaleDimensions.y * 0.5f;
			break;
		case csf::myText::Down:
			location.y = textureRect.top + textureRect.height - scaleDimensions.y;
			break;
		case csf::myText::VNoAlignment:
			location.y = textureRect.top;
			break;
		}
		
		location = Rotate(location, originLocation, rotate);
		auto temp = text.getLocalBounds();
		maskLocation = location;
		text.setPosition(location.x /*- temp.left*/, 
						 location.y /*- temp.top*/);
		updateDimentions();
	}

	void myText::setPosition(Vector2f location)
	{
		BaseObject::setPosition(location);
	};

	void myText::setSize(int size)
	{
		this->size = size;
		text.setCharacterSize(size);
		updateDimentions();
		setPosition(originLocation);
	}

	void myText::setString(String name)
	{
		this->name = name;
		text.setString(name);
		updateDimentions();
		setPosition(originLocation);
	}

	bool myText::Input(Event& event)
	{
		if (event.type == Event::TextEntered)
		{
			m_textChanged = true;
			switch (event.text.unicode)
			{
			case 0xD: //Return
				m_textChanged = false;
				event.type = Event::MouseMoved;
				return true;
				break;
			case 0x8://Backspace
				if (!name.isEmpty()) {
					name.erase(name.getSize() - 1);
					event.type = Event::MouseMoved;
				}
				break;
			default:
			{
				if ((int)name.getSize() <= maxLenght) 
				{ 
					name += static_cast<wchar_t>(event.text.unicode); 
					event.type = Event::MouseMoved;
				}
			} break;
			}
		}
		return false;
	}

	void myText::Clear()
	{
		name = "";
		text.setString(name);
		updateDimentions();
		setPosition(originLocation);
	}

	int myText::getLength()
	{
		return (int)name.getSize();
	}

	String myText::getString()
	{
		return name;
	}

	void myText::Refresh()
	{
		text.setFont(font);
		text.setFillColor(color);
		updateDimentions();
		setPosition(originLocation);
	}

	void myText::setMaxLenght(int maxLenght)
	{
		this->maxLenght = maxLenght;
	}

	void myText::setTextRect(FloatRect textRect)
	{
		textureRect = textRect;
		setPosition(textureRect.left, textureRect.top);
		//int saveSize = size;
		//while (!getFitInBox(sizeBox))
		//{
		//	if (size < 1) { setSize(saveSize); updateDimentions(); return false; }
		//	setSize(size - 1);
		//	updateDimentions();
		//}
	}

	size_t myText::Find(String str, size_t start)
	{
		size_t temp = name.find(str, start);
		return temp != String::InvalidPos ? temp : -1;
	}
	void myText::setScale(float x, float y)
	{
		scale.x = x;
		scale.y = y;
		text.setScale(scale.x, scale.y);
		setPosition(originLocation);
	}
	void myText::setRotate(float angle)
	{
		rotate = angle;
		text.setRotation(rotate);
		setPosition(originLocation);
	}
	void myText::setOutlineColor(Color outlineColor)
	{
		this->outlineColor = outlineColor;
		text.setOutlineColor(outlineColor);
	}
	void myText::setOutlineThickness(float outlineThickness)
	{
		this->outlineThickness = outlineThickness;
		text.setOutlineThickness(outlineThickness);
		setPosition(originLocation);
	}
	void myText::setLetterSpacing(float letterSpacing)
	{
		this->letterSpacing = letterSpacing;
		text.setLetterSpacing(letterSpacing);
		setPosition(originLocation);
	}
	void myText::setStyle(Text::Style style)
	{
		this->style = style;
		text.setStyle(style);
		setPosition(originLocation);
	}
	void myText::setHorizontalAlignmentType(HorizontalAlignmentType horizontalAlignmentType)
	{
		this->horizontalAlignmentType = horizontalAlignmentType;
	}
	void myText::setVerticalAlignmentType(VerticalAlignmentType verticalAlignmentType)
	{
		this->verticalAlignmentType = verticalAlignmentType;
	}
	void myText::setAlignmentType(HorizontalAlignmentType horizontalAlignmentType, VerticalAlignmentType verticalAlignmentType)
	{
		setHorizontalAlignmentType(horizontalAlignmentType);
		setVerticalAlignmentType(verticalAlignmentType);
	}
	Color myText::getOutlineColor()
	{
		return outlineColor;
	}
	float myText::getOutlineThickness()
	{
		return outlineThickness;
	}
	float myText::getLetterSpacing()
	{
		return letterSpacing;
	}
	Text::Style myText::getStyle()
	{
		return style;
	}
	myText::HorizontalAlignmentType myText::getHorizontalAlignmentType()
	{
		return horizontalAlignmentType;
	}
	myText::VerticalAlignmentType myText::getVerticalAlignmentType()
	{
		return verticalAlignmentType;
	}
}