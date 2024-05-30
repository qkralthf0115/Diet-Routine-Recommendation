#pragma once
#include<vector>
#include"FoodItem.h"

class FoodDatabase
{
private:
	std::vector<FoodItem> foodList;
public:
	void loadFoodList(std::string fileName);

	std::vector<FoodItem> getFoodList(std::vector<std::string>& exclude);
};