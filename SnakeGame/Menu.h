#pragma once
#include <vector>
#include <string>

class Menu
{
private:
	std::vector<std::string> _menuItems;
	int _selected;
public:
	Menu(const std::vector<std::string> &menuItems);
	~Menu();

	int getSelected();
	void setSelected(int index);

	void drawMenu();
};

