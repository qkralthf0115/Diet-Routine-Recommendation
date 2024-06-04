#pragma once
#include <vector>
#include <cstdlib> // rand()
#include <ctime> // time()
#include "WorkoutItem.h"

class WorkoutPlan {
private:
  std::vector<WorkoutItem> dailyWorkouts;

public:
  WorkoutPlan();
  void generateDailyWorkout(const std::vector<WorkoutItem>& workoutList, double dailyCalories, std::vector<bool>& usedWorkouts);
  const std::vector<WorkoutItem>& getDailyWorkouts() const;
};