#include "viewCommandReceiver.h"
#include "../view.h"

ViewCommandReceiver::ViewCommandReceiver()
{

}

ViewCommandReceiver::ViewCommandReceiver(view *ptr)
{
    pView = ptr;
}

void ViewCommandReceiver::exec(std::string str, bool bOK)
{
    if (bOK == false)
    {
        QMessageBox messageBox;
        messageBox.setWindowTitle("Error");
        messageBox.show();
    }
}
