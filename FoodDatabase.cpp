#include<fstream>
#include"FoodDatabase.h"

void FoodDatabase::loadFoodList(std::string filename)
	{
		std::ifstream file(filename);
		std::string name;
		int calories;
		while (file >> name >> calories)
		{
			foodList.emplace_back(name, calories);
		}
	}

std::vector<FoodItem> FoodDatabase::getFoodList(std::vector<std::string>& exclude)
	{
		std::vector<FoodItem> excludedList;
		for (auto& food : foodList)
		{
			if (std::find(exclude.begin(), exclude.end(), food.getName()) == exclude.end())
			{
				excludedList.push_back(food);
			}
		}
		return excludedList;
	}