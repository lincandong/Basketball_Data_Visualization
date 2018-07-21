#ifndef PAGETEAM_H
#define PAGETEAM_H

#include <QWidget>
#include <QtCharts>

//#include "../common/data.h"

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class pageTeam;
}

class pageTeam : public QWidget
{
    Q_OBJECT

public:
    explicit pageTeam(QWidget *parent = 0);
    ~pageTeam();

    //void setTeamData(shared_ptr<team_avg> ptr);

signals:
    void showPagePlayer();

private:
    Ui::pageTeam *ui;

    //shared_ptr<team_avg> teamData;
};

#endif // PAGETEAM_H
