#include <string>
#include "WorkoutItem.h"


std::string WorkoutItem::getName() const { return name; }
BodyArea WorkoutItem::getFocusArea() const { return focusArea; }
int WorkoutItem::getCaloriesBurned() const { return caloriesBurned; }
std::string WorkoutItem::getVideoLink() const { return videoLink; }