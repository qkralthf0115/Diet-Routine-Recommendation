#pragma once
#include<vector>
#include"FoodItem.h"

class FoodDatabase
{
private:
	std::vector<FoodItem> foodList;
	std::vector<std::string> exclusion;
public:
	void loadFoodList(std::string fileName);
	void setExclusion(std::vector<std::string>& exclude);

	std::vector<FoodItem> getFoodList();
};