#pragma once
#include <iostream>
#include "WorkoutPlan.h"

class ExercisePlan {
private:
  std::vector<WorkoutPlan> weeklyPlan;

public:
  void generateWeeklyPlan(const std::vector<WorkoutItem>& workoutList, int exerciseDays, int dailyCalories);
  void printWeeklyPlan() const;
};
