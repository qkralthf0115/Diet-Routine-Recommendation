#include <iostream>

using namespace std;

class ExercisePlan {
private:
  string name;
  double caloriesBurned;
public:
  virtual void generateExercisePlan() = 0;
};