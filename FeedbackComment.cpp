#pragma once
#include"FeedbackComment.h"
#include<iostream>

FeedbackComment::FeedbackComment(): exerciseRecord(exerciseRecord){}

void FeedbackComment::generateComment()
{
    exerciseRecord.printRecord();
    mealRecord.printRecord();
}