#pragma once
#include<vector>
#include<string>
#include"MealPlan.h"

class DietPlan
{
private:
	std::vector<MealPlan> weeklyPlan;

public:
	DietPlan();
	void generatePlan(const std::vector<FoodItem>& foodList, double maxCalories);
	void printPlan() const;
};