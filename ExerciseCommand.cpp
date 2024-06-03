#include "ExerciseCommand.h"

ExerciseCommand::ExerciseCommand() {
  userInfo = std::make_shared<UserInfo>();
}
void ExerciseCommand::execute() {
  std::vector<BodyArea> targetAreas;
  std::string targetAreaStr;

  std::cout << "Enter target body area (UpperBody, LowerBody, Core, Back, FullBody): ";
  std::cin.ignore();
  std::getline(std::cin, targetAreaStr);
  std::istringstream iss(targetAreaStr);
  std::string area;
  while (iss >> area) {
    try {
      targetAreas.push_back(stringToBodyArea(area));
    }
    catch (const std::invalid_argument& e) {
      std::cout << "Invalid input: " << area << ". Please enter a valid body area." << std::endl;
    }
  }

  int exerciseDays;
  std::cout << "Enter number of exercise days per week: ";
  std::cin >> exerciseDays;

  int dailyCalories = calculateDailyCalories(); // You need to implement this method

  WorkoutDatabase workoutDb;
  workoutDb.loadWorkoutList("Exercise_Data.txt");

  std::vector<WorkoutItem> filteredWorkouts;
  for (const auto& area : targetAreas) {
    auto areaWorkouts = workoutDb.getWorkoutListByArea(area);
    filteredWorkouts.insert(filteredWorkouts.end(), areaWorkouts.begin(), areaWorkouts.end());
  }
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

double ExerciseCommand::calculateDailyCalories() {
  double dailyCalories = userInfo->calculateExerciseCalories();
  return dailyCalories;
}

std::string ExerciseCommand::getName() const {
  return "Exercise Recommendation";
}