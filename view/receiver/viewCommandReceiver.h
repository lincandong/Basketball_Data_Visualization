#ifndef VIEW_COMMAND_RECEIVER_H
#define VIEW_COMMAND_RECEIVER_H

#include "../../common/receiver.h"
#include "../view.h"

#include <memory>
#include <string>

class ViewCommandReceiver : public commandReceiver
{
private:
    std::shared_ptr<view> pView;

public:
    ViewCommandReceiver(std::shared_ptr<view> ptr = nullptr);
    void exec(std::string str, bool bOK);
};

#endif