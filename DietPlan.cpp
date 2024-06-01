#include<iostream>
#include"DietPlan.h"

DietPlan::DietPlan() {}

void DietPlan::generatePlan()
{
	FoodDatabase db;
	db.getFoodList();
	for (int i = 0; i < 21; ++i)
	{
		auto mealPlan = std::make_shared<MealPlan>();
		mealPlan->generateMeal(db);
		weeklyPlan.push_back(mealPlan);
	}

}

void DietPlan::printPlan() const
{
	for (int j = 0; j < 7; ++j)
	{
		std::cout << "Day " << j + 1 << std::endl;
		std::cout << "Breakfast: ";
		weeklyPlan[3 * j]->displayMeal();
		std::cout << "Lunch: ";
		weeklyPlan[3 * j + 1]->displayMeal();
		std::cout << "Dinner: ";
		weeklyPlan[3 * j + 2]->displayMeal();
		std::cout<<std::endl;

	}

}