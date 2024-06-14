#include"MealRecord.h"
#include<iostream>
#include<algorithm>

MealRecord::MealRecord(std::shared_ptr<UserInfo> userInfo)
    : userInfo(userInfo), currentWeek(0) {
}

void MealRecord::inputRecord() {
    bool run = true;
    while (run) {
        std::cout << "Enter the number of the days you kept the meal plan this week " << "\033[0;35m" << "(-1 to go back)" << "\033[0;37m" << ": ";
        std::cin >> complete;
        if (complete == -1) {
            run = false;
        }
        else {
            updateWeeklyRecord();
        }
    }
}
void MealRecord::updateWeeklyRecord() {
    int totalWeeks = userInfo->getWeek();
    weeklyMealOX.resize(totalWeeks, false);

    if (currentWeek <= totalWeeks) {
        weeklyMealOX[currentWeek] = (complete == 7);
        ++currentWeek;
    }

}

void MealRecord::printRecord() const {
    double tot = weeklyMealOX.size();
    double success = std::count(weeklyMealOX.begin(), weeklyMealOX.end(), true);
    double rate = (success / tot) * 100;

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
