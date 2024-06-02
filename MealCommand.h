#pragma once
#include<memory>
#include"Command.h"
#include"DietPlan.h"
#include"UserInfo.h"

class MealCommand : public Command
{
private:
	std::shared_ptr<UserInfo> userInfo;
	DietPlan dietPlan;
	std::string name = "Meal Recommendation";
public:
	MealCommand();
	void execute() override;
	std::string getName() const;

};