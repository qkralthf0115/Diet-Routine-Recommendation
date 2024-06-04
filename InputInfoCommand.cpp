#include"InputInfoCommand.h"

InputInfoCommand::InputInfoCommand(std::shared_ptr<UserInfo> userInfo) : userInfo(userInfo) {}

void InputInfoCommand::execute() {
    userInfo->inputInfo();
}

std::string InputInfoCommand::getName() const {
    return "Input User Informaiton";
}