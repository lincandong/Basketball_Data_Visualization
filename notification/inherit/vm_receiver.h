#ifndef VM_RECEIVER_H
#define VM_RECEIVER_H
#include "..\base\receiver.h"
#include "..\..\viewmodel\viewmodel.h"
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