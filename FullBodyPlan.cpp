#include <iostream>
#include "ExercisePlan.h"

class FullBodyPlan : public ExercisePlan {
public:
  void generatePlan(const ExerciseData& db) {}
};

void FullBodyPlan::generatePlan() {
  exercises = db.getExercises();
  for (const auto& exercise : exercises) {
    caloriesPerWeek += exercise.burnedCalories;
  }
}
