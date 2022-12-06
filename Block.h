#pragma once

#include <stdint.h>

class Block
{
public:
	Block(uint32_t width, uint32_t height, float posX, float posY) : _width(width), _height(height), _posX(posX), _posY(posY) {}

	bool isHidden();
	void setHidden(bool hidden);
	void setColors(uint8_t red, uint8_t green, uint8_t blue);

	bool moveX(int32_t posX, float dt);
	bool moveY(int32_t posY, float dt);

	float getPositionX();
	float getPositionY();

	uint32_t getWidth();
	uint32_t getHeight();

	bool checkIntersect(const Block* other);

	void draw();

private:
	uint32_t _width;
	uint32_t _height;
	float _posX;
	float _posY;

	uint8_t _red = 0;
	uint8_t _green = 0;
	uint8_t _blue = 0;

	bool _hidden = false;
};

