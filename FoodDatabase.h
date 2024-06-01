//Manage the list of foods
#pragma once
#include<vector>
#include"FoodItem.h"

class FoodDatabase
{
private:
	std::vector<FoodItem> foodList;
public:
	//load food list from txt file
	void loadFoodList(std::string fileName);
	//get food list after excluding unwanted foods
	std::vector<FoodItem> getFoodList(std::vector<std::string>& exclude);
};