#pragma once
#include <string>
#include "BodyArea.h"

class WorkoutItem {
private:
  std::string name;
  BodyArea focusArea;
  double caloriesBurned;
  std::string videoLink;

public:
  WorkoutItem(const std::string& name, BodyArea focusArea, double caloriesBurned, const std::string& videoLink);
  std::string getName() const;
  BodyArea getFocusArea() const;
  double getCaloriesBurned() const;
  std::string getVideoLink() const;
};