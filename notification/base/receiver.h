#ifndef RECEIVER_H
#define RECEIVER_H
#include "..\..\common\common.h"
class receiver
{
public:
    virtual void exec(string str) = 0;
};
#endif // !RECEIVER_H
