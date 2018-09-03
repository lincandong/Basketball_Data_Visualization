#ifndef RECEIVER_H
#define RECEIVER_H

#include <string>

<<<<<<< HEAD
class commandReceiver
=======
class receiver {};

class commandReceiver : public receiver
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
{
public:
    virtual void exec(std::string str, bool bOK) = 0;
};

<<<<<<< HEAD
class propertyReceiver
=======
class propertyReceiver : public receiver
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
{
public:
    virtual void exec(std::string str) = 0;
};
#endif // !RECEIVER_H
