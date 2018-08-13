#include "SnakeGame.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

int SnakeGame::_width{ 20 };
int SnakeGame::_height{ 20 };

SnakeGame::SnakeGame()
{
	player = new Player(_width / 2 - 1, _height / 2 - 1);
	
	std::vector<std::string> menuItems{ "RESUME", "SETTINGS", "EXIT" };
	menu = new Menu(menuItems);

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
	delete player;
	delete menu;
}

void SnakeGame::exec()
{
	char userInput;
	size_t count{ 0 };

	while (_state != EXIT)
	{
		Sleep(1000 / 30);
		count++;

		int prevSelected = -1;
		
		while (_state == MENU)
		{
			input();
			if (prevSelected != menu->getSelected())
			{
				menu->drawMenu();
				prevSelected = menu->getSelected();
			}
		}

		input();
		logic(count);
		draw();


		if (_state == EXIT)
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
	std::cout << std::endl << std::endl;
}

void SnakeGame::input()
{
	
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (_state == RESUME)
				player->changeDirection(UP);
			else if (_state == MENU)
				menu->setSelected(menu->getSelected() - 1);
			break;
		case 'd':
			if (_state == RESUME)
				player->changeDirection(RIGHT);
			break;
		case 's':
			if (_state == RESUME)
				player->changeDirection(DOWN);
			else if (_state == MENU)
				menu->setSelected(menu->getSelected() + 1);
			break;
		case 'a':
			if (_state == RESUME)
				player->changeDirection(LEFT);
			break;
		case 'm':
			if (_state == RESUME)
			{
				player->changeDirection(STOP);
				_state = MENU;
			}
			else
				_state = RESUME;
			break;
		case ' ':
			if (_state == MENU)
				menuItemPress();
		case 'x':
			_state = EXIT;
			break;
		}
	}
}

void SnakeGame::logic(size_t &frameCount)
{
	std::vector<int> tailX = player->getTailX();
	std::vector<int> tailY = player->getTailY();
	size_t tailSize = tailX.size();
	bool isEating{ false };

	if (frameCount == 30 / _speedReg)
	{
		player->move();
		frameCount = 0;
		int playerX = player->getX();
		int playerY = player->getY();

		if (playerX == 0)
		{
			player->setX(_width - 2);
		}
		else if (playerX == _width - 1)
		{
			player->setX(1);
		}

		if (playerY == 0)
		{
			player->setY(_height - 2);
		}
		else if (playerY == _height - 1)
		{
			player->setY(1);
		}

		if (playerX == _fruitX && playerY == _fruitY)
		{
			player->eat();

			_score += 10;
			isEating = true;

			int newFruitX, newFruitY;

			do {
				newFruitX = 1 + rand() % (_width - 2);
				newFruitY = 1 + rand() % (_height - 2);
			} while (newFruitX == player->getX() && newFruitY == player->getY());

			_fruitX = newFruitX;
			_fruitY = newFruitY;
		}

		for (size_t i = 0; i < tailSize; ++i)
		{
			if (playerX == tailX[i] && playerY == tailY[i] && !isEating)
			{
				_state = EXIT;
			}
		}
	}
}

void SnakeGame::restart()
{
	delete player;
	player = new Player(_width / 2 - 1, _height / 2 - 1);
	
	_score = 0;
	_state = RESUME;

	int firstFruitX, firstFruitY;

	do {
		firstFruitX = 1 + rand() % (_width - 2);
		firstFruitY = 1 + rand() % (_height - 2);
	} while (firstFruitX == player->getX() && firstFruitY == player->getY());

	_fruitX = firstFruitX;
	_fruitY = firstFruitY;
}

void SnakeGame::menuItemPress()
{

}