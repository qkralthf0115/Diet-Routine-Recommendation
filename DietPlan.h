#pragma once
#include<vector>
#include<string>
#include<memory>
#include"MealPlan.h"
class DietPlan
{
private:
	std::vector<std::shared_ptr<MealPlan>> weeklyPlan;

public:
	DietPlan();
	void generatePlan(std::vector<FoodList> &foodlist);
	void printPlan() const;
};