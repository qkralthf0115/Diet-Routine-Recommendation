#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "WorkoutItem.h"

class WorkoutDatabase {
private:
  std::vector<WorkoutItem> workoutList;

  BodyArea stringToBodyArea(const std::string& areaStr) {
    if (areaStr == "UpperBody") return BodyArea::UpperBody;
    else if (areaStr == "LowerBody") return BodyArea::LowerBody;
    else if (areaStr == "Core") return BodyArea::Core;
    else if (areaStr == "Back") return BodyArea::Back;
    else if (areaStr == "FullBody") return BodyArea::FullBody;
    else throw std::invalid_argument("Unknown body area: " + areaStr);
  }

public:
  void loadWorkoutList(const std::string& filename);
  std::vector<WorkoutItem> filterByArea(BodyArea targetArea);
};