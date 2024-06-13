#include"MealCommand.h"
#include <iostream>
#include <sstream>
#include <iomanip>

MealCommand::MealCommand(std::shared_ptr<UserInfo> userInfo) : userInfo(userInfo) {}

void MealCommand::execute() {
	std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
	std::cout << "\033[0;33m" << "Meal Recommendation" << "\033[0;37m" << std::endl;
	if (!userInfo->getName().empty()) {
		std::vector<std::string> exclude;
		std::string input;
		std::cout << "Foods you do not want to eat" << std::endl;
		std::cout << "(Separate by " << "\033[0;35m" << "spaces" << "\033[0;37m" << ", the first letter should be" << "\033[0;35m" << " capitalized" << "\033[0;37m" << ", If none write down " << "\033[0;35m" << "None" << "\033[0;37m" << ")" << std::endl;
		std::cout << ": ";
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
		std::cout << "\033[0;35m" << "Please input user information first." << "\033[0;37m" << std::endl;
	}
}

std::string MealCommand::getName() const {
	return "Meal Recommendation";
}