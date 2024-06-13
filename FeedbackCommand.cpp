#include"FeedbackCommand.h"
#include <iostream>

FeedbackCommand::FeedbackCommand(std::shared_ptr<UserInfo> userInfo, const ExerciseCommand& exerciseCommand) : userInfo(userInfo), exerciseRecord(userInfo, exerciseCommand), mealRecord(userInfo), feedbackComment(userInfo) {}

void FeedbackCommand::execute() {
    std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
    std::cout << "\033[0;33m" << "Feedback" << "\033[0;37m" << std::endl;
    if (!userInfo->getName().empty()) {
        bool run = true;
        while (run) {
            std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
            std::cout << "1. Input Exercise   2. Input Meal   3. Check Feedback   4. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            int choice;
            std::cin >> choice;
            std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;

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
            case 4:
                run = false;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }
    else {
        std::cout << "Please input user information first." << std::endl;
    }
}

std::string FeedbackCommand::getName() const {
    return "Feedback";
}