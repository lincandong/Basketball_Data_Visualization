#include "sender.h"

<<<<<<< HEAD
<<<<<<< HEAD
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
=======
=======
>>>>>>> origin/master
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
<<<<<<< HEAD
}
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
}
>>>>>>> origin/master
