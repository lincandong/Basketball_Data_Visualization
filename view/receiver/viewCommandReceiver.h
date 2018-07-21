#ifndef VIEW_COMMAND_RECEIVER_H
#define VIEW_COMMAND_RECEIVER_H

#include "../../common/receiver.h"

#include <memory>
#include <string>

class view;
class ViewCommandReceiver : public commandReceiver
{
private:
    view *pView;

public:
    ViewCommandReceiver();
    ViewCommandReceiver(view *ptr);
    void exec(std::string str, bool bOK);
};

#endif
