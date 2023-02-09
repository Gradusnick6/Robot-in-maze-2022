#include "MultilineText.h"

void csf::MultilineText::updateDimensions()
{
	Carcas::updateDimensions();
	myText::originalDimensions = Carcas::originalDimensions;
	myText::scaleDimensions = Carcas::scaleDimensions;
	myText::realDimensions = Carcas::realDimensions;
}

void csf::MultilineText::setDimensions()
{
	//for (int i = 0; i < (int)Texts.size(); i++)
	//	Texts[i]->setDimensions();
	updateDimensions();
}

void csf::MultilineText::updatePosition()
{
	if (Texts.size() == 1)
	{
		Texts[0]->setPosition(Carcas::location);
	}
	else
	{
		float top = Carcas::location.y - Carcas::scaleDimensions.y / 2;
		for (int i = 0; i < (int)Texts.size(); i++)
		{
			Texts[i]->setPosition(Carcas::location.x, top + size / 2);
			top += lineSpacing * size;
		}
	}
}

String csf::MultilineText::getStringPart(String str, int startIndex, int endIndex)
{
	String result;
	for (int i = startIndex; i <= endIndex; i++)
		result += str[i];
	return result;
}

int csf::MultilineText::getIndexCentralSpace(String str)
{
	int centralIndex = (int)str.getSize() / 2;
	for (int i = 0; i < centralIndex; i++)
	{
		if (str[centralIndex - i] == ' ')
			return centralIndex - i;
		if (str[centralIndex + i] == ' ')
			return centralIndex + i;
	}
	return -1;
}

bool csf::MultilineText::DivideIntoParagraphs()
{
	int indexLongestLine = 0;
	for (int i = 1; i < (int)Texts.size(); i++)
	{
		if (Texts[indexLongestLine]->getLength() < Texts[i]->getLength()) indexLongestLine = i;
	}

	if (Texts[indexLongestLine]->Find(L' ') == -1) return false;
	else
	{
		int indexSpace = getIndexCentralSpace(Texts[indexLongestLine]->getString());
		String te = Texts[indexLongestLine]->getString();
		te = getStringPart(te, 0, (int)te.getSize() - 2);
		int indexStr = (int)myText::name.find(te);

		myText::name[indexStr + indexSpace] = '\n';
		return true;
	}
}

void csf::MultilineText::SplitText()
{
	String temp = myText::name;
	wstring x = temp;
	deleteTexts();
	int startIndex = 0;
	for (int i = 0; i < (int)temp.getSize(); i++)
	{
		if (temp[i] == L'\n' || i + 1 == (int)temp.getSize())
		{
			String str = getStringPart(temp, startIndex, (i + 1 == (int)temp.getSize()) ? i : i - 1);
			startIndex = i + 1;
			myText* mytext = new myText(0, 0, str, size);
			
			Texts.push_back(mytext);
			setObject(mytext);
		}
	}
	setDimensions();
	updatePosition();
	setColor(Carcas::color);
}

void csf::MultilineText::deleteTexts()
{
	for (int i = 0; i < (int)Texts.size(); i++) delete Texts[i];
	Texts.clear();
	Objects.clear();
}

csf::MultilineText::MultilineText()
	: Carcas(), myText() 
{
	lineSpacing = 1;
}

csf::MultilineText::MultilineText(float x, float y, String name, int size, float lineSpacing)
	: myText(x, y, name, size)
{
	this->lineSpacing = lineSpacing;
	SplitText();
	Carcas::name = myText::name;
	setPosition(x, y);
}

void csf::MultilineText::Reload(String name, float x, float y)
{
	Carcas::Delete();
	*this = MultilineText(x, y, name, 14, 1);
}

void csf::MultilineText::Reload(float x, float y, String name, int size, float lineSpacing)
{
	Carcas::Delete();
	*this = MultilineText(x, y, name, size, lineSpacing);
}

void csf::MultilineText::setColor(int red, int green, int blue, int alpha)
{
	Carcas::setColor(red, green, blue, alpha);
	myText::color = Carcas::color;
}

void csf::MultilineText::operator>(RenderWindow& window)
{
	Carcas::operator>(window);
}

void csf::MultilineText::operator>>(RenderWindow& window)
{
	Carcas::operator>>(window);
}

void csf::MultilineText::setPosition(float x, float y)
{
	Carcas::setPosition(x, y);
	myText::location = Carcas::location;
}

void csf::MultilineText::setPosition(Vector2f _location)
{
	Carcas::setPosition(_location);
}

void csf::MultilineText::setSize(int size)
{
	this->size = size;
	for (int i = 0; i < (int)Texts.size(); i++) Texts[i]->setSize(size);
	setDimensions();
	updatePosition();
}

void csf::MultilineText::setString(String name)
{
	this->myText::name = Carcas::name = name;
	SplitText();
}

