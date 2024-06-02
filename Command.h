#pragma once
#include <string>
class Command {
protected:
	std::string name;
public:
	virtual void execute() = 0;
	std::string getName();
};