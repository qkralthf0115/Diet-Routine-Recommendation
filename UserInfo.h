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
    int exerciseLevel;
    double wantedWeight;
public:
    UseInfo(std::string& name, int age, std::string& gender, double weight, double height, int exerciseLevel, double wantedWeight);
    void inputInfo();

    std::string& getName() const;
    int getAge() const;
    std::string& getGender() const;
    double getWeight() const;
    double getHeight() const;
    int getExerciseLevel() const;
    double getWantedWeight() const;

    void calculateFoodCalories();
    void calculateExerciseCalories();

    
};