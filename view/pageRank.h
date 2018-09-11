#ifndef PAGERANK_H
#define PAGERANK_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <memory>
#include <string>
using namespace std;

#include "../commands/base/command.h"
#include "../common/dataType.h"

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

    void setPlayerRank(shared_ptr<vector<shared_ptr<player_avg>>> playerRank);
    void setTeamRank(shared_ptr<vector<shared_ptr<team_avg>>> teamRank);

    void init();
private slots:
    void on_buttonTeam_clicked();

    void on_buttonPlayer_clicked();

private:
    Ui::pageRank *ui;

    // 参数
    bool isTeam;
    shared_ptr<rankParameter> para;

    // 数据
    shared_ptr<vector<shared_ptr<player_avg>>> playerRank;
    shared_ptr<vector<shared_ptr<team_avg>>> teamRank;

    // 命令
    shared_ptr<command> playerRankCommand;
    shared_ptr<command> teamRankCommand;

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
