#include "ExerciseCommand.h"


void ExerciseCommand::execute() {
  std::string targetAreaStr;
  int exerciseDays;

  std::cout << "Enter target body area (UpperBody, LowerBody, Core, Back, FullBody): ";
  std::cin >> targetAreaStr;
  BodyArea targetArea = stringToBodyArea(targetAreaStr);

  std::cout << "Enter number of exercise days per week: ";
  std::cin >> exerciseDays;

  int dailyCalories = calculateDailyCalories(); // You need to implement this method

  WorkoutDatabase workoutDb;
  workoutDb.loadWorkoutList("Exercise_Data.txt");
  auto filteredWorkouts = workoutDb.filterByArea(targetArea);

  ExercisePlan exercisePlan;
  exercisePlan.generateWeeklyPlan(filteredWorkouts, exerciseDays, dailyCalories);
  exercisePlan.printWeeklyPlan();
}

BodyArea ExerciseCommand::stringToBodyArea(const std::string& areaStr) {
  if (areaStr == "UpperBody") return BodyArea::UpperBody;
  else if (areaStr == "LowerBody") return BodyArea::LowerBody;
  else if (areaStr == "Core") return BodyArea::Core;
  else if (areaStr == "Back") return BodyArea::Back;
  else if (areaStr == "FullBody") return BodyArea::FullBody;
  else throw std::invalid_argument("Unknown body area: " + areaStr);
}

int ExerciseCommand::calculateDailyCalories() {
  return 500;
}
