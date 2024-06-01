#include <iostream>
#include <vector>
#include "ExerciseData.cpp"

class ExercisePlan {
private:
  std::vector<Exercise> exercises;


public:
  virtual void generatePlan(const ExerciseData& db) = 0;
};