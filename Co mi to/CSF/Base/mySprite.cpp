#include "mySprite.h"
#include "SizeWindow.h"


namespace csf
{
	TextureBank* mySprite::textureBank;

	void mySprite::updateDimentions()
	{
		scaleDimensions.x = originalDimensions.x * scale.x;
		scaleDimensions.y = originalDimensions.y * scale.y;
		FloatRect fr;
		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			fr = sprite.getGlobalBounds();
			break;
		case csf::mySprite::useShape:
			fr = shape->getGlobalBounds();
			break;
		}
	
		realDimensions.x = fr.width;
		realDimensions.y = fr.height;
		updateLocation();
	}

	void mySprite::updateLocation()
	{
		FloatRect fr;
		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			fr = sprite.getGlobalBounds();
			break;
		case csf::mySprite::useShape:
			fr = shape->getGlobalBounds();
			break;
		}
		realLocation.x = fr.left;
		realLocation.y = fr.top;
	}

	void mySprite::AwakeningChangeColor(bool awakening)
	{
		if (this->awakening != awakening)
		{
			if (awakening)
				switch (typeForm)
				{
				case csf::mySprite::useSprite:
					sprite.setColor(colorAwakening);
					break;
				case csf::mySprite::useShape:
					shape->setFillColor(colorAwakening);
					break;
				}
			else
				switch (typeForm)
				{
				case csf::mySprite::useSprite:
					sprite.setColor(color);
					break;
				case csf::mySprite::useShape:
					shape->setFillColor(color);
					break;
				}
			this->awakening = awakening;
		}
	}

	void mySprite::AwakeningChangeFrame(bool awakening)
	{
		if (this->awakening != awakening)
		{
			int sign = awakening ? +1 : -1;
			setTextureRect(FloatRect(textureRect.left + textureRect.width * sign, textureRect.top,
									 textureRect.width, textureRect.height));
			this->awakening = awakening;
		}
	}

	void mySprite::AwakeningChangeScale(bool awakening)
	{
		static Vector2f origScale = Vector2f(1, 1);
		if (this->awakening != awakening)
		{
			if (awakening)
			{
				origScale = scale;
				setScale(scaleAwakening.x, scaleAwakening.y);
			}
			else 
			{
				setScale(origScale.x, origScale.y);
			}
			this->awakening = awakening;
		}
	}

	mySprite::mySprite()
	{ 
		*this = mySprite("Error"); 
	}

	mySprite::mySprite(string name, float x, float y)
		: BaseObject()
	{
		typeForm = useSprite;
		shape = NULL;
		this->name = name; 
		sprite.setTexture(textureBank->getTexture(name).getTexture());
		setPosition(textureBank->getTexture(name).getPosition().x, 
				    textureBank->getTexture(name).getPosition().y);
		originalDimensions.x = textureBank->getTexture(name).getDimensions().x;
		originalDimensions.y = textureBank->getTexture(name).getDimensions().y;
		setTextureRect(FloatRect(0, 0, originalDimensions.x, originalDimensions.y));
		setScale(scale.x, scale.y);

		if (x < 0 && y < 0) 
			setPosition(textureBank->getTexture(name).getPosition().x, 
						textureBank->getTexture(name).getPosition().y);
		else setPosition(x, y);
	}

	mySprite::mySprite(string name, Vector2f location)
		: mySprite(name, location.x, location.y) {}

	mySprite::mySprite(const Sprite& sprite) 
		: BaseObject()
	{
		typeForm = useSprite;
		this->sprite = sprite;
		name = "CreateSprite";
		color = sprite.getColor();
		origin = sprite.getOrigin();
		rotate = sprite.getRotation();
		scale = sprite.getScale();

		this->sprite.setOrigin(0, 0);
		this->sprite.setRotation(0);
		this->sprite.setScale(1, 1);

		FloatRect temp = sprite.getLocalBounds();
		originalDimensions.x = temp.width;
		originalDimensions.y = temp.height;
		
		Vector2f tempPosition = sprite.getPosition();
		location.x = tempPosition.x / SizeWindow::getScaleAdapting().x - origin.x;
		location.y = tempPosition.y / SizeWindow::getScaleAdapting().y - origin.y;

		setPosition(location);
		setOrigin(origin.x, origin.y);
		setScale(scale.x, scale.y);
		setRotate(rotate);
		setTextureRect(FloatRect(sprite.getTextureRect()));
	}

	mySprite::mySprite(Shape* shape)
	{
		typeForm = useShape;
		this->shape = shape;
		name = "CreateSprite";
		color = shape->getFillColor();
		origin = shape->getOrigin();
		rotate = shape->getRotation();
		scale = shape->getScale();
		FloatRect t(shape->getTextureRect());

		this->shape->setOrigin(0, 0);
		this->shape->setRotation(0);
		this->shape->setScale(1, 1);

		FloatRect temp = shape->getLocalBounds();
		originalDimensions.x = temp.width;
		originalDimensions.y = temp.height;

		Vector2f tempPosition = shape->getPosition();
		location.x = tempPosition.x / SizeWindow::getScaleAdapting().x - origin.x;
		location.y = tempPosition.y / SizeWindow::getScaleAdapting().y - origin.y;

		setPosition(location);
		setOrigin(origin.x, origin.y);
		setScale(scale.x, scale.y);
		setRotate(rotate);
		
		setTextureRect(t);
	}

	void mySprite::Reload(string name, float x, float y)
	{ 
		Delete();
		*this = mySprite(name, x, y);
	}

	void mySprite::Reload(string name, Vector2f location)
	{
		Delete();
		*this = mySprite(name, location);
	}

	void mySprite::Reload(const Sprite& sprite)
	{
		Delete();
		*this = mySprite(sprite);
	}

	void mySprite::Reload(Shape* shape)
	{
		Delete();
		*this = mySprite(shape);
	}

	void mySprite::operator>(RenderWindow & window)
	{ 
		if (visible) 
			switch (typeForm)
			{
			case csf::mySprite::useSprite:
				window.draw(sprite);
				break;
			case csf::mySprite::useShape:
				window.draw(*shape);
				break;
			}
	}


	void mySprite::setPosition(float x, float y)
	{
		originLocation = Vector2f(x, y);
		location.x = x - origin.x * scale.x; 
		location.y = y - origin.y * scale.y;
		location = Rotate(location, originLocation, rotate);
		setTextureRect(textureRect);

		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			sprite.setPosition(maskLocation.x, maskLocation.y);
			break;
		case csf::mySprite::useShape:
			shape->setPosition(maskLocation.x, maskLocation.y);
			break;
		}
		
		updateLocation();
	}

	void mySprite::setPosition(Vector2f _location)
	{
		BaseObject::setPosition(_location);
	}

	void mySprite::setTexture(string name)
	{
		Vector2f origin = getOrigin();
		float rotate = getRotate();
		Vector2f scale = getScale();
		Vector2f location = getPosition();
		FloatRect maskRect = getMaskRect();

		Reload(name);

		setMaskRect(maskRect);
		setOrigin(origin.x, origin.y);
		setRotate(rotate);
		setScale(scale.x, scale.y);
		setPosition(location);
	}

	void mySprite::setColor(int red, int green, int blue, int alpha)
	{
		color = getUpdateColor(color, red, green, blue, alpha);
		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			sprite.setColor(color);
			break;
		case csf::mySprite::useShape:
			shape->setFillColor(color);
			break;
		}
	}
	void mySprite::setOrigin(float x, float y)
	{
		origin.x = x;
		origin.y = y;
		originLocation = Vector2f(location.x + origin.x * scale.x, location.y + origin.y * scale.y);
	}
	void mySprite::setScale(float x, float y)
	{
		scale.x = x;
		scale.y = y;

		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			sprite.setScale(scale.x, scale.y);
			break;
		case csf::mySprite::useShape:
			shape->setScale(scale.x, scale.y);
			break;
		}
		setPosition(originLocation);
	}
	void mySprite::setRotate(float angle)
	{
		rotate = angle;
		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			sprite.setRotation(rotate);
			break;
		case csf::mySprite::useShape:
			shape->setRotation(rotate);
			break;
		}
		setPosition(originLocation);
	}
	void mySprite::setTextureRect(FloatRect textureRect)
	{
		maskTextureRect = textureRect;
		maskLocation = location;
		if (rotate == 0 && typeForm == useSprite)
		{
			if (maskLocation.x < maskRect.left)
			{
				maskLocation.x = maskRect.left;
				float difference = (maskRect.left - location.x) / scale.x;
				maskTextureRect.left += difference;
				maskTextureRect.width -= difference;
			}
			else if (maskLocation.x > maskRect.left + maskRect.width)
			{
				maskLocation.x = maskRect.left + maskRect.width;
				maskTextureRect.width = 0;
			}

			if (maskLocation.x + maskTextureRect.width * scale.x > maskRect.left + maskRect.width)
			{
				float difference = (maskLocation.x + maskTextureRect.width * scale.x) - (maskRect.left + maskRect.width);
				maskTextureRect.width -= difference / scale.x;
			}
			else if (maskLocation.x + maskTextureRect.width * scale.x < maskRect.left)
			{
				maskLocation.x = maskRect.left + maskRect.width;
				maskTextureRect.width = 0;
			}

			if (maskLocation.y < maskRect.top)
			{
				maskLocation.y = maskRect.top;
				float difference = (maskRect.top - location.y) / scale.y;
				maskTextureRect.top += difference;
				maskTextureRect.height -= difference;
			}
			else if (maskLocation.y > maskRect.top + maskRect.height)
			{
				maskLocation.y = maskRect.top + maskRect.height;
				maskTextureRect.height = 0;
			}

			if (maskLocation.y + maskTextureRect.height * scale.y > maskRect.top + maskRect.height)
			{
				float difference = (maskLocation.y + maskTextureRect.height * scale.y) - (maskRect.top + maskRect.height);
				maskTextureRect.height -= difference / scale.y;
			}
			else if (maskLocation.y + maskTextureRect.height * scale.y < maskRect.top)
			{
				maskLocation.y = maskRect.top + maskRect.height;
				maskTextureRect.height = 0;
			}
		}
		this->textureRect = textureRect;
		originalDimensions.x = maskTextureRect.width;
		originalDimensions.y = maskTextureRect.height;
		switch (typeForm)
		{
		case csf::mySprite::useSprite:
			sprite.setTextureRect(IntRect(maskTextureRect));
			break;
		case csf::mySprite::useShape:
			shape->setTextureRect(IntRect(maskTextureRect));
			break;
		}
		updateDimentions();
	}
	void mySprite::setAwakeningType(AwakeningTypes AwakeningType)
	{
		if (this->AwakeningType == AwakeningTypes::ChangeFrame)
		{
			setTextureRect(FloatRect(textureRect.left, textureRect.top, textureRect.width * 2, textureRect.height));
		}

		switch (AwakeningType)
		{
		case csf::BaseObject::ChangeFrame:
			setTextureRect(FloatRect(textureRect.left, textureRect.top, textureRect.width / 2, textureRect.height));
			break;
		}
		BaseObject::setAwakeningType(AwakeningType);
	}
	Sprite mySprite::getSprite()
	{
		switch (typeForm)
		{
		case csf::mySprite::useSprite: return sprite;
		case csf::mySprite::useShape: return Sprite();
		}
	}
	void mySprite::set—urrentTextureBank(TextureBank* external)
	{
		textureBank = external;
	}
	void mySprite::Delete()
	{
		switch (typeForm)
		{
		case csf::mySprite::useShape:
			if (shape != NULL) {
				delete shape;
				shape = NULL;
			}
			break;
		}
	}
	TextureBank* mySprite::get—urrentTextureBank(TextureBank* external)
	{
		return textureBank;
	}
}