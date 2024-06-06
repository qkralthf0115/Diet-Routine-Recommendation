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
#include "User.cpp"
#include "UserManager.cpp"

int main() {
  UserManager userManager;
  std::shared_ptr<User> loggedInUser = nullptr;
  int choice;

  while (true) {
    userManager.displayMenu();
    std::cin >> choice;

    if (choice == -1) {
      std::cout << "Exiting program. Goodbye!\n";
      return 0;
    }

    switch (choice) {
    case 1:
      userManager.signup();
      break;
    case 2:
      loggedInUser = userManager.login();
      if (loggedInUser) {
        Menu menu;
        int menuChoice;
        while (true) {
          menu.displayMenu();
          std::cin >> menuChoice;
          if (menuChoice == -1) {
            std::cout << "Logging out...\n";
            loggedInUser = nullptr;
            break;
          }
          menu.executeCommand(menuChoice);
        }
      }
      break;
    default:
      std::cout << "Invalid choice. Please try again.\n";
      break;
    }
  }
}