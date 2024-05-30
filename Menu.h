#pragma once
#include<vector>
#include<Memory>
#include"Command.h"

class Menu
{
private:
	std::vector<std::shared_ptr<Command>> command;
public:
	void addCommand(std::shared_ptr<Command> command);
	void executeCommand();
	void displayCommand();
};