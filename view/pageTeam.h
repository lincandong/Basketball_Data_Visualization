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
<<<<<<< HEAD
    void setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr);
=======
    void setTeam(shared_ptr<vector<team_avg *>> ptr);
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
    void setTeam(shared_ptr<vector<team_avg *>> ptr);
>>>>>>> origin/master
    void setTeamDataCommand(shared_ptr<command> ptr);

    void update();

signals:
    void showPagePlayer();

private:
    Ui::pageTeam *ui;
    QString name;

<<<<<<< HEAD
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
=======
>>>>>>> origin/master
    shared_ptr<dataParameter> para;

    shared_ptr<command> teamDataCommand;
    shared_ptr<vector<team_avg *>> teamData;
<<<<<<< HEAD
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
>>>>>>> origin/master
};

#endif // PAGETEAM_H
