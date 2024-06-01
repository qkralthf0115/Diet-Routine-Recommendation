#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan() {
  srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

void WorkoutPlan::generateDailyWorkout(const std::vector<WorkoutItem>& workoutList, int dailyCalories) {
  dailyWorkouts.clear();
  int totalCalories = 0;
  while (dailyCalories - 500 <= totalCalories && totalCalories <= dailyCalories + 500) {
    int randomIndex = rand() % workoutList.size();
    dailyWorkouts.push_back(workoutList[randomIndex]);
    totalCalories += workoutList[randomIndex].getCaloriesBurned();
  }
}

const std::vector<WorkoutItem>& WorkoutPlan::getDailyWorkouts() const {
  return dailyWorkouts;
}