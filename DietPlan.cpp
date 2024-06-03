#include<iostream>
#include"DietPlan.h"

DietPlan::DietPlan() {}

void DietPlan::generatePlan(const std::vector<FoodItem>& foodList, double maxCalories)
{
	weeklyPlan.clear();
	for (int i = 0; i < 21; ++i)
	{
		MealPlan oneMealPlan;
		oneMealPlan.generateMeal(foodList, maxCalories);
		weeklyPlan.push_back(oneMealPlan);
	}

}

void DietPlan::printPlan() const
{
	for (int j = 0; j < 7; ++j)
	{
		std::cout << "Day " << j + 1 << std::endl;
		std::cout << "Breakfast: ";
		weeklyPlan[3 * j].displayMeal();
		std::cout<<std::endl;
		std::cout << "Lunch: ";
		weeklyPlan[3 * j + 1].displayMeal();
		std::cout<<std::endl;
		std::cout << "Dinner: ";
		weeklyPlan[3 * j + 2].displayMeal();
		std::cout << std::endl;

	}

}