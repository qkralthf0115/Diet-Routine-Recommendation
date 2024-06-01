#include <string>
#include "WorkoutItem.h"

WorkoutItem::WorkoutItem(const std::string& name, BodyArea focusArea, int caloriesBurned, const std::string& videoLink)
  : name(name), focusArea(focusArea), caloriesBurned(caloriesBurned), videoLink(videoLink) {
}
std::string WorkoutItem::getName() const { return name; }
BodyArea WorkoutItem::getFocusArea() const { return focusArea; }
int WorkoutItem::getCaloriesBurned() const { return caloriesBurned; }
std::string WorkoutItem::getVideoLink() const { return videoLink; }