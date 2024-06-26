#include<iostream>
#include"DietPlan.h"

DietPlan::DietPlan() {}

void DietPlan::generatePlan(const std::vector<FoodItem>& foodList, double maxCalories) {
	weeklyPlan.clear();
	bool creationfailed;
	for (int i = 0; i < 21; ++i) {
		MealPlan oneMealPlan;
		oneMealPlan.generateMeal(foodList, maxCalories);
		if (oneMealPlan.isEmpty()) {
			creationfailed = true;
		}
		weeklyPlan.push_back(oneMealPlan);
	}
	if (creationfailed == true) {
		std::cout << "Cannot create a meal. Include more foods." << std::endl;
	}

}

void DietPlan::printPlan() const {
	std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
	for (int j = 0; j < 7; ++j) {
		std::cout << "\033[0;35m" << "Day " << j + 1 << std::endl;
		std::cout << "\033[0;33m" << "Breakfast: " << "\033[0;37m";
		weeklyPlan[3 * j].displayMeal();

		std::cout << "\033[0;33m" << "Lunch: " << "\033[0;37m";
		weeklyPlan[3 * j + 1].displayMeal();

		std::cout << "\033[0;33m" << "Dinner: " << "\033[0;37m";
		weeklyPlan[3 * j + 2].displayMeal();

		std::cout << std::endl;

	}
}
