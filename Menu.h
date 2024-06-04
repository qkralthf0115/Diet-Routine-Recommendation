#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "Command.h"
#include "ExerciseCommand.h"
#include "MealCommand.h"
#include "InputInfoCommand.h"
#include "UserInfo.h"

class Menu
{
private:
	std::vector<std::unique_ptr<Command>> commands;
	std::shared_ptr<UserInfo> userInfo;
public:
	Menu();
	void addCommand(std::unique_ptr<Command> command);
	void executeCommand(int choice);
	void displayMenu() const;
};