#include "Menu.h"

Menu::Menu() {
	userInfo = std::make_shared<UserInfo>();
	ExerciseCommand exerciseCommand(userInfo);

	addCommand(std::unique_ptr<Command>(new InputInfoCommand(userInfo)));
	addCommand(std::unique_ptr<Command>(new ExerciseCommand(userInfo)));
	addCommand(std::unique_ptr<Command>(new MealCommand(userInfo)));
	addCommand(std::unique_ptr<Command>(new FeedbackCommand(userInfo, exerciseCommand)));
}

void Menu::addCommand(std::unique_ptr<Command> command) {
	this->commands.push_back(std::move(command));
}

void Menu::executeCommand(int choice) {
	if (choice - 1 >= 0 && choice - 1 < commands.size()) {
		commands[choice - 1]->execute();
	}
	else {
		std::cout << "Invalid command" << std::endl;
	}
}

void Menu::displayMenu() const {
	std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
	std::cout << "\033[1;32m" << "Choose a command (1-4) or -1 to exit:" << "\033[1;37m" << std::endl;
	for (int i = 0; i < this->commands.size(); i++) {
		std::cout << i + 1 << ". " << this->commands[i]->getName() << std::endl;
	}
	std::cout << "Enter your choice: ";
}