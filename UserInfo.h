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
    double bmr;
    int exerciseLevel;
public:
    UseInfo(std::string& name, int age, std::string& gender, double weight, double height, double bmr, int exerciseLevel);
    void inputInfo();

    std::string& getName() const;
    int getAge() const;
    std::string& getGender() const;
    double getWeight() const;
    double getHeight() const;
    double getBMR() const;
    int getExerciseLevel() const;
    
};