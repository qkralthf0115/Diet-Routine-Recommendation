#include"MealCommand.h"
#include<iostream>
#include<sstream>

MealCommand::MealCommand(std::shared_ptr<UserInfo> userInfo) : userInfo(userInfo) {}

void MealCommand::execute() {
	if (!userInfo->getName().empty()) {
		std::vector<std::string> exclude;
		std::string input;

		std::cout << "Foods you do not want to eat (separate by spaces, the first letter should be capitalized): " << std::endl;
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
	else {
		std::cout << "Please input user information first." << std::endl;

	}
}

std::string MealCommand::getName() const {
	return "Meal Recommendation";
}