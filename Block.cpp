#include "Block.h"
#include "Engine.h"

bool Block::isHidden()
{
	return _hidden;
}

void Block::setHidden(bool hidden)
{
	_hidden = hidden;
}

void Block::setColors(uint8_t red, uint8_t green, uint8_t blue)
{
	_red = red;
	_green = green;
	_blue = blue;
};


bool Block::moveX(int32_t posX, float dt)
{
	float newPosX = _posX + posX * dt;

	if (newPosX < 0)
	{
		_posX = 0;
	}
	else
	{
		_posX = newPosX;
		return true;
	}

	return false;
}

bool Block::moveY(int32_t posY, float dt)
{
	float newPosY = _posY + posY * dt;

	if (newPosY < 0)
	{
		_posY = 0;
	}
	else if (newPosY + _width > SCREEN_WIDTH - 1)
	{
		_posY = SCREEN_WIDTH - 1 - _width;
	}
	else
	{
		_posY = newPosY;
		return true;
	}

	return false;
}


void Block::draw()
{
	int32_t xMax = _posX + _height;
	int32_t yMax = _posY + _width;

	if (_posX < 0) _posX = 0;
	if (_posY < 0) _posY = 0;

	if (xMax > SCREEN_HEIGHT - 1) _posX = SCREEN_HEIGHT - 1 - _height;
	if (yMax > SCREEN_WIDTH - 1) _posY = SCREEN_WIDTH - 1 - _width;

	int32_t iPosX = (int)_posX;
	int32_t iPosY = (int)_posY;

	uint32_t color = _red << 16 | _green << 8 | _blue << 0;

	for (int x = iPosX + 1; x < xMax - 1; ++x)
	{
		for (int y = iPosY + 1; y < yMax - 1; ++y)
		{
			buffer[x][y] = color;
			buffer[x][y] = color;
		}
	}
}

bool Block::checkIntersect(const Block* other)
{
	return (
		other->_posX < _posX + _height &&
		other->_posX + other->_height > _posX &&
		other->_posY < _posY + _width &&
		other->_width + other->_posY > _posY
		);
}

float Block::getPositionX()
{
	return _posX;
}

float Block::getPositionY()
{
	return _posY;
}

uint32_t Block::getWidth()
{
	return _width;
}

uint32_t Block::getHeight()
{
	return _height;
}