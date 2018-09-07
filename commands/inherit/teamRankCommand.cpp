#include "teamRankCommand.h"
#include "../../viewmodel/viewmodel.h"

teamRankCommand::teamRankCommand()
{

}

void teamRankCommand::setVm(viewModel* ptr)
{
    vm = ptr;
}

void teamRankCommand::action()
{
    vm->RequestTeamRank(static_pointer_cast<rankParameter>(parameter));
    vm->UpdateTeamRank();
    vm->scc.notify("team rank has been updated", true);
}
