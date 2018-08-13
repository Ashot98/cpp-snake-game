#include "Menu.h"
#include <iostream>


Menu::Menu(const std::vector<std::string> &menuItems)
{
	for (auto menuItem : menuItems)
	{
		_menuItems.push_back(menuItem);
	}
	_selected = 0;
}


Menu::~Menu()
{
}

int Menu::getSelected()
{
	return _selected;
}

void Menu::setSelected(int index)
{
	if (index >= _menuItems.size())
		_selected = 0;
	else if (index < 0)
		_selected = _menuItems.size() - 1;
	else
		_selected = index;
}

void Menu::drawMenu()
{
	system("cls");

	int menuSize = _menuItems.size();
	std::cout << "== MENU ==";
	std::cout << std::endl << std::endl;
	for (int i = 0; i < menuSize; ++i)
	{
		std::cout << (i == _selected ? '>' : ' ') << _menuItems[i] << std::endl;
	}
}