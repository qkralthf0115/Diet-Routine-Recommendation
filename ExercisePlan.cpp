#include "ExercisePlan.h"

void ExercisePlan::generateWeeklyPlan(const std::vector<WorkoutItem>& workoutList, int exerciseDays, int dailyCalories) {
  weeklyPlan.clear();
  for (int i = 0; i < exerciseDays; ++i) {
    WorkoutPlan workoutPlan;
    workoutPlan.generateDailyWorkout(workoutList, dailyCalories);
    weeklyPlan.push_back(workoutPlan);
  }
}

void ExercisePlan::printWeeklyPlan() const {
  for (int i = 0; i < weeklyPlan.size(); ++i) {
    std::cout << "Day " << (i + 1) << " Plan:" << std::endl;
    const auto& dailyWorkouts = weeklyPlan[i].getDailyWorkouts();
    for (const auto& workout : dailyWorkouts) {
      std::cout << "- " << workout.getName() << " (" << workout.getCaloriesBurned() << " calories)" << std::endl;
      std::cout << "  Video Link: " << workout.getVideoLink() << std::endl;
    }
  }
}