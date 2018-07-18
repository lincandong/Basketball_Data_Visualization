#ifndef VIEWMODEL_H
#define VIEWMODEL_H
#include "..\notification\inherit\vm_receiver.h"
#include "..\notification\base\sender.h"
#include "..\model\model.h"
#include "..\command\allcommand.h"

class viewModel
{
private:
    shared_ptr<int> c;
    shared_ptr<int> age;
    shared_ptr<string> name;
    /* ... */
public:
    //pairs of set() and get()
    void set_c(int&& value);
    const int & get_c();

    //command instantiation
    openfile* c1;

    //get() for command
    const command* get_cmd1();

    //basic members
    model m;
    vm_receiver m2vm;
    vm_receiver vm2v;
    senderPropertyChange spc;
    senderCommandComplete scc;

    viewModel();
};

#endif // !VIEWMODEL_H