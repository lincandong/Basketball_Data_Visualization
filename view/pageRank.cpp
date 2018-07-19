#include "pageRank.h"
#include "ui_pageRank.h"

pageRank::pageRank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageRank)
{
    ui->setupUi(this);

    QLineSeries *line1 = new QLineSeries;
    line1->append(2015, 73);
    line1->append(2016, 81);
    line1->append(2017, 69);
    line1->append(2018, 67);

    QChart *c = new QChart;
    c->legend()->hide();
    c->setTitle("成绩");
    c->addSeries(line1);
    c->createDefaultAxes();

    ui->chartView->setChart(c);
}

pageRank::~pageRank()
{
    delete ui;
}
