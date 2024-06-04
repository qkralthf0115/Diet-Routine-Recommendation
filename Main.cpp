#include <iostream>
#include "Menu.h"
#include "Command.h"
#include "ExerciseCommand.cpp"
#include "MealCommand.cpp"
#include "InputInfoCommand.cpp"
#include "UserInfo.cpp"
#include "FoodDatabase.cpp"
#include "DietPlan.cpp"
#include "WorkoutDatabase.cpp"
#include "WorkoutItem.cpp"
#include "BodyArea.h"
#include "Menu.cpp"
#include "FoodItem.cpp"
#include "ExercisePlan.cpp"
#include "MealPlan.cpp"
#include "WorkoutPlan.cpp"

int main() {
  Menu menu;
  int choice;
  do {
    menu.displayMenu();
    std::cin >> choice;
    menu.executeCommand(choice);
  } while (choice != -1);
  std::cout << "Exit the program." << std::endl;
  return 0;
}