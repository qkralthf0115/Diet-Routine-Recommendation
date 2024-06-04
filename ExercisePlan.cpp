#include "ExercisePlan.h"

void ExercisePlan::generateWeeklyPlan(const std::vector<WorkoutItem>& workoutList, int exerciseDays, int dailyCalories) {
  weeklyPlan.clear();
  std::vector<bool> usedWorkouts(workoutList.size(), false);
  for (int i = 0; i < exerciseDays; ++i) {
    WorkoutPlan dailyWorkoutPlan;
    dailyWorkoutPlan.generateDailyWorkout(workoutList, dailyCalories, usedWorkouts);
    weeklyPlan.push_back(dailyWorkoutPlan);
  }
}

void ExercisePlan::printWeeklyPlan() const {
  for (int i = 0; i < weeklyPlan.size(); ++i) {
    std::cout << "Day " << (i + 1) << " Plan:" << std::endl;
    const auto& dailyWorkouts = weeklyPlan[i].getDailyWorkouts();
    if (dailyWorkouts.empty()) {
      std::cout << "  No workouts available." << std::endl; // Debug statement
    }
    else {
      for (const auto& workout : dailyWorkouts) {
        std::cout << "- " << workout.getName() << " (" << workout.getCaloriesBurned() << " calories)" << std::endl;
        std::cout << "  Video Link: " << workout.getVideoLink() << std::endl;
      }
    }
    std::cout << std::endl;
  }
}