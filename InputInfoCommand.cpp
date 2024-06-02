#include"InputInfoCommand.h"

void InputInfoCommand::execute() {
    userInfo->inputInfo();
}

std::string InputInfoCommand::getName() const {
    return "Input User Informaiton";
}