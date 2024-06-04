#include "WorkoutPlan.h"
#include <iostream>
#include <algorithm>
#include <random>

WorkoutPlan::WorkoutPlan() {
  srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

void WorkoutPlan::generateDailyWorkout(const std::vector<WorkoutItem>& workoutList, double dailyCalories) {
  dailyWorkouts.clear();
  int totalCalories = 0;

  if (workoutList.empty()) {
    std::cout << "No workouts available to generate daily workout." << std::endl;
    return;
  }

  std::vector<WorkoutItem> availableWorkouts = workoutList;
  std::random_device rd;
  std::default_random_engine rng(rd());
  std::shuffle(availableWorkouts.begin(), availableWorkouts.end(), rng);

  for (const auto& workout : availableWorkouts) {
    if (totalCalories + workout.getCaloriesBurned() <= dailyCalories) {
      dailyWorkouts.push_back(workout);
      totalCalories += workout.getCaloriesBurned();
    }
    if (totalCalories >= dailyCalories) {
      break;
    }
  }
  if (dailyWorkouts.empty()) {
    std::cout << "Cannot create a daily workout. Include more workouts." << std::endl;
  }
}

const std::vector<WorkoutItem>& WorkoutPlan::getDailyWorkouts() const {
  return dailyWorkouts;
}