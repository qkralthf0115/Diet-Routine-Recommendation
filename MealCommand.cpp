#include"MealCommand.h"
#include<iostream>
#include<sstream>
MealCommand::MealCommand(std::shared_ptr<DietPlan> dietPlan, FoodDatabase& db) : dietPlan(dietPlan), db(db) {}

void MealCommand::execute() {
	std::vector<std::string> exclude;
	std::string input;
	std::cout << "Foods you do not want to eat (separate by spaces): ";
	std::getline(std::cin, input);

	std::stringstream ss(input);
	std::string item;
	while (ss >> item) {
		exclude.push_back(item);
	}

	db.setExclusion(exclude);
	dietPlan->generatePlan();
	dietPlan->printPlan();
}

std::string MealCommand::getName() const {
	return name;
}