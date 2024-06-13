#include"InputInfoCommand.h"

InputInfoCommand::InputInfoCommand(std::shared_ptr<UserInfo> userInfo) : userInfo(userInfo) {}

void InputInfoCommand::execute() {
    std::cout << std::setfill('=') << std::setw(75) << "=" << std::endl;
    std::cout << "\033[0;33m" << "Input User Information" << "\033[0;37m" << std::endl;
    userInfo->inputInfo();
}

std::string InputInfoCommand::getName() const {
    return "Input User Informaiton";
}