#include "viewCommandReceiver.h"

ViewCommandReceiver::ViewCommandReceiver(std::shared_ptr<view> ptr)
{
    pView = ptr;
}

void ViewCommandReceiver::exec(std::string str, bool bOK)
{
    QString message;

    if (bOK == false)
    {
        switch(str)
        {
            case "teamRankOptionChangedCommand":
            case "playerRankOptionChangedCommand":
            case "teamChangedCommand":
            case "playerChangedCommand":
            case "teamOptionChangedCommand":
            case "playerOptionChangedCommand":
                QMessageBox messageBox;
                messageBox.setWindowTitle(QString("error!"));
                messageBox.exec();
            break;
        }
    }
}