#ifndef PAGEPLAYER_H
#define PAGEPLAYER_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <vector>
#include <memory>
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
class pagePlayer;
}

class pagePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit pagePlayer(QWidget *parent = 0);
    ~pagePlayer();

    void setPlayerDataCommand(shared_ptr<command> ptr);
<<<<<<< HEAD
<<<<<<< HEAD
    void setPlayer(shared_ptr<vector<shared_ptr<player_avg>>> player);
=======
    void setPlayer(shared_ptr<vector<player_avg *>> player);
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
    void setPlayer(shared_ptr<vector<player_avg *>> player);
>>>>>>> origin/master

    void update();

private:
    Ui::pagePlayer *ui;

    QChartView *viewTemp;

    shared_ptr<command> playerDataCommand;
<<<<<<< HEAD
<<<<<<< HEAD
    shared_ptr<vector<shared_ptr<player_avg>>> player;
=======
    shared_ptr<vector<player_avg *>> player;
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
    shared_ptr<vector<player_avg *>> player;
>>>>>>> origin/master

    void showTotal();
    void showShoot();
    void showThree();
    void showPenalty();
    void showBackboard();
    void showAssisting();
    void showFalut();
    void showScore();
    void showVictory();

};

#endif // PAGEPLAYER_H
