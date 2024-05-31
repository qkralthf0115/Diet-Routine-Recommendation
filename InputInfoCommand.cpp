#include"InputInfoCommand.h"

InputInfoCommand::InputInfoCommand(std::shared_ptr<UserInfo> userInfo): userInfo(userInfo) {}

InputInfoCommand::execute()
{
    userInfo->inputInfo();
}