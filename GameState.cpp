#include "GameState.h"

GameState::GameState() 
{
	_paddle = new Block( 124, 24, SCREEN_HEIGHT - 48, SCREEN_WIDTH/2 - 62 );
	_paddle->setColors(0, 254, 0);
	_ball = new Block( 24, 24, SCREEN_HEIGHT - 200, SCREEN_WIDTH/2 );
	_ball->setColors(254, 0, 0);
}

GameState::~GameState()
{
	if (_paddle) delete _paddle;
	if(_ball) delete _ball;

	for (auto block : _blocks)
	{
		if (block) delete block;
	}
}

void GameState::movePaddle(bool left, float dt)
{
	_paddle->moveY(left ? -_paddleSpeed : _paddleSpeed, dt);
}

bool GameState::moveBall(float dt)
{
	//I have ran out of time, but moving the ball should have happened after checking collisions.
	//first check where the ball should move then check collisions, after that move the ball
	bool bMove = _ball->moveX(_ballSpeedX, dt);

	bool bInterSectedWithPaddle = _ball->checkIntersect(_paddle);

	if (bInterSectedWithPaddle)
	{
		_ballSpeedX = -_ballSpeedX;
	}

	if (checkIntersect() || !bMove)
	{
		_ballSpeedX = -_ballSpeedX;
	}

	bMove = _ball->moveY(_ballSpeedY, dt);

	if (!bInterSectedWithPaddle && _ball->checkIntersect(_paddle))
	{
		_ballSpeedY = -_ballSpeedY;
	}

	if (checkIntersect() || !bMove)
	{
		_ballSpeedY = -_ballSpeedY;
	}

	if (_ball->getPositionX() + _ball->getHeight() > SCREEN_HEIGHT || _score == 80)
	{
		return false;
	}

	return true;
}

void GameState::addBlock(Block block)
{
	block.setColors(0, 0, 254);
	_blocks.push_back( new Block (block) );
}

void GameState::draw()
{
	for (auto block : _blocks)
	{
		if (!block->isHidden())
			block->draw();
	}
	_ball->draw();
	_paddle->draw();
}

bool GameState::checkIntersect()
{
	for (auto block : _blocks)
	{
		if (!block->isHidden() && _ball->checkIntersect(block))
		{
			block->setHidden(true);
			return true;
			_score++;
		}
	}

	return false;
}