#include <iostream>
#include "Menu.h"

int main() {
  Menu menu;
  menu.setMenu();

  int choice;
  do {
    menu.displayMenu();
    std::cin >> choice;
    menu.selectCommand(choice);
  } while (choice != 0);
  std::cout << "Exit the program." << std::endl;
  return 0;
}