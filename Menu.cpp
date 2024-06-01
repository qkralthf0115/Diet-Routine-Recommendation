#include "Menu.h"

void Menu::addCommand(int index, Command* command) {
	this->commands.push_back(command);
}

void Menu::executeCommand(int index) {
	auto it commands.find(index);
	if (it != commands.end()) {
		it->second->execute();
	}
	else {
		std::cout << "Invalid command" << std::endl;
	}
}

void Menu::displayCommand() {
	for (int i = 0; i < this->command.size(); i++) {
		std::cout << i << ". " << this->command[i]->getName() << std::endl;
	}
}
