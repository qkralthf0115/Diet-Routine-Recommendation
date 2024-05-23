#include <iostream>

using namespace std;

class Workout {
private:
  string name;
  int focusArea;
  int caloriesBurned;
  string videoLink;
public:
  Workout(string name, int focusArea, int caloriesBurned, string videoLink) {
    this->name = name;
    this->focusArea = focusArea;
    this->caloriesBurned = caloriesBurned;
    this->videoLink = videoLink;
  }
  string getName() {
    return name;
  }
  int getFocusArea() {
    return focusArea;
  }
  int getCaloriesBurned() {
    return caloriesBurned;
  }
  string getVideoLink() {
    return videoLink;
  }
  void setName(string name) {
    this->name = name;
  }
  void setFocusArea(int focusArea) {
    this->focusArea = focusArea;
  }
  void setCaloriesBurned(int caloriesBurned) {
    this->caloriesBurned = caloriesBurned;
  }
  void setVideoLink(string videoLink) {
    this->videoLink = videoLink;
  }
};