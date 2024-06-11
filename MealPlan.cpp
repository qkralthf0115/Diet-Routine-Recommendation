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
		if (totalCalories 
		>= maxCalories)
		{
			break;
		}
	}
}


void MealPlan::displayMeal() const
{
	double totC=0.0;
	for (const auto& food : mealItem)
	{
		std::cout << food.getName() << " ";
		totC+=food.getCalories();
	}
	std::cout<<"("<<totC<<"kcal)"<<std::endl;

}

bool MealPlan::isEmpty() const
{
	return mealItem.empty();
}