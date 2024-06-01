#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "WorkoutItem.cpp"
#include "BodyArea.h"

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
  void loadWorkoutList(const std::string& filename) {
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

  std::vector<WorkoutItem> filterByArea(BodyArea targetArea) {
    std::vector<WorkoutItem> filteredList;
    for (const auto& workout : workoutList) {
      if (workout.getFocusArea() == targetArea) {
        filteredList.push_back(workout);
      }
    }
    return filteredList;
  }
};