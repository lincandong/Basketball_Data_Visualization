#ifndef VIEWMODEL_H
#define VIEWMODEL_H
<<<<<<< HEAD

#include "receiver/receiverFromModel.h"
#include "receiver/receiverFromView.h"
#include "../common/sender.h"
#include "../model/model.h"
#include "compare/compare.h"
#include "../commands/allcommand.h"
#include "../common/dataType.h"
=======
#include "receiver/vm_receiver.h"
#include "../common/sender.h"
#include "../model/model.h"
#include "../commands/allcommand.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

class viewModel
{
private:
<<<<<<< HEAD
    //binding variables
    shared_ptr<vector<shared_ptr<player_avg>>> PlayerRank;
    shared_ptr<vector<shared_ptr<player_avg>>> PlayerData;
    shared_ptr<vector<shared_ptr<team_avg>>> TeamData;
    shared_ptr<vector<shared_ptr<team_avg>>> TeamRank;
    //temp variables storing updated value
    shared_ptr<vector<shared_ptr<player_avg>>> tmpPlayer;
    shared_ptr<vector<shared_ptr<team_avg>>> tmpTeam;

    shared_ptr<receiverFromModel> receiveModel;
    // shared_ptr<receiverFromView> receiveView;

public:
    //bind data
    shared_ptr<vector<shared_ptr<player_avg>>> getPlayer();
    shared_ptr<vector<shared_ptr<player_avg>>> getPlayerRank();
    shared_ptr<vector<shared_ptr<team_avg>>> getTeam();
    shared_ptr<vector<shared_ptr<team_avg>>> getTeamRank();

    //set sender and receiver
    shared_ptr<receiverFromModel> getModelReceiver();
    // shared_ptr<receiverFromView> getViewReceiver();
    void setSpc(shared_ptr<propertyReceiver> ptr);
    void setScc(shared_ptr<commandReceiver> ptr);

    //algorithms for calculating temp data
    void RequestPlayerData(shared_ptr<dataParameter> ptr);
    void RequestPlayerRank(shared_ptr<rankParameter> ptr);
    void RequestTeamData(shared_ptr<dataParameter> ptr);
    void RequestTeamRank(shared_ptr<rankParameter> ptr);
    //update binding data
    void UpdatePlayerData();
    void UpdatePlayerRank();
    void UpdateTeamData();
    void UpdateTeamRank();

    //commands
    shared_ptr<playerDataCommand> PlayerDataCmd;
    shared_ptr<playerRankCommand> PlayerRankCmd;
    shared_ptr<teamDataCommand> TeamDataCmd;
    shared_ptr<teamRankCommand> TeamRankCmd;
    shared_ptr<command> getPlayerDataCmd();
    shared_ptr<command> getPlayerRankCmd();
    shared_ptr<command> getTeamDataCmd();
    shared_ptr<command> getTeamRankCmd();
    
    //basic members
    model m;
    senderPropertyChange spc;
    senderCommandComplete scc;
    viewModel();
};

#endif // !VIEWMODEL_H
=======
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
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
