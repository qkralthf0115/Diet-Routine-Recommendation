//stores information of the food item including name, calories
#pragma once
#include<string>

class FoodItem
{
private:
	std::string name;
	int calories;
public:
	FoodItem(std::string& name, int calories);
	std::string getName() const;
	int getCalories() const;
};