#include "BaseObject.h"
#include "SizeWindow.h"
#define _USE_MATH_DEFINES
#include <math.h>

namespace csf
{
	BaseObject::BaseObject()
	{
		name = "";
		color = colorAwakening = Color(255, 255, 255);
		visible = true;
		enable = true;
		awakening = false;
		origin = Vector2f(0, 0);
		scale = scaleAwakening = Vector2f(1, 1);
		rotate = 0;
		realLocation = maskLocation = originLocation = location = Vector2f(0, 0);
		realDimensions = scaleDimensions = originalDimensions = Vector2f(10, 10);
		maskRect = FloatRect(Vector2f(-100000, -100000), Vector2f(200000, 200000));
		textureRect = FloatRect(Vector2f(0, 0), originalDimensions);
		maskTextureRect = FloatRect();
		AwakeningType = AwakeningTypes::nonAwakening;
	}

	BaseObject::BaseObject(float x, float y, string name) : BaseObject()
	{
		this->name = name;
		visible = true;
		location.x = x;
		location.y = y;
		realLocation = location;
		originLocation = location;
		maskLocation = location;
	};
	BaseObject::BaseObject(Vector2f location, string name) : BaseObject(location.x, location.y, name) {}

	void BaseObject::Draw(RenderWindow& window)
	{
		operator>(window);
	}

	void BaseObject::DrawAwakening(RenderWindow& window)
	{
		operator>>(window);
	}

	void BaseObject::setOrigin(Vector2f origin)
	{
		setOrigin(origin.x, origin.y);
	}

	void BaseObject::setScale(Vector2f scale)
	{
		setScale(scale.x, scale.y);
	}

	Vector2f BaseObject::getOrigin()
	{
		return origin;
	}

	Vector2f BaseObject::getScale()
	{
		return scale;
	}

	float BaseObject::getRotate()
	{
		return rotate;
	}

	Vector2f BaseObject::getPosition()
	{
		return location;
	}

	Vector2f BaseObject::getOriginPosition()
	{
		return originLocation;
	}

	Vector2f BaseObject::getMaskPosition()
	{
		return maskLocation;
	}

	Vector2f BaseObject::getRealPosition()
	{
		return realLocation;
	}

	BaseObject* BaseObject::operator*()
	{
		return this;
	}

	bool BaseObject::isCursorOnObject(RenderWindow& window)
	{
		return operator<(window);
	}

	bool BaseObject::isCursorOnObjectAwakening(RenderWindow& window)
	{
		return operator<<(window);
	}

	void BaseObject::setVisible(bool visible)
	{
		this->visible = visible;
	}

	bool BaseObject::getVisible()
	{
		return visible;
	}

	bool csf::BaseObject::getEnable()
	{
		return enable;
	}

	void csf::BaseObject::setEnable(bool enable)
	{
		this->enable = enable;
	}

	void BaseObject::setName(String name)
	{
		this->name = name;
	}

	String BaseObject::getName()
	{
		return name;
	}

	void BaseObject::setColorAwakening(int red, int green, int blue, int alpha)
	{
		colorAwakening = getUpdateColor(colorAwakening, red, green, blue, alpha);
	}

	void BaseObject::setColorAwakening(Color color)
	{
		setColorAwakening(color.r, color.g, color.b, color.a);
	}

	Color BaseObject::getColorAwakening()
	{
		return colorAwakening;
	}

	void BaseObject::setScaleAwakening(Vector2f scale)
	{
		scaleAwakening = scale;
	}

	Vector2f BaseObject::getScaleAwakening()
	{
		return scaleAwakening;
	}

	void BaseObject::setColor(Color color)
	{
		setColor(color.r, color.g, color.b, color.a);
	}

	Color BaseObject::getColor()
	{
		return color;
	}

