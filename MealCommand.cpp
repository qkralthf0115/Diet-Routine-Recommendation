#include"MealCommand.h"
#include<iostream>
#include<sstream>

MealCommand::MealCommand() {
	userInfo = std::make_shared<UserInfo>();
}

void MealCommand::execute() {
	std::vector<std::string> exclude;
	std::string input;

	std::cout << "Foods you do not want to eat (separate by spaces, the first letter should be capitalized): "<<std::endl;
	std::cin.ignore();
	std::getline(std::cin, input);

	std::stringstream ss(input);
	std::string item;
	while (ss >> item) {
		exclude.push_back(item);
	}

	FoodDatabase db;
	db.loadFoodList("foodlist.txt");
	db.setExclusion(exclude);

	double maxCalories = userInfo->calculateFoodCalories() / 3;
	dietPlan.generatePlan(db.getFoodList(), maxCalories);
	dietPlan.printPlan();
}

std::string MealCommand::getName() const {
	return "Meal Recommendation";
}