#pragma once
#include<vector>
#include<Memory>
#include"Command.h"

class Menu
{
private:
	std::vector<Command*> command;
	std::string name;
public:
	void addCommand(Command* command);
	void executeCommand(int index);
	void displayCommand();
};