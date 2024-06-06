#pragma once
#include<memory>
#include<vector>
#include"Record.h"
#include"UserInfo.h"

class MealRecord : public Record
{
private:
    std::shared_ptr<UserInfo> userInfo;
    std::vector<bool> weeklyMealOX;
    int complete;
    int currentWeek;
public:
    MealRecord();
    void inputRecord();
    void updateWeeklyRecord();
    void printRecord() const;
};