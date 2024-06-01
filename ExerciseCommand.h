#pragma once
#include <iostream>
#include <string>
#include "Command.h"
#include "ExercisePlan.h"
#include "WorkoutDatabase.h"
#include "BodyArea.h"

class ExerciseCommand : public Command {
public:
  void execute() override;

private:
  BodyArea stringToBodyArea(const std::string& areaStr);
  int calculateDailyCalories();
};