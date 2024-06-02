#pragma once
#include<memory>
#include"Command.h"
#include"UserInfo.h"

class InputInfoCommand : public Command
{
private:
    std::shared_ptr<UserInfo> userInfo;
    std::string name = "Input User Info";
public:
    void execute();
};