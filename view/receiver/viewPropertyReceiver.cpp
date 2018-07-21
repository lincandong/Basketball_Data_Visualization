#include "viewPropertyReceiver.h"

ViewPropertyReceiver::ViewPropertyReceiver()
{

}

ViewPropertyReceiver::ViewPropertyReceiver(view *ptr)
{
    pView = ptr;
}

void ViewPropertyReceiver::exec(std::string str)
{
    if (str == "season")
    {
        //
    }
}
