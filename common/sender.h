#ifndef SENDER_H
#define SENDER_H
#include "common.h"
#include "receiver.h"
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