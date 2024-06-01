#include <iostream>
#include <memory>
#include "ExercisePlan.h"

class ExerciseCommand {
private:
  UserInfo& userInfo;
  ExercisePlan* exercisePlan;
  ExerciseData& db;
public:
  ExerciseCommand(UserInfo& ui, ExerciseDatae& database) : userInfo(ui), exercisePlan(nullptr), db(database) {}
  virtual void execute() = 0;
  void displayPlan();
};


void ExerciseCommand::execute() {
  std::string targetArea;
  std::cout << "관심 있는 신체 부위가 있나요? (상체, 하체, 코어, 등, 전신): ";
  std::cin >> targetArea;

  if (targetArea == "전신" || targetArea == "") {
    exercisePlan = new FullBodyPlan();
  }
  else {
    exercisePlan = new BodyPartPlan(targetArea);
  }

  exercisePlan->generatePlan();
  displayPlan();
  delete exercisePlan;
}

void ExerciseCommand::displayPlan() {
  std::cout << std::endl << "추천 운동 루틴 (" << userInfo.workoutDaysPerWeek << "일):" << std::endl;
  for (int i = 0; i < userInfo.workoutDaysPerWeek; ++i) {
    std::cout << "Day " << i + 1 << ":" << std::endl;
    for (const auto& exercise : exercisePlan->exercises) {
      std::cout << "- " << exercise.name << " (칼로리 소모량: " << exercise.burnedCalories << ")" << std::endl;
    }
  }
}
