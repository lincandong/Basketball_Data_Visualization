#ifndef PAGETEAM_H
#define PAGETEAM_H

#include <QWidget>
#include <QtCharts>

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

private:
    Ui::pageTeam *ui;
};

#endif // PAGETEAM_H
