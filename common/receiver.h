#ifndef RECEIVER_H
#define RECEIVER_H

#include <string>

class commandReceiver
{
public:
    virtual void exec(std::string str, bool bOK) = 0;
};

class propertyReceiver
{
public:
    virtual void exec(std::string str) = 0;
};
#endif // !RECEIVER_H
