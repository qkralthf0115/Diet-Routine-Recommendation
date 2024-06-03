#include"InputInfoCommand.h"

InputInfoCommand::InputInfoCommand() : userInfo(std::make_shared<UserInfo>()) {}

void InputInfoCommand::execute() {
    userInfo->inputInfo();
}

std::string InputInfoCommand::getName() const {
    return "Input User Informaiton";
}