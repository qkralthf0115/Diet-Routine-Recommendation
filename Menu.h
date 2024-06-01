#pragma once
#include <vector>
#include <Memory>
#include "Command.h"

class Menu
{
private:
	std::vector<Command*> commands;
public:
	void addCommand(std::shared_ptr<Command> command);
	void selectCommand(int index);
	void displayCommand();
	void setMenu();
};