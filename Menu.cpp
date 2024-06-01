#include "Menu.h"

Menu::addCommand(Command* command) {
	this->command.push_back(command);
}

Menu::executeCommand(int index) {
	this->command[index]->execute();
}

Menu::displayCommand() {
	for (int i = 0; i < this->command.size(); i++) {
		std::cout << i << ". " << this->command[i]->getName() << std::endl;
	}
}
