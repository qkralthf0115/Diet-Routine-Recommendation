#pragma once
#include"FeedbackComment.h"
#include<iostream>

FeedbackComment::FeedbackComment() : exerciseRecord(exerciseRecord), mealRecord(mealRecord) {}

void FeedbackComment::generateComment() {
    std::cout << "Exercise Comment" << std::endl;
    exerciseRecord.printRecord();
    std::cout << "Meal Comment" << std::endl;
    mealRecord.printRecord();
}