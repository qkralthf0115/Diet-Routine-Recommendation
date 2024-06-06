#pragma once
#include <string>

class User {
private:
  std::string id;
  std::string password;

public:
  User(const std::string& id, const std::string& password);
  std::string getId() const;
  std::string getPassword() const;
};