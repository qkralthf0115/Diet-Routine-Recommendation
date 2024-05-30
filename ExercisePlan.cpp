#include <iostream>

using namespace std;

class ExercisePlan {
private:
  string name;
  double caloriesBurned;
public:
  virtual void generateExercisePlan() = 0;
};

class BodyPartPlan : public ExercisePlan {
private:
  string bodyPart;
public:
  void generateExercisePlan() {
    cout << "Exercise plan for " << bodyPart << " generated." << endl;
  }
};

class FullBodyPlan : public ExercisePlan {
public:
  void generateExercisePlan() {
    cout << "Full body exercise plan generated." << endl;
  }
};
