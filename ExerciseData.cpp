#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class ExerciseData {
private:
  std::vector<Exercise> exercises;

public:
  void loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
      std::stringstream ss(line);
      std::string name, focusArea, burnedCaloriesStr;
      std::getline(ss, name, ',');
      std::getline(ss, focusArea, ',');
      std::getline(ss, burnedCaloriesStr, ',');
      int burnedCalories = std::stoi(burnedCaloriesStr);
      exercises.emplace_back(name, focusArea, burnedCalories);
    }
  }

  const std::vector<Exercise>& getExercises() const {
    return exercises;
  }

  std::vector<Exercise> getExercisesByFocusArea(const std::string& focusArea) const {
    std::vector<Exercise> result;
    for (const auto& exercise : exercises) {
      if (exercise.focusArea == focusArea) {
        result.push_back(exercise);
      }
    }
    return result;
  }
};