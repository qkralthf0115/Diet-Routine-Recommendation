#pragma once
#include<vector>
#include<string>
#include<memory>
#include"MealPlan.h"

class DietPlan
{
private:
	int totalCalories;
	std::vector<std::string> exclusion;
	std::vector<std::shared_ptr<MealPlan>> weeklyPlan;

public:
	DietPlan(int totalCalories);
	void generatePlan(FoodDatabase& db);
	void printPlan() const;
	void setExclusion(std::vector<std::string>& exclusion);
};