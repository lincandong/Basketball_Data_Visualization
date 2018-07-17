#include "view_receiver.h"
void view_receiver::set_c_ptr(const shared_ptr<string>& ptr)
{
    c = ptr;
}
void view_receiver::exec(string&& str)
{
    if(str == "c has been set")
    {
        
    }
}