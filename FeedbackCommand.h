#pragma once
#include<memory>
#include"Command.h"
#include "FeedbackComment.h"
#include"UserInfo.h"
#include"ExerciseRecord.h"
#include"MealRecord.h"

class FeedbackCommand : public Command
{
private:
    std::shared_ptr<UserInfo> userInfo;
    ExerciseRecord exerciseRecord;
    MealRecord mealRecord;
    FeedbackComment feedbackComment;
public:
    FeedbackCommand(std::shared_ptr<UserInfo> userInfo, const ExerciseCommand& exerciseCommand);
    void execute() override;
    std::string getName() const override;
};