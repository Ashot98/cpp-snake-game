#pragma once
#include "Player.h"

enum GameState { RESUME = 0, OVER };

class SnakeGame
{
private:
	static int _width;
	static int _height;
	GameState _state{ RESUME };
	Player *player;
	int _score;
	int _speedReg;

	int _fruitX;
	int _fruitY;

	void draw();
	void input();
	void logic(size_t &frameCount);
	void restart();
public:
	SnakeGame();
	~SnakeGame();

	void exec();
};

