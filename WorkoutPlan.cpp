#include <vector>
#include "WorkoutItem.cpp"

class WorkoutPlan {
private:
  std::vector<WorkoutItem> workoutItems;
  int dailyCalories = 500;

public:
  void generateWorkout(const std::vector<WorkoutItem>& filteredWorkouts) {
    workoutItems = filteredWorkouts;
  }

  std::vector<WorkoutItem> getWorkoutItems() const {
    return workoutItems;
  }

  int getDailyCalories() const {
    return dailyCalories;
  }
};