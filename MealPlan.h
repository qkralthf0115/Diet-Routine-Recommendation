//create one meal
#pragma once
#include"FoodDatabase.h"
#include"userInfo.h"

class MealPlan
{
private:
	std::vector<FoodItem> mealItem;
	int maxCalories;
public:
	MealPlan(UserInfo& user);
	void generateMeal(FoodDatabase& db, UserInfo& user);
	void displayMeal()const;
};