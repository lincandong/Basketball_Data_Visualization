#include "pageRank.h"
#include "ui_pageRank.h"

#include <iostream>

pageRank::pageRank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageRank)
{
    ui->setupUi(this);

    // connections
    connect(ui->buttonShoot, &QPushButton::clicked, this, &pageRank::showShoot);
    connect(ui->buttonThree, &QPushButton::clicked, this, &pageRank::showThree);
    connect(ui->buttonPenalty, &QPushButton::clicked, this, &pageRank::showPenalty);
    connect(ui->buttonBackboard, &QPushButton::clicked, this, &pageRank::showBackboard);
    connect(ui->buttonAssisting, &QPushButton::clicked, this, &pageRank::showAssisting);
    connect(ui->buttonFalut, &QPushButton::clicked, this, &pageRank::showFalut);
    connect(ui->buttonScore, &QPushButton::clicked, this, &pageRank::showScore);
    connect(ui->buttonVictory, &QPushButton::clicked, this, &pageRank::showVictory);
}

pageRank::~pageRank()
{
    delete ui;
}

void pageRank::init()
{
    // initialize parameter
    para = make_shared<rankParameter>("fgper", 17);
    isTeam = true;
    // show chart
    showShoot();
}

void pageRank::showShoot()
{
    // show chart page and set scroll area's height
    if (ui->stackedWidget->currentWidget() != ui->pageShoot)
        ui->stackedWidget->setCurrentWidget(ui->pageShoot);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);

    // modify parameter and send command
    para->option = "fgper";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("投篮");
    QBarSet *set2 = new QBarSet("命中");
    QBarSet *set3 = new QBarSet("出手");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->fgper;
            *set2 << (*riter)->fg;
            *set3 << (*riter)->fga;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->fgper;
            *set2 << (*riter)->fg;
            *set3 << (*riter)->fga;
            categories << QString::fromStdString((*riter)->name);
        }

    }

    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);
    QHorizontalBarSeries *series3 = new QHorizontalBarSeries;
    series3->append(set3);
    series3->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series3->setLabelsVisible(true);

    // set axis
    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisY(axis3, series3);
    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutShoot->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutShoot->removeItem(child);
        }
    }
    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutShoot->addWidget(view1, 0, 0);
    ui->layoutShoot->addWidget(view2, 1, 0);
    ui->layoutShoot->addWidget(view3, 2, 0);
}

void pageRank::showThree()
{
    if (ui->stackedWidget->currentWidget() != ui->pageThree)
        ui->stackedWidget->setCurrentWidget(ui->pageThree);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "threepper";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("三分");
    QBarSet *set2 = new QBarSet("命中");
    QBarSet *set3 = new QBarSet("出手");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->threepper;
            *set2 << (*riter)->threep;
            *set3 << (*riter)->threepa;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->threepper;
            *set2 << (*riter)->threep;
            *set3 << (*riter)->threepa;
            categories << QString::fromStdString((*riter)->name);
        }

    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);
    QHorizontalBarSeries *series3 = new QHorizontalBarSeries;
    series3->append(set3);
    series3->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series3->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisY(axis3, series3);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutThree->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutThree->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutThree->addWidget(view1, 0, 0);
    ui->layoutThree->addWidget(view2, 1, 0);
    ui->layoutThree->addWidget(view3, 2, 0);
}

void pageRank::showPenalty()
{
    if (ui->stackedWidget->currentWidget() != ui->pagePenalty)
        ui->stackedWidget->setCurrentWidget(ui->pagePenalty);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "ftper";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("罚球");
    QBarSet *set2 = new QBarSet("命中");
    QBarSet *set3 = new QBarSet("出手");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->ftper;
            *set2 << (*riter)->ft;
            *set3 << (*riter)->fta;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->ftper;
            *set2 << (*riter)->ft;
            *set3 << (*riter)->fta;
            categories << QString::fromStdString((*riter)->name);
        }

    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);
    QHorizontalBarSeries *series3 = new QHorizontalBarSeries;
    series3->append(set3);
    series3->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series3->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisY(axis3, series3);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutPenalty->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutPenalty->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutPenalty->addWidget(view1, 0, 0);
    ui->layoutPenalty->addWidget(view2, 1, 0);
    ui->layoutPenalty->addWidget(view3, 2, 0);
}

void pageRank::showBackboard()
{
    if (ui->stackedWidget->currentWidget() != ui->pageBackboard)
        ui->stackedWidget->setCurrentWidget(ui->pageBackboard);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "trb";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("篮板");
    QBarSet *set2 = new QBarSet("前场");
    QBarSet *set3 = new QBarSet("后场");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->trb;
            *set2 << (*riter)->orb;
            *set3 << (*riter)->drb;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->trb;
            *set2 << (*riter)->orb;
            *set3 << (*riter)->drb;
            categories << QString::fromStdString((*riter)->name);
        }

    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);
    QHorizontalBarSeries *series3 = new QHorizontalBarSeries;
    series3->append(set3);
    series3->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series3->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisY(axis3, series3);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutBackboard->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutBackboard->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutBackboard->addWidget(view1, 0, 0);
    ui->layoutBackboard->addWidget(view2, 1, 0);
    ui->layoutBackboard->addWidget(view3, 2, 0);
}

