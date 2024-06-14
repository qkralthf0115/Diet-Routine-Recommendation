#include"MealRecord.h"
#include<iostream>
#include<algorithm>

MealRecord::MealRecord(std::shared_ptr<UserInfo> userInfo)
    : userInfo(userInfo), currentWeek(0) {
}

void MealRecord::inputRecord() {
    std::cout << "Enter the number of the days you kept the meal plan this week: ";
    std::cin >> complete;
    updateWeeklyRecord();
}
void MealRecord::updateWeeklyRecord() {
    int totalWeeks = userInfo->getWeek();
    if (currentWeek <= totalWeeks) {
        weeklyMealOX[currentWeek] = (complete == 7);
        currentWeek += 1;
    }
    else {
        std::cout << "All weeks have been recorded. Check the feedback" << std::endl;
    }
}

void MealRecord::printRecord() const {
    double tot = weeklyMealOX.size();
    double success = std::count(weeklyMealOX.begin(), weeklyMealOX.end(), true);
    double rate = (success / tot);

    for (int i = 0;weeklyMealOX.size();++i) {
        std::cout << "Week" << i + 1 << ": " << (weeklyMealOX[i] ? "Success" : "Failure") << std::endl;
    }
    if (success == tot) {
        std::cout << "Congratulations! You did a perfect job!" << std::endl;
    }
    else if (success >= 80) {
        std::cout << "Good job!" << std::endl;
    }
    else {
        std::cout << "You should eat less!" << std::endl;
    }
}