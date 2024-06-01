#include <iostream>
#include <vector>
#include <cstdlib> // 랜덤
#include <ctime> // 랜덤 숫자 생성을 위한 시간
#include "WorkoutItem.cpp"

class ExercisePlan {
private:
  std::string name;
  int caloriesBurned;
  std::vector<std::vector<WorkoutItem>> weeklyPlan;

public:
  void generatePlan(const std::vector<WorkoutItem>& workouts, int exerciseDays) {
    srand(static_cast<unsigned int>(time(0))); // 랜덤 숫자 생성

    int dailyCalories = calculateDailyCalories();
    for (int i = 0; i < 7; ++i) {
      std::vector<WorkoutItem> dailyWorkouts;
      int totalCalories = 0;
      while (totalCalories < dailyCalories) {
        int randomIndex = rand() % workouts.size();
        dailyWorkouts.push_back(workouts[randomIndex]);
        totalCalories += workouts[randomIndex].getCaloriesBurned();
      }
      weeklyPlan.push_back(dailyWorkouts);
    }
  }

  void printPlan() {
    for (int i = 0; i < weeklyPlan.size(); ++i) {
      std::cout << "Day " << (i + 1) << " Plan:" << std::endl;
      for (const auto& workout : weeklyPlan[i]) {
        std::cout << "- " << workout.getName() << " (" << workout.getCaloriesBurned() << " calories)" << std::endl;
        std::cout << "  Video Link: " << workout.getVideoLink() << std::endl;
      }
    }
  }

  int calculateDailyCalories() {

    return 500;
  }
};