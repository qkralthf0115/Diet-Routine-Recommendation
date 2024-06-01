#include <string>

class Exercise {
private:
  std::string name;
  std::string focusArea;
  int caloriesBurned = 0;
  std::string videoLink;
public:
  WorkoutItem(const std::string& name, BodyArea focusArea, int caloriesBurned, const std::string& videoLink)
    : name(name), focusArea(focusArea), caloriesBurned(caloriesBurned), videoLink(videoLink) {
  }

  std::string getName() const { return name; }
  BodyArea getFocusArea() const { return focusArea; }
  int getCaloriesBurned() const { return caloriesBurned; }
  std::string getVideoLink() const { return videoLink; }
};