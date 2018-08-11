#include "SnakeGame.h"
#include <iostream>
#include <conio.h>

int SnakeGame::_width{ 20 };
int SnakeGame::_height{ 20 };

SnakeGame::SnakeGame()
{
	player = new Player(_width / 2 - 1, _height / 2 - 1);
}


SnakeGame::~SnakeGame()
{
}

void SnakeGame::exec()
{
	char userInput;
	while (_state == RESUME)
	{
		draw();
		input();
		logic();

		if (_state == OVER)
		{
			std::cout << "Do you want to restart game? (y/n): ";
			std::cin >> userInput;
			if (userInput == 'y' || userInput == 'Y')
				restart();
		}
	}
}

void SnakeGame::draw()
{
	system("cls");
	for (size_t i = 0; i < _width; ++i)
	{
		std::cout << '#';
	}
	std::cout << std::endl;

	for (size_t i = 0; i < _height - 2; ++i)
	{
		for (size_t j = 0; j < _width; ++j)
		{
			if (j == 0 || j == _width - 1)
				std::cout << '#';
			else if (j == player->getX() && i == player->getY())
				std::cout << 'O';
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < _width; ++i)
	{
		std::cout << '#';
	}
	std::cout << std::endl;
}

void SnakeGame::input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			player->changeDirection(UP);
			break;
		case 'd':
			player->changeDirection(RIGHT);
			break;
		case 's':
			player->changeDirection(DOWN);
			break;
		case 'a':
			player->changeDirection(LEFT);
			break;
		}
	}
}

void SnakeGame::logic()
{
	player->move();
}

void SnakeGame::restart()
{

}