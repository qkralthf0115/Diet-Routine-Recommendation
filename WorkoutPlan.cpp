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
  std::vector<bool> dailyUsedWorkouts(workoutList.size(), false);

  while (totalCalories < dailyCalories + 500) {
    if (std::all_of(dailyUsedWorkouts.begin(), dailyUsedWorkouts.end(), [](bool b) { return b; })) {
      std::cout << "No more workouts available to generate daily workout." << std::endl;
      break;
    }
    int randomIndex = rand() % workoutList.size();
    if (!usedWorkouts[randomIndex] && !dailyUsedWorkouts[randomIndex]) {
      const WorkoutItem& workout = workoutList[randomIndex];
      dailyWorkouts.push_back(workout);
      totalCalories += workout.getCaloriesBurned();
      dailyUsedWorkouts[randomIndex] = true;
    }
  }

  for (size_t i = 0; i < workoutList.size(); ++i) {
    if (dailyUsedWorkouts[i]) {
      usedWorkouts[i] = true;
    }
  }
  std::cout << "Generated daily workout with " << dailyWorkouts.size() << " exercises." << std::endl;
}

const std::vector<WorkoutItem>& WorkoutPlan::getDailyWorkouts() const {
  return dailyWorkouts;
}