#include <iostream>
#include <vector>
#include "ExerciseData.cpp"

class ExercisePlan {
private:
  std::vector<Exercise> exercises;
  std::string name;
  int caloriesPerWeek = 0;

public:
  virtual void generatePlan(const ExerciseData& db) = 0;
};