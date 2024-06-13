#include "ExercisePlan.h"

void ExercisePlan::generateWeeklyPlan(const std::vector<WorkoutItem>& workoutList, int exerciseDays, double dailyCalories) {
  weeklyPlan.clear();

  for (int i = 0; i < exerciseDays; ++i) {
    WorkoutPlan dailyWorkoutPlan;
    dailyWorkoutPlan.generateDailyWorkout(workoutList, dailyCalories);
    weeklyPlan.push_back(dailyWorkoutPlan);
  }
}

void ExercisePlan::printWeeklyPlan() const {
  std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
  for (int i = 0; i < weeklyPlan.size(); ++i) {
    std::cout << "\033[0;35m" << "Day " << (i + 1) << "\033[0;37m" << std::endl;
    const auto& dailyWorkouts = weeklyPlan[i].getDailyWorkouts();
    if (dailyWorkouts.empty()) {
      std::cout << "  No workouts available." << std::endl; // Debug statement
    }
    else {
      for (const auto& workout : dailyWorkouts) {
        std::cout << "\033[0;33m" << workout.getName() << "\033[0;37m" << " (" << workout.getCaloriesBurned() << " kcal)" << std::endl;
        std::cout << "Video Link: " << workout.getVideoLink() << std::endl;
      }
      std::cout << std::endl;
    }
  }
}