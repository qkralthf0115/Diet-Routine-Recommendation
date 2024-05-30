//전체 식단 계획 관리, 일주일 식단 생성
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