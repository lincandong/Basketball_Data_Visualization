#include "../view/view.h"
#include "../viewmodel/viewmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    view v;
    viewModel vm;

    //set property change sender
    vm.m.InitSender(vm.getModelReceiver());
    
    //set command complete sender
    vm.setScc(v.getCommandReceiver());
    vm.setSpc(v.getPropertyReceiver());
    
    //set property change receiver in view

    //binding data
    v.setPlayer(vm.getPlayer());
    v.setPlayerRank(vm.getPlayerRank());
    v.setTeam(vm.getTeam());
    v.setTeamRank(vm.getTeamRank());
    
    //binding commands
    v.setPlayerDataCommand(vm.getPlayerDataCmd());
    v.setPlayerRankCommand(vm.getPlayerRankCmd());
    v.setTeamDataCommand(vm.getTeamDataCmd());
    v.setTeamRankCommand(vm.getTeamRankCmd());

    v.show();

    return app.exec();
}
