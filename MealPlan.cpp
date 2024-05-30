//�ѳ� �Ļ� ����, �־��� ���� ��ϰ� Į�θ� ���� �������� �Ļ� ����
#include<iostream>
#include<random>
#include"MealPlan.h"

MealPlan::MealPlan(std::vector<FoodItem> mealItem) : mealItem(mealItem) {}

std::vector<FoodItem> MealPlan::generateMeal(FoodDatabase& db , int maxCalories, std::vector<std::string>& exclusion)
	{
		mealItem.clear();
		int totalCalories = 0;

		std::random_device rd;
		auto available = db.getFoodList(exclusion);
		std::shuffle(available.begin(),available.end(),std::default_random_engine(rd()));

		for (auto food : available)
		{
			if (totalCalories + food.getCalories() <= maxCalories)
			{
				mealItem.push_back(food);
				totalCalories += food.getCalories();
			}
			if (totalCalories >= maxCalories)
			{
				break;
			}
		}
		if (mealItem.empty())
		{
			std::cout << "Cannot create a meal. Include foods." << std::endl;
		}
		return mealItem;
	}