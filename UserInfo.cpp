#include<iostream>
#include"UserInfo.h"

void UserInfo::inputInfo() {
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Gender (M/F): ";
    std::cin >> gender;
    std::cout << "Weight: ";
    std::cin >> weight;
    std::cout << "Height: ";
    std::cin >> height;
    std::cout << "Wanted weight: ";
    std::cin >> wantedWeight;
    std::cout << "How much weeks are you doing this: ";
    std::cin >> week;
}

std::string UserInfo::getName() const { return name; }
int UserInfo::getAge() const { return age; }
std::string UserInfo::getGender() const { return gender; }
double UserInfo::getWeight() const { return weight; }
double UserInfo::getHeight() const { return height; }
double UserInfo::getWantedWeight() const { return wantedWeight; }
int UserInfo::getWeek() const { return week; }

double UserInfo::calculateFoodCalories() {
    double foodcalories;
    height = getHeight();
    weight = getWeight();
    age = getAge();
    gender = getGender();

    if (gender == "F") {
        foodcalories = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);
    }
    else {
        foodcalories = 66.5 + (13.7 * weight) + (5 * height) - (6.8 * age);
    }
    return foodcalories;

}

double UserInfo::calculateExerciseCalories() {
    if (week <= 0) {
        std::cerr << "Invalid number of weeks. Please enter a positive number." << std::endl;
        return 0;
    }
    double exerciseCalories = ((weight - wantedWeight) * 7000) / week;
    if (exerciseCalories < 0) {
        std::cerr << "Wanted weight should be less than current weight." << std::endl;
        return 0;
    }
    return exerciseCalories;
}