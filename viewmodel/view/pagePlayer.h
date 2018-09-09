#ifndef PAGEPLAYER_H
#define PAGEPLAYER_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

#include <vector>
#include <memory>
using namespace std;

#include "../commands/base/command.h"
#include "../common/dataType.h"

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
    void setPlayer(shared_ptr<vector<shared_ptr<player_avg>>> player);
    void setName(QString name);

    void init();

private:
    Ui::pagePlayer *ui;

    QString name;

    shared_ptr<command> playerDataCommand;
    shared_ptr<vector<shared_ptr<player_avg>>> player;
    shared_ptr<dataParameter> para;

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
