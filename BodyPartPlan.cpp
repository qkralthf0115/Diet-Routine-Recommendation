#include <iostream>
#include "ExercisePlan.h"

class BodyPartPlan : public ExercisePlan {
private:
  std::string bodyPart;
public:
  void generateExercisePlan() {
    std::cout << "Exercise plan for " << bodyPart << " generated." << std::endl;
  }
};
