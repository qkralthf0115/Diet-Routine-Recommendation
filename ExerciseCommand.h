#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Command.h"
#include "ExercisePlan.h"
#include "WorkoutDatabase.h"
#include "BodyArea.h"
#include "UserInfo.h"

class ExerciseCommand : public Command {
private:
  BodyArea stringToBodyArea(const std::string& areaStr);
  double calculateDailyCalories();
  std::shared_ptr<UserInfo> userInfo;
public:
  ExerciseCommand();
  void execute();
  std::string getName() const;
};