#include "vm_receiver.h"
vm_receiver::vm_receiver(viewModel* ptr)
{
    vm = ptr;
}
void vm_receiver::exec(string str)
{
    if(str == "a has been set")
    {
        vm->set_c(vm->m.a_plus_b());
    }
    /* ....... */

};