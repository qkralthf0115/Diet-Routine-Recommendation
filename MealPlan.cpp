#include<iostream>
#include<random>
#include"MealPlan.h"

MealPlan::MealPlan() {}

void MealPlan::generateMeal(const std::vector<FoodItem>& foodList, double maxCalories)
{
	mealItem.clear();
	double totalCalories = 0;

	std::random_device rd;
	auto available = foodList;
	std::shuffle(available.begin(), available.end(), std::default_random_engine(rd()));

	for (const auto& food : available)
	{
		if (totalCalories + food.getCalories() <= maxCalories)
		{
			mealItem.push_back(food);
			totalCalories += food.getCalories();
		}
		if (totalCalories >= maxCalories)
		{
			break;
		}
	}
	if (mealItem.empty())
	{
		std::cout << "Cannot create a meal. Include more foods." << std::endl;
	}
}

void MealPlan::displayMeal() const
{
	for (const auto& food : mealItem)
	{
		std::cout << food.getName() << " ";
	}
}