	void BaseObject::setPosition(Vector2f _location)
	{
		setPosition(_location.x, _location.y);
	};
	Vector2f BaseObject::getOriginalDimensions()
	{
		return originalDimensions;
	}
	Vector2f BaseObject::getScaleDimensions()
	{
		return scaleDimensions;
	}
	Vector2f BaseObject::getRealDimensions()
	{
		return realDimensions;
	}
	bool BaseObject::setScrolling(float scrolling)
	{
		return false;
	}
	void BaseObject::setAwakening(bool awakening)
	{
		switch (AwakeningType)
		{
		case csf::BaseObject::nonAwakening:
			break;
		case csf::BaseObject::ChangeColor:
			AwakeningChangeColor(awakening);
			break;
		case csf::BaseObject::ChangeFrame:
			AwakeningChangeFrame(awakening);
			break;
		case csf::BaseObject::ChangeScale:
			AwakeningChangeScale(awakening);
			break;
		case csf::BaseObject::Outline:
			AwakeningOutline(awakening);
			break;
		case csf::BaseObject::Other:
			AwakeningOther(awakening);
			break;
		default: break;
		}
	}
	void BaseObject::setAwakeningType(AwakeningTypes AwakeningType)
	{
		this->AwakeningType = AwakeningType;
	}
	void BaseObject::setMaskRect(FloatRect maskRect)
	{
		this->maskRect = maskRect;
		setTextureRect(textureRect);
	}
	BaseObject::AwakeningTypes BaseObject::getAwakeningType()
	{
		return AwakeningType;
	}
	FloatRect BaseObject::getOriginalRect()
	{
		return FloatRect(location, originalDimensions);
	}
	FloatRect BaseObject::getScaleRect()
	{
		return FloatRect(location, scaleDimensions);
	}
	FloatRect BaseObject::getRealRect()
	{
		return FloatRect(realLocation, realDimensions);
	}
	FloatRect BaseObject::getTextureRect()
	{
		return textureRect;
	}
	FloatRect BaseObject::getMaskTextureRect()
	{
		return maskTextureRect;
	}
	FloatRect BaseObject::getMaskRect()
	{
		return maskRect;
	}
	Vector2f BaseObject::getRealPositionLeftUpper()
	{
		return maskLocation;
	}
	Vector2f BaseObject::getRealPositionRightUpper()
	{
		return Rotate(Vector2f(maskLocation.x + scaleDimensions.x, maskLocation.y), maskLocation, rotate);
	}
	Vector2f BaseObject::getRealPositionLeftDown()
	{
		return Rotate(Vector2f(maskLocation.x, maskLocation.y + scaleDimensions.y), location, rotate);
	}
	Vector2f BaseObject::getRealPositionRightDown()
	{
		return Rotate(Vector2f(maskLocation.x + scaleDimensions.x, maskLocation.y + scaleDimensions.y), maskLocation, rotate);
	}

	void BaseObject::Delete() {}

	bool BaseObject::operator<(RenderWindow& window)
	{
		Vector2f windowMousePostion = window.mapPixelToCoords(Mouse::getPosition(window));
		windowMousePostion = Rotate(Vector2f(windowMousePostion), maskLocation, -rotate);

		if (rotate != 0)
		{
			if (FloatRect(maskLocation.x, maskLocation.y,
						  scaleDimensions.x, scaleDimensions.y)
				.contains(windowMousePostion)) 
				return true;
			return false;
		}
		else if (FloatRect(realLocation.x, realLocation.y,
						   realDimensions.x, realDimensions.y)
			.contains(windowMousePostion)) 
			return true;

		return false;
	}
	bool BaseObject::operator<<(RenderWindow& window)
	{
		if (operator<(window)) { setAwakening(true); return true; }
		else { setAwakening(false); return false; }
	}
	void BaseObject::operator>>(RenderWindow& window)
	{
		if (visible)
		{
			if (enable) operator<<(window);
			operator>(window);
		}
	}

	Color BaseObject::getUpdateColor(Color prev, int red, int green, int blue, int alpha)
	{
		Color color;
		color.r = red != -1 ? (Uint8)red : prev.r;
		color.g = green != -1 ? (Uint8)green : prev.g;
		color.b = blue != -1 ? (Uint8)blue : prev.b;
		color.a = alpha != -1 ? (Uint8)alpha : prev.a;
		return color;
	}
	void BaseObject::AwakeningChangeColor(bool awakening) {}
	void BaseObject::AwakeningChangeFrame(bool awakening) {}
	void BaseObject::AwakeningChangeScale(bool awakening) {}
	void BaseObject::AwakeningOutline(bool awakening) {}
	void BaseObject::AwakeningOther(bool awakening) {}
	Vector2f BaseObject::Rotate(Vector2f pos, Vector2f centre, float angle)
	{
		pos.x -= centre.x;
		pos.y -= centre.y;
		angle *= (float)M_PI / 180;
		Vector2f newPos(pos.x * cos(angle) - pos.y * sin(angle),
			pos.x * sin(angle) + pos.y * cos(angle));
		newPos.x += centre.x;
		newPos.y += centre.y;
		return newPos;
	}
}