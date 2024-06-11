#include <fstream>
#include <algorithm>
#include"FoodDatabase.h"

void FoodDatabase::loadFoodList(const std::string& filename) {
	std::ifstream file(filename);
	std::string name;
	int calories;
	while (file >> name >> calories) {
		foodList.emplace_back(name, calories);
	}
}
void FoodDatabase::setExclusion(const std::vector<std::string>& exclude) {
	exclusion = exclude;
}
std::vector<FoodItem> FoodDatabase::getFoodList() const {
	std::vector<FoodItem> excludedList;
	for (const auto& food : foodList) {
		if (std::none_of(exclusion.begin(), exclusion.end(),[&food](const std::string &ex) {
			return food.getName().find(ex) !=std::string::npos;
		})) {
			excludedList.push_back(food);
		}
	}
	return excludedList;
}