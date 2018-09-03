#ifndef SENDER_H
#define SENDER_H
#include "common.h"
#include "receiver.h"
<<<<<<< HEAD
class senderPropertyChange
{
private:
    shared_ptr<propertyReceiver> rec;
public:
    senderPropertyChange() = default;
    void add(shared_ptr<propertyReceiver> p);
    void clear();
    void notify(string str);
};
class senderCommandComplete
{
private:
    shared_ptr<commandReceiver> rec;
public:
    senderCommandComplete() = default;
    void add(shared_ptr<commandReceiver> p);
    void clear();
    void notify(string str, bool bOK);
};

#endif // !SENDER_H
=======
class sender
{
private:
    shared_ptr<receiver> rec;
public:
    sender() = default;
    void add(const shared_ptr<receiver>& p);
    void clear();
    void notify(string str);
};
class senderPropertyChange : public sender
{
public:
    senderPropertyChange() = default;
};
class senderCommandComplete : public sender
{
public:
    senderCommandComplete() = default;
};

#endif // !SENDER_H
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
