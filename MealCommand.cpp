#include"MealCommand.h"
#include<iostream>
#include<sstream>
#include"FoodDatabase.h"

void MealCommand::execute()
{
	std::vector<std::string> exclude;
	std::string input;
	std::cout << "Foods you do not want to eat (separate by spaces): ";
	std::getline(std::cin, input);

	std::stringstream ss(input);
	std::string item;
	while (ss >> item)
	{
		exclude.push_back(item);
	}

	FoodDatabase db;
	db.loadFoodList("foodlist.txt");
	db.setExclusion(exclude);
	dietPlan->generatePlan(db);
	dietPlan->printPlan();
}