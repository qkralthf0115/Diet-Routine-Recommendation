#include <iostream>
#include <string>
#include <vector>
#include "ExercisePlan.h"
#include "WorkoutDatabase.cpp"
#include "BodyArea.h

class ExerciseCommand : public Command {
private:
  BodyArea stringToBodyArea(const std::string& areaStr) {
    if (areaStr == "UpperBody") return BodyArea::UpperBody;
    else if (areaStr == "LowerBody") return BodyArea::LowerBody;
    else if (areaStr == "Core") return BodyArea::Core;
    else if (areaStr == "Back") return BodyArea::Back;
    else if (areaStr == "FullBody") return BodyArea::FullBody;
    else throw std::invalid_argument("Unknown body area: " + areaStr);
  }
public:
  virtual void execute() = 0;
};


void ExerciseCommand::execute() {
  std::string targetAreaStr;
  int exerciseDays;

  std::cout << "Enter target body area (UpperBody, LowerBody, Core, Back, FullBody): ";
  std::cin >> targetAreaStr;
  BodyArea targetArea = stringToBodyArea(targetAreaStr);

  std::cout << "Enter number of exercise days per week: ";
  std::cin >> exerciseDays;

  WorkoutDatabase workoutDb;
  workoutDb.loadWorkoutList("ExerciseData.txt");
  auto filteredWorkouts = workoutDb.filterByArea(targetArea);

  ExercisePlan exercisePlan;
  exercisePlan.generatePlan(filteredWorkouts, exerciseDays);
  exercisePlan.printPlan();
}
