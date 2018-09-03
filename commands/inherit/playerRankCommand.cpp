#include "playerRankCommand.h"
#include "../../viewmodel/viewmodel.h"

playerRankCommand::playerRankCommand()
{

}

void playerRankCommand::setVm(viewModel* ptr)
{
    vm = ptr;
}

void playerRankCommand::action()
{
    vm->RequestPlayerRank(static_pointer_cast<rankParameter, parameters>(para));
    vm->UpdatePlayerRank();
    vm->scc.notify("player rank has been updated", true);
}
