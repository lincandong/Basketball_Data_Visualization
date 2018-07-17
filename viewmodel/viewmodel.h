#include "..\notification\inherit\vm_receiver.h"
#include "..\notification\base\sender.h"
#include "..\model\model.h"

class viewModel
{
public:
    shared_ptr<int> age;
    shared_ptr<string> name;
    /* ... */

    //command instantiation

    //basic members
    model m;
    vm_receiver m2vm;
    vm_receiver vm2v;
    senderPropertyChange spc;
    senderCommandComplete scc;

    viewModel();
};
