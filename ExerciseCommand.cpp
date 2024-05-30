#include <iostream>
#include <memory>
#include "ExercisePlan.h"

class ExerciseCommand {
private:
  std::shared_ptr<ExercisePlan> exercisePlan;
public:
  virtual void execute() = 0;
};

