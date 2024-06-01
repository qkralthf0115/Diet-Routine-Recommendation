#include <iostream>
#include "ExercisePlan.h"

class BodyPartPlan : public ExercisePlan {
private:
  std::string bodyPart;
public:
  BodyPartPlan(std::string& part) : bodyPart(part) {}
  void generatePlan(const ExerciseData& db) {}
};

void BodyPartPlan::generatePlan(const ExerciseData& db) {
  exercises = db.getExercisesByFocusArea(bodyPart);
  for (const auto& exercise : exercises) {
    caloriesPerWeek += exercise.burnedCalories;
  }
}
