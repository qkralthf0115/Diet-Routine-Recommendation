#include "Menu.h"

void Menu::addCommand(Command* command) {
	this->commands.push_back(command);
}

void Menu::selectCommand(int index) {
	if (index >= 0 && index < commands.size()) {
		commands[index]->execute();
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
	Command* addInfoCommand = new InputInfoCommand();
	Command* exerciseCommand = new ExerciseCommand();
	Command* mealCommand = new MealCommand();

	addCommand(addInfoCommand);
	addCommand(exerciseCommand);
	addCommand(mealCommand);
}