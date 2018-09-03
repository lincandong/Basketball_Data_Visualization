#ifndef PAGERANK_H
#define PAGERANK_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <memory>
#include <string>
using namespace std;

<<<<<<< HEAD
<<<<<<< HEAD
#include "../commands/base/command.h"
#include "../common/dataType.h"
=======
#include "../commands/command.h"
#include "../common/data.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
#include "../commands/command.h"
#include "../common/data.h"
>>>>>>> origin/master

namespace Ui {
class pageRank;
}

class pageRank : public QWidget
{
    Q_OBJECT

public:
    explicit pageRank(QWidget *parent = 0);
    ~pageRank();

    void setPlayerRankCommand(shared_ptr<command> ptr);
    void setTeamRankCommand(shared_ptr<command> ptr);

<<<<<<< HEAD
<<<<<<< HEAD
    void setPlayerRank(shared_ptr<vector<shared_ptr<player_avg>>> playerRank);
    void setTeamRank(shared_ptr<vector<shared_ptr<team_avg>>> teamRank);
=======
    void setPlayerRank(shared_ptr<vector<player_avg *>> playerRank);
    void setTeamRank(shared_ptr<vector<team_avg *>> teamRank);
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
    void setPlayerRank(shared_ptr<vector<player_avg *>> playerRank);
    void setTeamRank(shared_ptr<vector<team_avg *>> teamRank);
>>>>>>> origin/master

    void init();
    void update();

private slots:
    void on_boxSeason_valueChanged(int arg1);

    void on_buttonTeam_clicked();

    void on_buttonPlayer_clicked();

private:
    Ui::pageRank *ui;

    QChartView *view1, *view2, *view3, *view4;

    // 参数
    bool isTeam;
    shared_ptr<rankParameter> para;

    // 数据
<<<<<<< HEAD
<<<<<<< HEAD
    shared_ptr<vector<shared_ptr<player_avg>>> playerRank;
    shared_ptr<vector<shared_ptr<team_avg>>> teamRank;
=======
    shared_ptr<vector<player_avg *>> playerRank;
    shared_ptr<vector<team_avg *>> teamRank;
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
    shared_ptr<vector<player_avg *>> playerRank;
    shared_ptr<vector<team_avg *>> teamRank;
>>>>>>> origin/master

    // 命令
    shared_ptr<command> playerRankCommand;
    shared_ptr<command> teamRankCommand;

    vector<float> data;
    vector<string> dataName;
    void getData();
    QChart *drawTable(const QString &title);

    void showShoot();
    void showThree();
    void showPenalty();
    void showBackboard();
    void showAssisting();
    void showFalut();
    void showScore();
    void showVictory();
};

#endif // PAGERANK_H
