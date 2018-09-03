#ifndef VIEW_PROPERTY_RECEIVER_H
#define VIEW_PROPERTY_RECEIVER_H

#include "../../common/receiver.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
#include "../view.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
#include "../view.h"
>>>>>>> origin/master

#include <memory>
#include <string>

<<<<<<< HEAD
<<<<<<< HEAD
class view;
=======
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
>>>>>>> origin/master
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
