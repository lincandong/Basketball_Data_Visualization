#ifndef PAGETEAM_H
#define PAGETEAM_H

#include <QWidget>
#include <QPixmap>
#include <QtCharts>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "../commands/base/command.h"
#include "../common/dataType.h"
#include "myLabel.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class pageTeam;
}

class pageTeam : public QWidget
{
    Q_OBJECT

public:
    QList<myLabel *> *listLabel;

    explicit pageTeam(QWidget *parent = 0);
    ~pageTeam();

    void setName(string name);
    void setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr);
    void setTeamDataCommand(shared_ptr<command> ptr);
    void setPlayerName(string name);

    void init();

signals:
    void showPagePlayer(string name);

private:
    Ui::pageTeam *ui;
    string name;

    shared_ptr<dataParameter> para;

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<shared_ptr<team_avg>>> teamData;

    void addLabel(myLabel *label, int row, int col);
    void showTeamData();
};

#endif // PAGETEAM_H
