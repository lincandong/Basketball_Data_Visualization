#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "pageStart.h"
#include "pageRank.h"
#include "pageData.h"
#include "pageTeam.h"
#include "pagePlayer.h"

#include "receiver/viewCommandReceiver.h"

namespace Ui {
class view;
}

class view : public QMainWindow
{
    Q_OBJECT

public:
    //shared_ptr<ViewCommandReceiver> viewCommandReceiver;

    explicit view(QWidget *parent = 0);
    ~view();

    // switch pages
    void switchPageStart();
    void switchPageRank();
    void switchPageData();
    void switchPageTeam();
    void switchPagePlayer();
/*
    void setPlayerDataCommand(shared_ptr<command> ptr);
    void setPlayerRankCommand(shared_ptr<command> ptr);
    void setTeamDataCommand(shared_ptr<command> ptr);
    void setTeamRankCommand(shared_ptr<command> ptr);

    void setPlayerRank(shared_ptr<vector<player_avg *>> playerRank);
    void setTeamRank(shared_ptr<vector<team_avg *>> teamRank);
    void setPlayer(vector<float *> player);
    void setTeam(vector<float *> team);
*/
private:
    Ui::view *ui;

    pageStart *page_start;
    pageRank *page_rank;
    pageData *page_data;
    pageTeam *page_team;
    pagePlayer *page_player;
/*
    // 绑定的命令
    shared_ptr<command> playerDataCommand;
    shared_ptr<command> playerRankCommand;
    shared_ptr<command> teamDataCommand;
    shared_ptr<command> teamRankCommand;*/
};

#endif // VIEW_H
