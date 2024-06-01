#include<string>
#include"FoodItem.h"

FoodItem::FoodItem(std::string& name, int calories) : name(name), calories(calories) {}

std::string FoodItem::getName() const
{
	return name;
}

int FoodItem::getCalories() const
{
	return calories;
}