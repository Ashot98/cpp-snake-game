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

	void draw();
	void input();
	void logic();
	void restart();
public:
	SnakeGame();
	~SnakeGame();

	void exec();
};

