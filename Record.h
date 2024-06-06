#pragma once

class Record
{
public:
    virtual void inputRecord()=0;
    virtual void updateWeeklyRecord()=0;
    virtual void printRecord() const=0;
};