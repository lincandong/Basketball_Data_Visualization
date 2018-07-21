#ifndef PAGEPLAYER_H
#define PAGEPLAYER_H

#include <QWidget>
#include <QtCharts>
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class pagePlayer;
}

class pagePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit pagePlayer(QWidget *parent = 0);
    ~pagePlayer();

private:
    Ui::pagePlayer *ui;

    QChartView *viewTemp;

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
