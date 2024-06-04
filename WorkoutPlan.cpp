#include "WorkoutPlan.h"

WorkoutPlan::WorkoutPlan() {
  srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

void WorkoutPlan::generateDailyWorkout(const std::vector<WorkoutItem>& workoutList, double dailyCalories, std::vector<bool>& usedWorkouts) {
  dailyWorkouts.clear();
  int totalCalories = 0;
  if (workoutList.empty()) {
    std::cout << "No workouts available to generate daily workout." << std::endl;
    return;
  }
  std::vector<int> availableIndices;
  for (size_t i = 0; i < workoutList.size(); ++i) {
    if (!usedWorkouts[i]) {
      availableIndices.push_back(i);
    }
  }
  if (availableIndices.empty()) {
    std::cout << "No more workouts available to generate daily workout." << std::endl;
    return;
  }
  while (totalCalories < dailyCalories) {
    if (availableIndices.empty()) {
      std::cout << "Ran out of available workouts to reach the calorie target." << std::endl;
      break;
    }

    int randomIndex = rand() % workoutList.size();
    int workoutIndex = availableIndices[randomIndex];
    if (workoutIndex >= workoutList.size() || workoutIndex < 0) {
      std::cerr << "Invalid workout index: " << workoutIndex << std::endl;
      continue;
    }
    const WorkoutItem& workout = workoutList[workoutIndex];

    if (totalCalories + workout.getCaloriesBurned() <= dailyCalories + 500) {
      dailyWorkouts.push_back(workout);
      totalCalories += workout.getCaloriesBurned();
      usedWorkouts[workoutIndex] = true;
    }
    availableIndices.erase(availableIndices.begin() + randomIndex);
  }
  std::cout << "Generated daily workout with " << dailyWorkouts.size() << " exercises." << std::endl;
}

const std::vector<WorkoutItem>& WorkoutPlan::getDailyWorkouts() const {
  return dailyWorkouts;
}