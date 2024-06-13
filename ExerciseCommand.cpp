#include "ExerciseCommand.h"

ExerciseCommand::ExerciseCommand(std::shared_ptr<UserInfo> userInfo) : userInfo(userInfo) {}

void ExerciseCommand::execute() {
  std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
  std::cout << "\033[0;33m" << "Exercise Recommendation" << "\033[0;37m" << std::endl;
  if (!userInfo->getName().empty()) {
    std::vector<BodyArea> targetAreas;
    std::string targetAreaStr;

    std::cout << "Enter target body areas" << "\033[0;35m" << " (UpperBody, LowerBody, Core, Back, FullBody)" << "\033[0;37m" << " separated by spaces. " << std::endl;
    std::cout << ":";
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

    std::cout << "Enter number of exercise days per week: ";
    std::cin >> exerciseDays;

    double dailyCalories = calculateDailyCalories();

    WorkoutDatabase workoutDb;
    workoutDb.loadWorkoutList("ExerciseData.txt");

    std::vector<WorkoutItem> filteredWorkouts;
    for (const auto& area : targetAreas) {
      auto areaWorkouts = workoutDb.getWorkoutListByArea(area);
      filteredWorkouts.insert(filteredWorkouts.end(), areaWorkouts.begin(), areaWorkouts.end());
    }

    ExercisePlan exercisePlan;
    exercisePlan.generateWeeklyPlan(filteredWorkouts, exerciseDays, dailyCalories);
    exercisePlan.printWeeklyPlan();
  }
  else {
    std::cout << "Please input user information first." << std::endl;
  }
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
  double weeklyExerciseCalories = userInfo->calculateExerciseCalories();
  if (exerciseDays <= 0) {
    std::cerr << "Invalid number of exercise days. Must be greater than zero." << std::endl;
    return 0;
  }
  double dailyCalories = weeklyExerciseCalories / exerciseDays;
  std::cout << "Daily exercise calories: " << dailyCalories << std::endl;
  return dailyCalories;
}

std::string ExerciseCommand::getName() const {
  return "Exercise Recommendation";
}

int ExerciseCommand::getDays() const {
  return exerciseDays;
}