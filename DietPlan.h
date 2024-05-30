#pragma once
#include<vector>
#include<string>

class DietPlan
{
private:
	int totalCalories;
	std::vector<std::string> exclusion;
	std::vector<std::vector<std::string>> weeklyPlan;

public:
	DietPlan(int totalCalories);
	void generatePlan();
	void printPlan() const;
	void setExclusion(std::vector<std::string>& exclusion);
};