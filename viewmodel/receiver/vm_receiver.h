#ifndef VM_RECEIVER_H
#define VM_RECEIVER_H
#include "../../common/receiver.h"
#include "../viewmodel.h"
class vm_receiver : public receiver
{
private:
    viewModel* vm;
public:
    vm_receiver() = default;
    vm_receiver(viewModel* ptr);
    virtual void exec(string str);
};
#endif