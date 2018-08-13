#include "Player.h"



Player::Player(int x, int y) : _x{x}, _y{y}
{
}


Player::~Player()
{
}

void Player::changeDirection(PlayerDirection newDir)
{
	if (_direction && abs(_direction - newDir) == 2)
	{
		return;
	}
	_direction = newDir;
}

void Player::move()
{
	int prevX{ _x };
	int prevY{ _y };
	int tmp;

	switch (_direction)
	{
	case STOP:
		return;
	case UP:
		--_y;
		break;
	case RIGHT:
		++_x;
		break;
	case DOWN:
		++_y;
		break;
	case LEFT:
		--_x;
		break;
	}

	size_t tailSize = _tailX.size();
	for(size_t i =0; i < tailSize; ++i)
	{
		if (_tailX[i] != prevX || _tailY[i] != prevY)
		{
			tmp = prevX;
			prevX = _tailX[i];
			_tailX[i] = tmp;
			
			tmp = prevY;
			prevY = _tailY[i];
			_tailY[i] = tmp;
		}
	}
}

void Player::eat()
{
	_tailX.push_back(_x);
	_tailY.push_back(_y);
}

int Player::getX()
{
	return _x;
}

int Player::getY()
{
	return _y;
}

std::vector<int> Player::getTailX()
{
	return _tailX;
}

std::vector<int> Player::getTailY()
{
	return _tailY;
}

void Player::setX(int x)
{
	_x = x;
}

void Player::setY(int y)
{
	_y = y;
}