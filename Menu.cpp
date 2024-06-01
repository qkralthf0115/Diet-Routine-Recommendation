#include "Menu.h"

void Menu::addCommand(int index, std::shared_ptr<Command> command) {
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

void Menu::displayCommand() {
	for (int i = 0; i < this->command.size(); i++) {
		std::cout << i << ". " << this->command[i]->getName() << std::endl;
	}
}

void Menu::setMenu() {
	std::shared_ptr<Command> addInfoCommand = std::make_shared<AddInformationCommand>();
	std::shared_ptr<Command> exerciseCommand = std::make_shared<ExerciseRecommendationCommand>();
	std::shared_ptr<Command> mealCommand = std::make_shared<MealRecommendationCommand>();

	addCommand(1, addInfoCommand);
	addCommand(2, exerciseCommand);
	addCommand(3, mealCommand);
}