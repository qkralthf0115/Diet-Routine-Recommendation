#pragma once
#include<memory>
#include<vector>
#include"Record.h"
#include"UserInfo.h"
#include"ExerciseCommand.h"

class ExerciseRecord : public Record
{
private:
    int complete;
    int currentWeek;
    std::shared_ptr<UserInfo> userInfo;
    const ExerciseCommand& exerciseCommand;
    std::vector<bool> weeklyExerciseOX;
public:
    ExerciseRecord(std::shared_ptr<UserInfo> userInfo, const ExerciseCommand& exerciseCommand);
    void inputRecord() override;
    void updateWeeklyRecord() override;
    void printRecord() const override;
    bool isComplete() const;
    int getCurrentWeek() const;
};