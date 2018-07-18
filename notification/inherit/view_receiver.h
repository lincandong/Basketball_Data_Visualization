#ifndef VIEW_RECEIVER_H
#define VIEW_RECEIVER_H
#include "..\base\receiver.h"
#include "..\..\view\view.h"

class view_receiver
{
private:
    view* v;
    shared_ptr<string> c;
    /* ... */
public:
    //used for initialzation in app
    void set_c_ptr(const shared_ptr<string>& ptr);
    /* ... */

    virtual void exec(string&& str);
};
#endif //  VIEW_RECEIVER_H