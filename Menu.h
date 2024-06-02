#pragma once
#include <vector>
#include <Memory>
#include "Command.h"
#include "ExerciseCommand.h"
#include "MealCommand.h"
#include "InputInfoCommand.h"

class Menu
{
private:
	std::vector<Command*> commands;
public:
	void addCommand(Command* command);
	void selectCommand(int index);
	void displayMenu();
	void setMenu();
};