#include "UserManager.h"

void UserManager::signup() {
  std::string id, password;
  std::cout << "Signup" << std::endl;
  std::cout << "Enter ID: ";
  std::cin >> id;
  std::cout << "Enter Password: ";
  std::cin >> password;
  users.push_back(std::make_shared<User>(id, password));
  std::cout << "Signup successful! Returning to main page..." << std::endl;
}

std::shared_ptr<User> UserManager::login() {
  std::string id, password;
  std::cout << "Login Page" << std::endl;
  std::cout << "Enter ID: ";
  std::cin >> id;
  std::cout << "Enter Password: ";
  std::cin >> password;

  for (const auto& user : users) {
    if (user->getId() == id && user->getPassword() == password) {
      std::cout << "Login successful!" << std::endl;
      return user;
    }
  }

  std::cout << "Invalid ID or Password. Returning to main page..." << std::endl;
  return nullptr;
}

void UserManager::displayMenu() {
  std::cout << "Main Menu" << std::endl;
  std::cout << "1. Signup" << std::endl;
  std::cout << "2. Login" << std::endl;
  std::cout << "-1. Exit" << std::endl;
  std::cout << "Enter your choice: ";
}
