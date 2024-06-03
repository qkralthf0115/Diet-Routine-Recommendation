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
  menu.setMenu();

  int temp;
  int choice;
  do {
    std::cout << "\033[1;32m" << "Choose a command (1-3) or -1 to exit:" << "\033[1;32m" << std::endl;
    menu.displayMenu();
    std::cin >> temp;
    choice = temp - 1;
    menu.selectCommand(choice);
  } while (choice != -1);
  std::cout << "Exit the program." << std::endl;
  return 0;
}