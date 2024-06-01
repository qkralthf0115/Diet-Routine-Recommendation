#include"MealCommand.h"

MealCommand::MealCommand(std::shared_ptr<DietPlan> dietPlan) : dietPlan(dietPlan) {}

void MealCommand::execute() override
{
	dietPlan->generatePlan();
	dietPlan->printPlan();
}