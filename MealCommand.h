#pragma once
#include<memory>
#include"Command.h"
#include"DietPlan.h"

class MealCommand : public Command
{
private:
	std::shared_ptr<DietPlan> dietPlan;
public:
	MealCommand(std::shared_ptr<DietPlan> dietPlan);
	void execute() override;

};