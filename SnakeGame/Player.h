#pragma once
#include <vector>

enum PlayerDirection { STOP = 0, UP, RIGHT, DOWN, LEFT};

class Player
{
private:
	int _x;
	int _y;
	PlayerDirection _direction{ STOP };
	std::vector<int> _tailX;
	std::vector<int> _tailY;
	
public:
	Player(int x, int y);
	~Player();

	void changeDirection(PlayerDirection newDir);
	void move();

	int getX();
	int getY();

	void setX(int x);
	void setY(int y);
};

