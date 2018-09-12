#include "viewPropertyReceiver.h"
#include "../view.h"

ViewPropertyReceiver::ViewPropertyReceiver()
{

}

ViewPropertyReceiver::ViewPropertyReceiver(view *ptr)
{
    pView = ptr;
}

void ViewPropertyReceiver::exec(std::string str)
{
    // do nothing
}
