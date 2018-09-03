#include "viewPropertyReceiver.h"
<<<<<<< HEAD
#include "../view.h"
=======
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

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
