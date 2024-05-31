#include<iostream>
#include"DietPlan.h"

DietPlan::DietPlan(int totalCalories): totalCalories(totalCalories){}

void DietPlan::generatePlan()
{

}

void DietPlan::printPlan() const
{

}

void DietPlan::setExclusion(std::vector<std::string>& exclusion)
{
	this->exclusion = exclusion;
}