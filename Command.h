#pragma once
#include <string>
class Command {
protected:
	std::string name;
public:
	virtual void execute() = 0;
	virtual std::string getName() const = 0;
};