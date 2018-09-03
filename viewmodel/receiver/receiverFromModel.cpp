#include "receiverFromModel.h"
#include "../viewmodel.h"
receiverFromModel::receiverFromModel(viewModel* ptr)
{
    vm = ptr;
}
//simpliy transform notification to view
void receiverFromModel::exec(string str)
{
    if(str == "player has been set")
    {
        vm->spc.notify("player has been set");
    }
    else if(str == "team has been set")
    {
        vm->spc.notify("team has been set");
    }
    else if(str == "player rank has been set")
    {
        vm->spc.notify("player rank has been set");
    }
    else if(str == "team rank has been set")
    {
        vm->spc.notify("team rank has been set");
    }

};
