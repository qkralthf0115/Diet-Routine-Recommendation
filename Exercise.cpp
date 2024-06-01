#include <string>

class Exercise {
public:
  std::string name;
  std::string focusArea;
  int burnedCalories;

  Exercise(const std::string& n, const std::string& f, int b) : name(n), focusArea(f), burnedCalories(b) {}
};