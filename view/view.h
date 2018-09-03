#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <memory>
#include <vector>

#include "pageStart.h"
#include "pageRank.h"
#include "pageData.h"
#include "pageTeam.h"
#include "pagePlayer.h"

#include "receiver/viewCommandReceiver.h"
<<<<<<< HEAD
#include "receiver/viewPropertyReceiver.h"
#include "../common/dataType.h"
=======
#include "../common/data.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

using namespace std;

namespace Ui {
class view;
}

class view : public QMainWindow
{
    Q_OBJECT

public:
<<<<<<< HEAD
    shared_ptr<ViewCommandReceiver> getCommandReceiver();
    shared_ptr<ViewPropertyReceiver> getPropertyReceiver();
=======
    shared_ptr<ViewCommandReceiver> receiver;
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

    explicit view(QWidget *parent = 0);
    ~view();

    // switch pages
    void switchPageStart();
    void switchPageRank();
    void switchPageData();
    void switchPageTeam();
    void switchPagePlayer();

    // set
    void setPlayerDataCommand(shared_ptr<command> ptr);
    void setPlayerRankCommand(shared_ptr<command> ptr);
    void setTeamDataCommand(shared_ptr<command> ptr);
    void setTeamRankCommand(shared_ptr<command> ptr);

<<<<<<< HEAD
    void setPlayerRank(shared_ptr<vector<shared_ptr<player_avg>>> playerRank);
    void setTeamRank(shared_ptr<vector<shared_ptr<team_avg>>> teamRank);
    void setPlayer(shared_ptr<vector<shared_ptr<player_avg>>> player);
    void setTeam(shared_ptr<vector<shared_ptr<team_avg>>> team);
private:
    shared_ptr<ViewCommandReceiver> commandReceiver;
    shared_ptr<ViewPropertyReceiver> propertyReceiver;
=======
    void setPlayerRank(shared_ptr<vector<player_avg *>> playerRank);
    void setTeamRank(shared_ptr<vector<team_avg *>> teamRank);
    void setPlayer(shared_ptr<vector<player_avg *>> player);
    void setTeam(shared_ptr<vector<team_avg *>> team);
private:
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
    Ui::view *ui;

    pageStart *page_start;
    pageRank *page_rank;
    pageData *page_data;
    pageTeam *page_team;
    pagePlayer *page_player;

    // 命令
    shared_ptr<command> playerDataCommand;
    shared_ptr<command> playerRankCommand;
    shared_ptr<command> teamDataCommand;
    shared_ptr<command> teamRankCommand;
};

#endif // VIEW_H
