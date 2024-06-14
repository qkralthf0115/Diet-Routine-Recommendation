#include"FeedbackCommand.h"
#include <iostream>

FeedbackCommand::FeedbackCommand(std::shared_ptr<UserInfo> userInfo)
    : userInfo(userInfo), exerciseRecord(userInfo), mealRecord(userInfo), feedbackComment() {
}

void FeedbackCommand::execute() {
    std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
    std::cout << "\033[0;33m" << "Feedback" << "\033[0;37m" << std::endl;
    std::cout << "1. Input Exercise   2. Input Meal   3. Check Feedback" << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        exerciseRecord.inputRecord();
        break;
    case 2:
        mealRecord.inputRecord();
        break;
    case 3:
        feedbackComment.generateComment();
        break;
    default:
        std::cout << "Invalid choice" << std::endl;
        break;
    }
}

std::string FeedbackCommand::getName() const {
    return "Feedback";
}