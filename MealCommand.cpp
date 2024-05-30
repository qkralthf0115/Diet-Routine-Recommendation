#include"MealCommand.h"

MealCommand::MealCommand(std::shared_ptr<DietPlan> dietPlan) : dietPlan(dietPlan) {}

void MealCommand::execute()
{
	dietPlan->generatePlan();
	dietPlan->printPlan();
}