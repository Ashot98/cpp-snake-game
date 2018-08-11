#include "SnakeGame.h"
#include <time.h>

int main() {

	srand(time(NULL));

	SnakeGame game;

	game.exec();

	system("pause");
	return 0;
}