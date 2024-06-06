#include "User.h"

User::User(const std::string& id, const std::string& password) : id(id), password(password) {}

std::string User::getId() const {
  return id;
}

std::string User::getPassword() const {
  return password;
}