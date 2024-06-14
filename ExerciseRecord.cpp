#include"ExerciseRecord.h"
#include<iostream>
#include<algorithm>

ExerciseRecord::ExerciseRecord(std::shared_ptr<UserInfo> userInfo)
    : userInfo(userInfo), exerciseCommand(exerciseCommand), complete(0), currentWeek(0) {
}

void ExerciseRecord::inputRecord() {
    std::cout << "Enter the number of the days you exercised this week: ";
    std::cin >> complete;
    updateWeeklyRecord();
}

void ExerciseRecord::updateWeeklyRecord() {
    int totalWeeks = userInfo->getWeek();
    int targetDays = exerciseCommand.getDays();

    if (currentWeek < totalWeeks) {
        weeklyExerciseOX[currentWeek] = (complete >= targetDays);
        currentWeek += 1;
    }
    else {
        std::cout << "All weeks have been recorded. Check the feedback" << std::endl;
    }
}

void ExerciseRecord::printRecord() const {
    double tot = weeklyExerciseOX.size();
    double success = std::count(weeklyExerciseOX.begin(), weeklyExerciseOX.end(), true);
    double rate = (success / tot) * 100;
    std::cout << currentWeek << std::endl;
    for (int i = 0; i < weeklyExerciseOX.size();++i) {
        std::cout << "Week" << i + 1 << ": " << (weeklyExerciseOX[i] ? "Success" : "Failure") << std::endl;
    }

    if (success == tot) {
        std::cout << "Congratulations! You've done all the workout!" << std::endl;
    }
    else if (success >= 80) {
        std::cout << "Good job!" << std::endl;
    }
    else {
        std::cout << "You should exercise more!" << std::endl;
    }

}