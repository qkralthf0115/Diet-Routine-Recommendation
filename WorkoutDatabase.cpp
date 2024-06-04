#include "WorkoutDatabase.h"

BodyArea WorkoutDatabase::stringToBodyArea(const std::string& areaStr) {
  if (areaStr == "UpperBody") return BodyArea::UpperBody;
  else if (areaStr == "LowerBody") return BodyArea::LowerBody;
  else if (areaStr == "Core") return BodyArea::Core;
  else if (areaStr == "Back") return BodyArea::Back;
  else if (areaStr == "FullBody") return BodyArea::FullBody;
  else throw std::invalid_argument("Unknown body area: " + areaStr);
}

void WorkoutDatabase::loadWorkoutList(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string name, focusAreaStr, videoLink;
    int caloriesBurned;
    if (!(iss >> name >> focusAreaStr >> caloriesBurned >> videoLink)) {
      std::cerr << "Error parsing line: " << line << std::endl;
      continue;
    }
    try {
      BodyArea focusArea = stringToBodyArea(focusAreaStr);
      workoutList.push_back(WorkoutItem(name, focusArea, caloriesBurned, videoLink));
    }
    catch (const std::invalid_argument& e) {
      std::cerr << "Invalid focus area: " << focusAreaStr << " in line: " << line << std::endl;
      continue;
    }
  }
}

std::vector<WorkoutItem> WorkoutDatabase::getWorkoutListByArea(BodyArea targetArea) {
  std::vector<WorkoutItem> filteredList;
  for (const auto& workout : workoutList) {
    if (workout.getFocusArea() == targetArea) {
      filteredList.push_back(workout);
    }
  }
  return filteredList;
}