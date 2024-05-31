#include<iostream>
#include"UserInfo.h"

UserInfo::UserInfo(std::string& name, int age, std::string& gender, double weight, double height, double bmr, int exerciseLevel)
    : name(name), age(age), gender(gender), weigt(weight), height(height), bmr(bmr), exerciseLevel(exerciseLevel) {}

UserInfo::inputInfo()
{
    std::cout<<"Name: ";
    std::cin>>name;
    std::cout<<"Age: ";
    std::cin>>age;
    std::cout<<"Gender (M/F): ";
    std::cin>>gender;
    std::cout<<"Weight: ";
    std::cin>>weight;
    std::cout<<"Height: ";
    std::cin>>height;
    std::cout<<"BMR (If you do not know enter 0): ";
    std::cin>>bmr;
    std::cout<<"ExerciseLevel (Beginner: 0, Intermediate: 1, Advanced: 2): ";
    std::cin>>exerciseLevel;
}

std::string& UserInfo::getName() const  { return name; }
int UserInfo::getAge() const    { return age; }
std::string& UserInfo::getGender() const { return gender; }
double UserInfo::getWeight() const  { return weight; }
double UserInfo::getHeight() const  { return height; }
double UserInfo::getBMR() const { return bmr; }
int UserInfo::getExerciseLevel() const  { return exerciseLevel; }