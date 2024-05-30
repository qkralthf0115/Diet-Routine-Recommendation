#include <iostream>
#include "ExercisePlan.h"
using namespace std;

class FullBodyPlan : public ExercisePlan {
public:
  void generateExercisePlan() {
    cout << "Full body exercise plan generated." << endl;
  }
};
