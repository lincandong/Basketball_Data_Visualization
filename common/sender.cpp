#include "sender.h"

void senderCommandComplete::add(shared_ptr<commandReceiver> p)
{
    rec = p;
}
void senderCommandComplete::clear()
{
    rec = nullptr;
}
void senderCommandComplete::notify(string str, bool bOK)
{
    rec->exec(str, bOK);
}

void senderPropertyChange::add(shared_ptr<propertyReceiver> p)
{
    rec = p;
}
void senderPropertyChange::clear()
{
    rec = nullptr;
}
void senderPropertyChange::notify(string str)
{
    rec->exec(str);
}
