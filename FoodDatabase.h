#pragma once
#include <vector>
#include"FoodItem.h"

class FoodDatabase
{
private:
	std::vector<FoodItem> foodList;
	std::vector<std::string> exclusion;
public:
	void loadFoodList(const std::string& fileName);
	void setExclusion(const std::vector<std::string>& exclude);

	std::vector<FoodItem> getFoodList() const;
};