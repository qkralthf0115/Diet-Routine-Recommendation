#pragma once
#include<memory>
#include"Command.h"
#include"DietPlan.h"
#include"FoodDatabase.h"

class MealCommand : public Command
{
private:
	std::shared_ptr<DietPlan> dietPlan;
	FoodDatabase& db;
	std::string name = "Meal Recommendation";
public:
	MealCommand(std::shared_ptr<DietPlan> dietPlan, FoodDatabase& db);
	void execute() override;
	std::string getName() const;

};