#include "viewmodel.h"

viewModel::viewModel()
{
    //command instance
    PlayerDataCmd = make_shared<playerDataCommand>();
    PlayerDataCmd->setVm(this);
    PlayerRankCmd = make_shared<playerRankCommand>();
    PlayerRankCmd->setVm(this);
    TeamDataCmd = make_shared<teamDataCommand>();
    TeamDataCmd->setVm(this);
    TeamRankCmd = make_shared<teamRankCommand>();
    TeamRankCmd->setVm(this);
    receiveModel = make_shared<receiverFromModel>();
    // receiveView = make_shared<receiverFromView>();

    // rank and data  instance
    PlayerRank = make_shared<vector<shared_ptr<player_avg>>>();
    PlayerData = make_shared<vector<shared_ptr<player_avg>>>();
    TeamRank = make_shared<vector<shared_ptr<team_avg>>>();
    TeamData = make_shared<vector<shared_ptr<team_avg>>>();

    // sender
    m.InitSender(receiveModel);
}
shared_ptr<receiverFromModel> viewModel::getModelReceiver()
{
    return receiveModel;
}
// shared_ptr<receiverFromView> viewModel::getViewReceiver()
// {
//     return receiveView;
// }
shared_ptr<vector<shared_ptr<player_avg>>> viewModel::getPlayer()
{
    return PlayerData;
}
shared_ptr<vector<shared_ptr<player_avg>>> viewModel::getPlayerRank()
{
    return PlayerRank;
}
shared_ptr<vector<shared_ptr<team_avg>>> viewModel::getTeam()
{
    return TeamData;
}
shared_ptr<vector<shared_ptr<team_avg>>> viewModel::getTeamRank()
{
    return TeamRank;
}
void viewModel::setSpc(shared_ptr<propertyReceiver> ptr)
{
    spc.add(ptr);
}
void viewModel::setScc(shared_ptr<commandReceiver> ptr)
{
    scc.add(ptr);
}
shared_ptr<command> viewModel::getPlayerDataCmd()
{
    return PlayerDataCmd;
}
shared_ptr<command> viewModel::getPlayerRankCmd()
{
    return PlayerRankCmd;
}
shared_ptr<command> viewModel::getTeamDataCmd()
{
    return TeamDataCmd;
}
shared_ptr<command> viewModel::getTeamRankCmd()
{
    return TeamRankCmd;
}
void viewModel::RequestPlayerData(shared_ptr<dataParameter> ptr)
{
    //if request a player's one year data
    if(ptr->begin == ptr->end)
    {
        tmpPlayer = make_shared<vector<shared_ptr<player_avg>>>();
        tmpPlayer->push_back(make_shared<player_avg>());
        m.player_data(ptr->name, ptr->begin, ptr->end, (*tmpPlayer)[0]);
    }
    //else if request a player's multi year average data
    else if(ptr->begin < ptr->end)
    {
        tmpPlayer = make_shared<vector<shared_ptr<player_avg>>>();
        m.player_series(ptr->name, ptr->begin, ptr->end, *tmpPlayer);
    }
}
void viewModel::UpdatePlayerData()
{
    if (tmpPlayer != nullptr)
    *PlayerData = *tmpPlayer;
}
void viewModel::RequestPlayerRank(shared_ptr<rankParameter> ptr)
{
    if(ptr->option == "g") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_g);
    if(ptr->option == "gs") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_gs);
    if(ptr->option == "mp") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_mp);
    if(ptr->option == "fgper") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_fgper);
    if(ptr->option == "fg") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_fg);
    if(ptr->option == "fga") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_fga);
    if(ptr->option == "threepper") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_threepper);
    if(ptr->option == "threep") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_threep);
    if(ptr->option == "threepa") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_threepa);
    if(ptr->option == "ftper") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_ftper);
    if(ptr->option == "ft") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_ft);
    if(ptr->option == "fta") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_fta);
    if(ptr->option == "ts") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_ts);
    if(ptr->option == "trb") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_trb);
    if(ptr->option == "orb") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_orb);
    if(ptr->option == "drb") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_drb);
    if(ptr->option == "ast") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_ast);
    if(ptr->option == "stl") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_stl);
    if(ptr->option == "blk") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_blk);
    if(ptr->option == "tov") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_tov);
    if(ptr->option == "pf") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_pf);
    if(ptr->option == "pts") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_pts);
    if(ptr->option == "w") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_w);
    if(ptr->option == "l") m.order(ptr->season, *PlayerRank, &PlayerCompare::cmp_l);
}
void viewModel::UpdatePlayerRank()
{
    //if (tmpPlayer != nullptr)
    //*PlayerRank = *tmpPlayer;
}
void viewModel::RequestTeamData(shared_ptr<dataParameter> ptr)
{
    //if request a team's one year data
    if(ptr->begin == ptr->end)
    {
        //tmpTeam = make_shared<vector<shared_ptr<team_avg>>>();
        //tmpTeam->push_back(make_shared<team_avg>());
        tmpTeam = m.team_data(ptr->name);
    }
}
void viewModel::UpdateTeamData()
{
    if (tmpTeam != nullptr)
    TeamData->push_back(tmpTeam);
}
void viewModel::RequestTeamRank(shared_ptr<rankParameter> ptr)
{
    //tmpTeam = make_shared<vector<shared_ptr<team_avg>>>();
    if(ptr->option == "g") m.order(*TeamRank, &TeamCompare::cmp_g);
    if(ptr->option == "wg") m.order(*TeamRank, &TeamCompare::cmp_wg);
    if(ptr->option == "lg") m.order(*TeamRank, &TeamCompare::cmp_lg);
    if(ptr->option == "fgper") m.order(*TeamRank, &TeamCompare::cmp_fgper);
    if(ptr->option == "fg") m.order(*TeamRank, &TeamCompare::cmp_fg);
    if(ptr->option == "fga") m.order(*TeamRank, &TeamCompare::cmp_fga);
    if(ptr->option == "threepper") m.order(*TeamRank, &TeamCompare::cmp_threepper);
    if(ptr->option == "threep") m.order(*TeamRank, &TeamCompare::cmp_threep);
    if(ptr->option == "threepa") m.order(*TeamRank, &TeamCompare::cmp_threepa);
    if(ptr->option == "ftper") m.order(*TeamRank, &TeamCompare::cmp_ftper);
    if(ptr->option == "ft") m.order(*TeamRank, &TeamCompare::cmp_ft);
    if(ptr->option == "fta") m.order(*TeamRank, &TeamCompare::cmp_fta);
    if(ptr->option == "ts") m.order(*TeamRank, &TeamCompare::cmp_ts);
    if(ptr->option == "trb") m.order(*TeamRank, &TeamCompare::cmp_trb);
    if(ptr->option == "orb") m.order(*TeamRank, &TeamCompare::cmp_orb);
    if(ptr->option == "drb") m.order(*TeamRank, &TeamCompare::cmp_drb);
    if(ptr->option == "ast") m.order(*TeamRank, &TeamCompare::cmp_ast);
    if(ptr->option == "stl") m.order(*TeamRank, &TeamCompare::cmp_stl);
    if(ptr->option == "blk") m.order(*TeamRank, &TeamCompare::cmp_blk);
    if(ptr->option == "tov") m.order(*TeamRank, &TeamCompare::cmp_tov);
    if(ptr->option == "pf") m.order(*TeamRank, &TeamCompare::cmp_pf);
    if(ptr->option == "pts") m.order(*TeamRank, &TeamCompare::cmp_pts);
}
void viewModel::UpdateTeamRank()
{
    //if (tmpTeam != nullptr)
    //*TeamRank = *tmpTeam;
}
