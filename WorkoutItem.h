#pragma once
#include <string>
#include "BodyArea.h"

class WorkoutItem {
private:
  std::string name;
  BodyArea focusArea;
  int caloriesBurned;
  std::string videoLink;

public:
  WorkoutItem(const std::string& name, BodyArea focusArea, int caloriesBurned, const std::string& videoLink);
  std::string getName() const;
  BodyArea getFocusArea() const;
  int getCaloriesBurned() const;
  std::string getVideoLink() const;
};