#pragma once
#include<memory>
#include"Command.h"
#include"UserInfo.h"

class InputInfoCommand : public Command
{
private:
    std::shared_ptr<UserInfo> userInfo;
public:
    InputInfoCommand(std::shared_ptr<UserInfo> userInfo);
    void execute();
    std::string getName() const;
};
