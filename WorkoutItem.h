#include <string>
#include "BodyArea.h"
#pragma once

class WorkoutItem {
private:
  std::string name;
  BodyArea focusArea;
  int caloriesBurned;
  std::string videoLink;

public:
  WorkoutItem(const std::string& name, BodyArea focusArea, int caloriesBurned, const std::string& videoLink)
    : name(name), focusArea(focusArea), caloriesBurned(caloriesBurned), videoLink(videoLink) {
  }

  std::string getName() const;
  BodyArea getFocusArea() const;
  int getCaloriesBurned() const;
  std::string getVideoLink() const;
};