#include <iostream>
#include "BodyPartPlan.cpp"
#include "ExercisePlan.h"

class BodyPartPlan : public ExercisePlan {
private:
  std::string bodyPart;
public:
  BodyPartPlan(std::string bodyPart) : bodyPart(bodyPart) {}
  void generatePlan() {}
};

void BodyPartPlan::generatePlan(const ExerciseData& db) {
  exercises = db.getExercisesByFocusArea(bodyPart);
  c
    caloriesPerWeek = 500 * exercises.size();
}
