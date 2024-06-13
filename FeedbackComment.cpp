#pragma once
#include"FeedbackComment.h"
#include<iostream>

FeedbackComment::FeedbackComment(std::shared_ptr<UserInfo> userInfo): userInfo(userInfo), mealRecord(userInfo), exerciseRecord(userInfo){}

void FeedbackComment::generateComment()
{
    std::cout<<"Exercise Record: "<<std::endl;
    if (exerciseRecord.isComplete())
    {
        exerciseRecord.printRecord();
    }
    else
    {
        std::cout<<"Please complete exercise record"<<std::endl;
    }

    std::cout<<"Meal Record: "<<std::endl;
    if (mealRecord.isComplete())
    {
        mealRecord.printRecord();
    }
    else
    {
        std::cout<<"Please complete meal record"<<std::endl;
    }

}