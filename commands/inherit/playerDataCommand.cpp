#include "playerDataCommand.h"
#include "../../viewmodel/viewmodel.h"

playerDataCommand::playerDataCommand()
{

}

void playerDataCommand::setVm(viewModel* ptr)
{
    vm = ptr;
}

void playerDataCommand::action()
{
    vm->RequestPlayerData(static_pointer_cast<dataParameter, parameters>(para));
    vm->UpdatePlayerData();
    vm->scc.notify("player has been updated", true);
}
