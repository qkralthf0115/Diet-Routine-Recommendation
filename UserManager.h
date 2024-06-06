#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "User.h"

class UserManager {
private:
  std::vector<std::shared_ptr<User>> users;

public:
  void signup();
  std::shared_ptr<User> login();
  void displayMenu();
};