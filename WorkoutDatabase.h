#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "WorkoutItem.h"
#include "BodyArea.h"

class WorkoutDatabase {
private:
  std::vector<WorkoutItem> workoutList;
  BodyArea stringToBodyArea(const std::string& areaStr);

public:
  void loadWorkoutList(const std::string& filename);
  std::vector<WorkoutItem> getWorkoutListByArea(BodyArea targetArea);
};