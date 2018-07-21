#ifndef PAGERANK_H
#define PAGERANK_H

#include <QWidget>
#include <QtCharts>

#include <memory>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class pageRank;
}

class pageRank : public QWidget
{
    Q_OBJECT

public:
    explicit pageRank(QWidget *parent = 0);
    ~pageRank();

private:
    Ui::pageRank *ui;

    QList<QChartView *> list;
    bool isTeam;
    /*
    void showShoot();
    void showThree();
    void showPenalty();
    void showBackboard();
    void showAssisting();
    void showFalut();
    void showScore();
    void showVictory();*/
};

#endif // PAGERANK_H
