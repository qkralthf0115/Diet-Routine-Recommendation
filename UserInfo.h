#pragma once
#include<string>

class UserInfo
{
private:
    std::string name;
    int age;
    std::string gender;
    double weight;
    double height;
    double wantedWeight;
    int week;
public:
    void inputInfo();

    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    double getWeight() const;
    double getHeight() const;
    double getWantedWeight() const;
    int getWeek() const;

    double calculateFoodCalories();
    double calculateExerciseCalories();

};