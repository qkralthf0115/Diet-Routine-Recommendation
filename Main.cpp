#include <iostream>
#include "Menu.h"
#include "Command.h"
#include "ExerciseCommand.h"
#include "MealCommand.h"
#include "InputInfoCommand.h"
#include "FeedbackCommand.h"
#include "UserInfo.h"
#include "FoodDatabase.h"
#include "DietPlan.h"
#include "WorkoutDatabase.h"
#include "WorkoutItem.h"
#include "BodyArea.h"
#include "FoodItem.h"
#include "ExercisePlan.h"
#include "MealPlan.h"
#include "WorkoutPlan.h"
#include "User.h"
#include "UserManager.h"
#include "MealRecord.h"
#include "ExerciseRecord.h"
#include "FeedbackComment.h"
#include "Record.h"

int main() {
  UserManager userManager;
  std::shared_ptr<User> loggedInUser = nullptr;
  int choice;

  while (true) {
    userManager.displayMenu();
    std::cin >> choice;

    if (choice == -1) {
      std::cout << "Exiting program. See you next time!" << std::endl;
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
            std::cout << "Logging out..." << std::endl;
            loggedInUser = nullptr;
            break;
          }
          menu.executeCommand(menuChoice);
        }
      }
      break;
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      break;
    }
  }
}