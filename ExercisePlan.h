#include <iostream>

class ExercisePlan {
private:
  std::string name;
  double caloriesBurned;
public:
  virtual void generateExercisePlan() = 0;
};