void pageRank::showAssisting()
{
    if (ui->stackedWidget->currentWidget() != ui->pageAssisting)
        ui->stackedWidget->setCurrentWidget(ui->pageAssisting);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "ast";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("助攻");
    QBarSet *set2 = new QBarSet("抢断");
    QBarSet *set3 = new QBarSet("盖帽");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->ast;
            *set2 << (*riter)->stl;
            *set3 << (*riter)->blk;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->ast;
            *set2 << (*riter)->stl;
            *set3 << (*riter)->blk;
            categories << QString::fromStdString((*riter)->name);
        }

    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);
    QHorizontalBarSeries *series3 = new QHorizontalBarSeries;
    series3->append(set3);
    series3->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series3->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisY(axis3, series3);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutAssisting->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutAssisting->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutAssisting->addWidget(view1, 0, 0);
    ui->layoutAssisting->addWidget(view2, 1, 0);
    ui->layoutAssisting->addWidget(view3, 2, 0);
}

void pageRank::showFalut()
{
    if (ui->stackedWidget->currentWidget() != ui->pageFalut)
        ui->stackedWidget->setCurrentWidget(ui->pageFalut);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "tov";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("失误");
    QBarSet *set2 = new QBarSet("犯规");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->tov;
            *set2 << (*riter)->pf;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->tov;
            *set2 << (*riter)->pf;
            categories << QString::fromStdString((*riter)->name);
        }

    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutFalut->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutFalut->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);

    ui->layoutFalut->addWidget(view1, 0, 0);
    ui->layoutFalut->addWidget(view2, 1, 0);
}

void pageRank::showScore()
{
    if (ui->stackedWidget->currentWidget() != ui->pageScore)
        ui->stackedWidget->setCurrentWidget(ui->pageScore);
    ui->scrollAreaWidgetContents->setMinimumHeight(500);
    // modify parameter and send command
    para->option = "pts";
    para->season = 2017;
    if (isTeam == true)
    {
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("得分");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->pts;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->pts;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    axis1->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutScore->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutScore->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);

    ui->layoutScore->addWidget(view1, 0, 0);
}

void pageRank::showVictory()
{
    if (ui->stackedWidget->currentWidget() != ui->pageVictory)
        ui->stackedWidget->setCurrentWidget(ui->pageVictory);
    ui->scrollAreaWidgetContents->setMinimumHeight(1000);
    // modify parameter and send command
    para->season = 2017;
    if (isTeam == true)
    {
        para->option = "wg";
        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        para->option = "w";
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }

    // get current data
    QBarSet *set1 = new QBarSet("胜");
    QBarSet *set2 = new QBarSet("负");
    QStringList categories;
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::reverse_iterator riter;
        for (riter = teamRank->rbegin(); riter != teamRank->rend(); riter++)
        {
            *set1 << (*riter)->wg;
            *set2 << (*riter)->lg;
            categories << QString::fromStdString((*riter)->name);
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::reverse_iterator riter;
        for (riter = playerRank->rbegin(); riter != playerRank->rend(); riter++)
        {
            *set1 << (*riter)->w;
            *set2 << (*riter)->l;
            categories << QString::fromStdString((*riter)->name);
        }

    }
    QHorizontalBarSeries *series1 = new QHorizontalBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);
    QHorizontalBarSeries *series2 = new QHorizontalBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisY(axis1, series1);
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisY(axis2, series2);

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutVictory->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutVictory->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);

    ui->layoutVictory->addWidget(view1, 0, 0);
    ui->layoutVictory->addWidget(view2, 1, 0);
}

void pageRank::setTeamRankCommand(std::shared_ptr<command> ptr)
{
    teamRankCommand = ptr;
}


void pageRank::setPlayerRankCommand(shared_ptr<command> ptr)
{
    playerRankCommand = ptr;
}

void pageRank::setPlayerRank(shared_ptr<vector<shared_ptr<player_avg>>> playerRank)
{
    this->playerRank = playerRank;
}

void pageRank::setTeamRank(shared_ptr<vector<shared_ptr<team_avg>>> teamRank)
{
    this->teamRank = teamRank;
}

void pageRank::on_buttonTeam_clicked()
{
    isTeam = true;
    showShoot();
}

void pageRank::on_buttonPlayer_clicked()
{
    isTeam = false;
    showShoot();
}