bool csf::MultilineText::Input(Event& event)
{
	//if (event.type == Event::TextEntered)
	//{
	//	m_textChanged = true;
	//	switch (event.text.unicode)
	//	{
	//	case 0xD: //Return
	//		m_textChanged = false;
	//		sleep(milliseconds(100));
	//		return true;
	//		break;
	//	case 0x8://Backspace
	//		if (!name.isEmpty()){
	//			name.erase(name.getSize() - 1);
	//			sleep(milliseconds(100));
	//		}
	//		break;
	//	default:
	//	{
	//			   if ((int)name.getSize() <= maxLenght) { name += static_cast<wchar_t>(event.text.unicode); sleep(milliseconds(100)); }
	//	} break;
	//	}
	//}
	return false;
}

void csf::MultilineText::Clear()
{
	myText::name = Carcas::name = "";
	setDimensions();
	updatePosition();
}

int csf::MultilineText::getLength()
{
	int sum = 0;
	for (int i = 0; i < (int)Texts.size(); i++) sum += Texts[i]->getLength();
	return sum;
}

String csf::MultilineText::getString() 
{ 
	return myText::name;
}

void csf::MultilineText::Refresh()
{
	for (int i = 0; i < (int)Texts.size(); i++) Texts[i]->setFont(font);
	Color color = Carcas::color;
	setColor(color.r, color.g, color.b, color.a);
	setPosition(Carcas::location);
}

void csf::MultilineText::setMaxLenght(int maxLenght)
{
	this->maxLenght = maxLenght;
	for (int i = 0; i < (int)Texts.size(); i++) 
		Texts[i]->setMaxLenght(maxLenght);
}

csf::BaseObject* csf::MultilineText::operator*()
{
	return myText::operator*();
}

bool csf::MultilineText::AlignTextBox(Vector2f sizeBox)
{
	return AlignTextBox(sizeBox, false, false, false);
}

bool csf::MultilineText::AlignTextBox(Vector2f sizeBox, bool isSaveLine, bool isSaveSize, bool isSaveLineSpacing)
{
	String saveName = myText::name;
	float saveLineSpacing = lineSpacing;
	int saveSize = size;

	bool isContinue = true;
	bool isLastDivideIntoParagraphs = true;

	while (!getFitInBox(sizeBox))
	{
		if (isSaveLine && isSaveSize && isSaveLineSpacing) return false;
		if (!isContinue)
		{
			if (isSaveLine) setString(saveName);
			if (isSaveSize) setSize(saveSize);
			if (isSaveLineSpacing) setLineSpacing(saveLineSpacing);
			setDimensions();
			return false;
		}

		if (!getFitInBoxWidth((int)sizeBox.x))
		{
			if (isSaveLine && isSaveSize) { isContinue = false; continue; }
			if (size == 1 && !isLastDivideIntoParagraphs) { isContinue = false; continue; }
			if (!isSaveLine && isLastDivideIntoParagraphs)
			{
				isLastDivideIntoParagraphs = DivideIntoParagraphs();
				SplitText();
				setDimensions();
				continue;
			}
			if (!isSaveSize)
			{
				setSize(size - 1);
				isLastDivideIntoParagraphs = true;
				setDimensions();
				continue;
			}
		}

		if (!getFitInBoxHeight((int)sizeBox.y))
		{
			if (isSaveLineSpacing && isSaveSize) { isContinue = false; continue; }
			if (size == 1 && lineSpacing < 0) { isContinue = false; continue; }
			if (!isSaveLineSpacing && lineSpacing > 0 && Texts.size() > 1)
			{
				setLineSpacing(lineSpacing - 0.1f);
				setDimensions();
				continue;
			}
			if (!isSaveSize)
			{
				setSize(size - 1);
				isLastDivideIntoParagraphs = true;
				setDimensions();
				continue;
			}
		}
	}
	return true;
}

Vector2f csf::MultilineText::getPosition()
{
	return Carcas::getPosition();
}

bool csf::MultilineText::getVisible()
{
	return Carcas::getVisible();
}

Color csf::MultilineText::getColor()
{
	return Carcas::getColor();
}

void csf::MultilineText::setColor(Color color)
{
	Carcas::setColor(color.r, color.g, color.b, color.a);
}
void csf::MultilineText::setScale(float x, float y)
{
	Carcas::setScale(x, y);
}
void csf::MultilineText::setRotate(float angle)
{
	Carcas::setRotate(angle);
}
float csf::MultilineText::getLineSpacing()
{
	return lineSpacing;
}
void csf::MultilineText::setLineSpacing(float lineSpacing)
{
	this->lineSpacing = lineSpacing;
	setDimensions();
	updatePosition();
}
Vector2f csf::MultilineText::getOriginalDimensions()
{
	return Carcas::getOriginalDimensions();
}
Vector2f csf::MultilineText::getScaleDimensions()
{
	return Carcas::getScaleDimensions();
}
Vector2f csf::MultilineText::getRealDimensions()
{
	return Carcas::getRealDimensions();
}
