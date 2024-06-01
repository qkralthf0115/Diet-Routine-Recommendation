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
void FoodDatabase::setExclusion(std::vector<std::string>& exclude)
{
	this->exclusion = exclude;
}
std::vector<FoodItem> FoodDatabase::getFoodList()
	{
		std::vector<FoodItem> excludedList;
		for (auto& food : foodList)
		{
			if (std::find(exclusion.begin(), exclusion.end(), food.getName()) == exclusion.end())
			{
				excludedList.push_back(food);
			}
		}
		return excludedList;
	}