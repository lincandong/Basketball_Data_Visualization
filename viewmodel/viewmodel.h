#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "receiver/receiverFromModel.h"
#include "receiver/receiverFromView.h"
#include "../common/sender.h"
#include "../model/model.h"
#include "compare/compare.h"
#include "../commands/allcommand.h"
#include "../common/dataType.h"

class viewModel
{
private:
    //bound variables
    shared_ptr<vector<shared_ptr<player_avg>>> PlayerRank;
    shared_ptr<vector<shared_ptr<player_avg>>> PlayerData;
    shared_ptr<vector<shared_ptr<team_avg>>> TeamData;
    shared_ptr<vector<shared_ptr<team_avg>>> TeamRank;

    //temp variables storing updated value
    shared_ptr<vector<shared_ptr<player_avg>>> tmpPlayer;
    shared_ptr<team_avg> tmpTeam;

    //receiver for receiving notice from model
    shared_ptr<receiverFromModel> receiveModel;

public:
    //to bind variables
    shared_ptr<vector<shared_ptr<player_avg>>> getPlayer();
    shared_ptr<vector<shared_ptr<player_avg>>> getPlayerRank();
    shared_ptr<vector<shared_ptr<team_avg>>> getTeam();
    shared_ptr<vector<shared_ptr<team_avg>>> getTeamRank();

    //set sender and receiver
    shared_ptr<receiverFromModel> getModelReceiver();
    void setSpc(shared_ptr<propertyReceiver> ptr);
    void setScc(shared_ptr<commandReceiver> ptr);

    //algorithms for calculating temp data
    void RequestPlayerData(shared_ptr<dataParameter> ptr);
    void RequestPlayerRank(shared_ptr<rankParameter> ptr);
    void RequestTeamData(shared_ptr<dataParameter> ptr);
    void RequestTeamRank(shared_ptr<rankParameter> ptr);
    //update bound variables
    void UpdatePlayerData();
    void UpdatePlayerRank();
    void UpdateTeamData();
    void UpdateTeamRank();

    //commands
    //commands for requesting data by view
    shared_ptr<playerDataCommand> PlayerDataCmd;
    shared_ptr<playerRankCommand> PlayerRankCmd;
    shared_ptr<teamDataCommand> TeamDataCmd;
    shared_ptr<teamRankCommand> TeamRankCmd;
    //expose commands to view
    shared_ptr<command> getPlayerDataCmd();
    shared_ptr<command> getPlayerRankCmd();
    shared_ptr<command> getTeamDataCmd();
    shared_ptr<command> getTeamRankCmd();
    
    //basic members
    //embeded model
    model m;
    //sender for sending notice about property changes to view
    senderPropertyChange spc;
    //sender for sending notice about command compeletion to view
    senderCommandComplete scc;
    viewModel();
};

#endif // !VIEWMODEL_H
