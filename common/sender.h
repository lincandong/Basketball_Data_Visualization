#ifndef SENDER_H
#define SENDER_H
#include "common.h"
#include "receiver.h"
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
