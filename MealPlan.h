#pragma once
#include"FoodDatabase.h"

class MealPlan
{
private:
	std::vector<FoodItem> mealItem;
public:
	MealPlan(std::vector<FoodItem> mealItem);
	std::vector<FoodItem> generateMeal(FoodDatabase& db, int maxCalories, std::vector<std::string>& exclusion);
	
};