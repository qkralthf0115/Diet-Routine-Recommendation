#pragma once
#include"FoodDatabase.h"

class MealPlan
{
private:
	std::vector<FoodItem> mealItem;
public:
	MealPlan(std::vector<FoodItem> mealItem);
	void generateMeal(FoodDatabase& db, int maxCalories, std::vector<std::string>& exclusion);
	void displayMeal();
};