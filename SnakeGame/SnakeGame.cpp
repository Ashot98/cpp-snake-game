#include "SnakeGame.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

int SnakeGame::_width{ 20 };
int SnakeGame::_height{ 20 };

SnakeGame::SnakeGame()
{
	player = new Player(_width / 2 - 1, _height / 2 - 1);
	int firstFruitX, firstFruitY;

	do {
		firstFruitX = 1 + rand() % (_width - 2);
		firstFruitY = 1 + rand() % (_height - 2);
	} while (firstFruitX == player->getX() && firstFruitY == player->getY());

	_fruitX = firstFruitX;
	_fruitY = firstFruitY;

	_score = 0;
	_speedReg = 10;
}


SnakeGame::~SnakeGame()
{
}

void SnakeGame::exec()
{
	char userInput;
	size_t count{ 0 };

	while (_state == RESUME)
	{
		Sleep(1000 / 30);
		count++;
		input();
		logic(count);
		draw();


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

	bool isTail;
	std::vector<int> tailX = player->getTailX();
	std::vector<int> tailY = player->getTailY();
	size_t tailSize = tailX.size();

	for (size_t i = 0; i < _width; ++i)
	{
		std::cout << '#';
	}
	std::cout << std::endl;

	for (size_t i = 1; i < _height - 1; ++i)
	{
		for (size_t j = 0; j < _width; ++j)
		{
			isTail = false;

			if (j == 0 || j == _width - 1)
				std::cout << '#';
			else if (j == _fruitX && i == _fruitY)
				std::cout << 'F';
			else if (j == player->getX() && i == player->getY())
				std::cout << 'O';
			else
			{
				for (size_t k = 0; k < tailSize; ++k)
				{
					if (j == tailX[k] && i == tailY[k])
					{
						isTail = true;
						std::cout << 'o';
					}
				}
				if (!isTail)
					std::cout << ' ';
			}
		}
		std::cout << std::endl;
	}

	for (size_t i = 0; i < _width; ++i)
	{
		std::cout << '#';
	}
	std::cout << std::endl << std::endl;
	std::cout << "Score: " << _score;
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

void SnakeGame::logic(size_t &frameCount)
{
	if (frameCount == 30 / _speedReg)
	{
		player->move();
		frameCount = 0;
	}
	
	if (player->getX() == 0)
	{
		player->setX(_width - 2);
	}
	else if (player->getX() == _width - 1)
	{
		player->setX(1);
	}

	if (player->getY() == 0)
	{
		player->setY(_height - 2);
	}
	else if (player->getY() == _height - 1)
	{
		player->setY(1);
	}

	if (player->getX() == _fruitX && player->getY() == _fruitY)
	{
		player->eat();

		_score += 10;

		int newFruitX, newFruitY;

		do {
			newFruitX = 1 + rand() % (_width - 2);
			newFruitY = 1 + rand() % (_height - 2);
		} while (newFruitX == player->getX() && newFruitY == player->getY());

		_fruitX = newFruitX;
		_fruitY = newFruitY;
	}
}

void SnakeGame::restart()
{

}