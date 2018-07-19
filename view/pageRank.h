#ifndef PAGERANK_H
#define PAGERANK_H

#include <QWidget>
#include <QtCharts>

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
};

#endif // PAGERANK_H
