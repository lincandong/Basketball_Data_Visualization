#include "sender.h"

sender::sender(){};
void sender::add(const shared_ptr<receiver>& p)
{
    rec = p;
}
void sender::clear()
{
    rec = nullptr;
}
void sender::notify(string str)
{
    rec->exec(str);
}