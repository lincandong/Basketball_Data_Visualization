#ifndef COMMAND_H
#define COMMAND_H
<<<<<<< HEAD
<<<<<<< HEAD

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
=======
=======
>>>>>>> origin/master
#include "..\..\common\common.h"

class command
{
public:
    virtual void setParameter(const any& para) = 0;
    virtual void action() = 0;
};
<<<<<<< HEAD
#endif // !COMMAND_H
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
#endif // !COMMAND_H
>>>>>>> origin/master
