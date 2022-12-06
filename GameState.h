#pragma once

#include "Block.h"
#include "Engine.h"
#include <vector>

class GameState
{
public:
	GameState();
	~GameState();

	void movePaddle(bool left, float dt);
	bool moveBall(float dt);

	void addBlock(Block block);
	void draw();

	bool checkIntersect();

private:
	std::vector<Block*> _blocks;
	Block* _ball;
	Block* _paddle;

	int16_t _ballSpeedX = -150;
	int16_t _ballSpeedY = -150;
	int16_t _paddleSpeed = 200;

	uint8_t _score = 0;
};

