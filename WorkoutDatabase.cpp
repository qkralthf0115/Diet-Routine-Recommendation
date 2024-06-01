#include "WorkoutDatabase.h"

void WorkoutDatabase::loadWorkoutList(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string name, focusAreaStr, videoLink;
    int caloriesBurned;
    if (!(iss >> name >> focusAreaStr >> caloriesBurned >> videoLink)) { break; }
    BodyArea focusArea = stringToBodyArea(focusAreaStr);
    workoutList.push_back(WorkoutItem(name, focusArea, caloriesBurned, videoLink));
  }
}

std::vector<WorkoutItem> WorkoutDatabase::filterByArea(BodyArea targetArea) {
  std::vector<WorkoutItem> filteredList;
  for (const auto& workout : workoutList) {
    if (workout.getFocusArea() == targetArea) {
      filteredList.push_back(workout);
    }
  }
  return filteredList;
}