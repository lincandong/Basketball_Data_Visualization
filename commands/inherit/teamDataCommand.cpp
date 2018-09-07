#include "teamDataCommand.h"
#include "../../viewmodel/viewmodel.h"

teamDataCommand::teamDataCommand()
{

}

void teamDataCommand::setVm(viewModel* ptr)
{
    vm = ptr;
}

void teamDataCommand::action()
{
    vm->RequestTeamData(static_pointer_cast<dataParameter>(parameter));
    vm->UpdateTeamData();
    vm->scc.notify("team has been updated", true);
}
