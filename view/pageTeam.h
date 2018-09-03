#ifndef PAGETEAM_H
#define PAGETEAM_H

#include <QWidget>
#include <QPixmap>
#include <QtCharts>
#include <string>
#include <vector>
#include <memory>
using namespace std;

<<<<<<< HEAD
#include "../commands/base/command.h"
#include "../common/dataType.h"
=======
#include "../commands/command.h"
#include "../common/data.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

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
<<<<<<< HEAD
    void setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr);
=======
    void setTeam(shared_ptr<vector<team_avg *>> ptr);
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
    void setTeamDataCommand(shared_ptr<command> ptr);

    void update();

signals:
    void showPagePlayer();

private:
    Ui::pageTeam *ui;
    QString name;

<<<<<<< HEAD
    QChartView *view1, *view2, *view3, *view4;
    shared_ptr<dataParameter> para;

    vector<float> data;
    vector<string> season;

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<shared_ptr<team_avg>>> teamData;

    void getData();
    QChart *drawTable(const QString &title);
=======
    shared_ptr<dataParameter> para;

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<team_avg *>> teamData;
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
};

#endif // PAGETEAM_H
