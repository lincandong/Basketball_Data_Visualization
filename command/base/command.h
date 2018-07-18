#ifndef COMMAND_H
#define COMMAND_H
#include "..\..\common\common.h"

class command
{
public:
    virtual void setParameter(const any& para) = 0;
    virtual void action() = 0;
};
#endif // !COMMAND_H