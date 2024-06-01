#include<iostream>
#include<random>
#include"MealPlan.h"

MealPlan::MealPlan(UserInfo& user) : maxCalories(user.calculateFoodCalories()/3) {}

void MealPlan::generateMeal(FoodDatabase& db, UserInfo& user)
{
	mealItem.clear();
	int totalCalories = 0;

	std::random_device rd;
	auto available = db.getFoodList();
	std::shuffle(available.begin(), available.end(), std::default_random_engine(rd()));

	for (auto food : available)
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
	for (auto& food : mealItem)
	{
		std::cout << food.getName() << " " << std::endl;
	}
	std::cout << std::endl;
}