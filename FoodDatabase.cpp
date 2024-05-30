//음식 데이터베이스, 파일에서 음식 목록을 로드하고, 제공된 제외 목록을 기준으로 필터링

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