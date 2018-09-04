#ifndef COMMAND_H
#define COMMAND_H

#include "parameters.h"
#include <memory>

class command
{
protected:
    std::shared_ptr<parameters> parameter;

public:
    command();
    void setParameter(std::shared_ptr<parameters> para);
    virtual void action() = 0;
};
#endif // !COMMAND_H
