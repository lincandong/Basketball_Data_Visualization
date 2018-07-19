#ifndef VIEW_PROPERTY_RECEIVER_H
#define VIEW_PROPERTY_RECEIVER_H

#include "../../common/receiver.h"
#include "../view.h"

#include <memory>
#include <string>

class ViewPropertyReceiver : public propertyReceiver
{
private:
    std::shared_ptr<view> pView;

public:
    ViewPropertyReceiver(shared_ptr<view> ptr = nullptr);
    void exec(std::string str);
};

#endif