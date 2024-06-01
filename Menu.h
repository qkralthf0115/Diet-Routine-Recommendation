#pragma once
#include <vector>
#include <Memory>
#include "Command.h"
#include "ExerciseCommand.h"

class Menu
{
private:
	std::vector<Command*> commands;
public:
	void addCommand(int index, Command* command);
	void selectCommand(int index);
	void displayMenu();
	void setMenu();
};