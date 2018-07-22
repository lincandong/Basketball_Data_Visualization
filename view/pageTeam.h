#ifndef PAGETEAM_H
#define PAGETEAM_H

#include <QWidget>
#include <QPixmap>
#include <QtCharts>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "../commands/command.h"
#include "../common/data.h"

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

    void setName(QString name);
    void setTeam(shared_ptr<vector<team_avg *>> ptr);
    void setTeamDataCommand(shared_ptr<command> ptr);

    void update();

signals:
    void showPagePlayer();

private:
    Ui::pageTeam *ui;
    QString name;

    shared_ptr<dataParameter> para;

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<team_avg *>> teamData;
};

#endif // PAGETEAM_H
