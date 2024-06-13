#include"ExerciseRecord.h"
#include<iostream>
#include<algorithm>

ExerciseRecord::ExerciseRecord(std::shared_ptr<UserInfo> userInfo, const ExerciseCommand& exerciseCommand)
    : userInfo(userInfo), exerciseCommand(exerciseCommand), complete(0), currentWeek(0) {
}

void ExerciseRecord::inputRecord() {
    bool run = true;
    while (run) {
        std::cout << "Enter the number of the days you exercised this week " << "\033[0;35m" << "(-1 to go back)" << "\033[0;37m" << ": ";
        std::cin >> complete;
        if (complete == -1) {
            run = false;
        }
        else {
            updateWeeklyRecord();
            if (isComplete()) {
                std::cout << "All weeks have been recorded. Check the feedback" << std::endl;
                run = false;
            }
        }
    }
}

void ExerciseRecord::updateWeeklyRecord() {
    int totalWeeks = userInfo->getWeek();
    weeklyExerciseOX.resize(totalWeeks, false);
    int targetDays = exerciseCommand.getDays();

    if (currentWeek < totalWeeks) {
        weeklyExerciseOX[currentWeek] = (complete >= targetDays);
        ++currentWeek;
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

bool ExerciseRecord::isComplete() const {
    return currentWeek >= userInfo->getWeek();
}