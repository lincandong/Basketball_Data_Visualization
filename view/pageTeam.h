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
    void setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr);
    void setTeamDataCommand(shared_ptr<command> ptr);

    void update();

signals:
    void showPagePlayer();

private:
    Ui::pageTeam *ui;
    QString name;

    QChartView *view1, *view2, *view3, *view4;
    shared_ptr<dataParameter> para;

    vector<float> data;
    vector<string> season;

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<shared_ptr<team_avg>>> teamData;

    void getData();
    QChart *drawTable(const QString &title);
};

#endif // PAGETEAM_H
