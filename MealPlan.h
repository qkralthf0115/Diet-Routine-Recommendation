//create one meal
#pragma once
#include"FoodDatabase.h"
#include"UserInfo.h"

class MealPlan
{
private:
	std::vector<FoodItem> mealItem;
public:
	MealPlan();
	void generateMeal(const std::vector<FoodItem>& foodList, double maxCalories);
	void displayMeal()const;
};