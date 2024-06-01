#include "Menu.h"

void Menu::addCommand(int index, Command* command) {
	this->commands.push_back(command);
}

void Menu::selectCommand(int index) {
	auto it commands.find(index);
	if (it != commands.end()) {
		it->second->execute();
	}
	else {
		std::cout << "Invalid command" << std::endl;
	}
}

void Menu::displayMenu() {
	for (int i = 0; i < this->commands.size(); i++) {
		std::cout << i << ". " << this->commands[i]->getName() << std::endl;
	}
}

void Menu::setMenu() {
	Command* addInfoCommand = new AddInformationCommand();
	Command* exerciseCommand = new ExerciseCommand();
	Command* mealCommand = new MealCommand();

	addCommand(1, addInfoCommand);
	addCommand(2, exerciseCommand);
	addCommand(3, mealCommand);
}