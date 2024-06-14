#pragma once
#include"Record.h"
#include"ExerciseRecord.h"
#include"MealRecord.h"

class FeedbackComment
{
private:
    MealRecord mealRecord;
    ExerciseRecord exerciseRecord;
public:
    FeedbackComment();
    void generateComment();
};