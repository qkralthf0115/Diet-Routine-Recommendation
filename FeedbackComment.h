#pragma once
#include"Record.h"
#include"ExerciseRecord.h"
#include"MealRecord.h"

class FeedbackComment
{
private:
    MealRecord mealRecord;
    ExerciseRecord exerciseRecord;
    std::shared_ptr<UserInfo> userInfo;
public:
    FeedbackComment(std::shared_ptr<UserInfo> userInfo);
    void generateComment();
};