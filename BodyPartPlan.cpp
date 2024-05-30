#include <iostream>
#include "ExercisePlan.h"
using namespace std;

class BodyPartPlan : public ExercisePlan {
private:
  string bodyPart;
public:
  void generateExercisePlan() {
    cout << "Exercise plan for " << bodyPart << " generated." << endl;
  }
};
