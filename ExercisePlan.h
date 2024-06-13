#pragma once
#include <iostream>
#include <iomanip>
#include "WorkoutPlan.h"

class ExercisePlan {
private:
  std::vector<WorkoutPlan> weeklyPlan;

public:
  void generateWeeklyPlan(const std::vector<WorkoutItem>& workoutList, int exerciseDays, double dailyCalories);
  void printWeeklyPlan() const;
};
