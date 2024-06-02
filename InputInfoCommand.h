#pragma once
#include<memory>
#include"Command.h"
#include"UserInfo.h"

class InputInfoCommand : public Command
{
private:
    std::shared_ptr<UserInfo> userInfo;
public:
    void execute() override;
};