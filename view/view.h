#ifndef VIEW_H
#define VIEW_H
#include "..\command\base\command.h"
#include "..\notification\inherit\view_receiver.h"
class view
{
private:
    //QPushButtion* q;
    /* ... */
    
    command* c1;
    /* ... */
public:
    void set_cmd1(command*& ptr);
    /* ... */

    view_receiver rec;
};
#endif // !VIEW_H