#include "Player.h"



Player::Player(int x, int y) : _x{x}, _y{y}
{
}


Player::~Player()
{
}

void Player::changeDirection(PlayerDirection newDir)
{
	_direction = newDir;
}

void Player::move()
{
	switch (_direction)
	{
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
}

int Player::getX()
{
	return _x;
}

int Player::getY()
{
	return _y;
}