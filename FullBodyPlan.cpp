#include <iostream>
#include "ExercisePlan.h"

class FullBodyPlan : public ExercisePlan {
public:
  void generateExercisePlan() {
    std::cout << "Full body exercise plan generated." << std::endl;
  }
};
