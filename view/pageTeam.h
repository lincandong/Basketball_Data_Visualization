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
    QList<myLabel *> *listLabel;    // store all labels

    explicit pageTeam(QWidget *parent = 0);
    ~pageTeam();

    void setName(string name);                                  // set team's name
    void setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr); // set team's data
    void setTeamDataCommand(shared_ptr<command> ptr);           // set command
    void setPlayerName(string name);                            // get player's name

    void init();    // initialize page team

signals:
    void showPagePlayer(string name);   // send player's name to page player

private:
    Ui::pageTeam *ui;
    string name;    // team name

    shared_ptr<dataParameter> para; // parameter for command

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<shared_ptr<team_avg>>> teamData;

    void addLabel(myLabel *label, int row, int col);    // add label to layout
    void showTeamData();    // draw charts for team's data
};

#endif // PAGETEAM_H
