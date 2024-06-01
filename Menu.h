#pragma once
#include <vector>
#include <Memory>
#include "Command.h"

class Menu
{
private:
	std::vector<Command*> commands;
public:
	void addCommand(Command* command);
	void executeCommand(int index);
	void displayCommand();
};