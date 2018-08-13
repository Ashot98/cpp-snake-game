#pragma once
#include "Player.h"
#include "Menu.h"

enum GameState { RESUME = 0, MENU, EXIT };

class SnakeGame
{
private:
	static int _width;
	static int _height;
	GameState _state{ RESUME };
	Player *player;
	Menu *menu;
	int _score;
	int _speedReg;

	int _fruitX;
	int _fruitY;

	void draw();
	void input();
	void logic(size_t &frameCount);
	void restart();
	void menuItemPress():
public:
	SnakeGame();
	~SnakeGame();

	void exec();
};

