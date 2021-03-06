#ifndef VIEW_PROPERTY_RECEIVER_H
#define VIEW_PROPERTY_RECEIVER_H

#include "../../common/receiver.h"

#include <memory>
#include <string>

class view;
class ViewPropertyReceiver : public propertyReceiver
{
private:
    view *pView;

public:
    ViewPropertyReceiver();
    ViewPropertyReceiver(view *ptr);
    void exec(std::string str);
};

#endif
