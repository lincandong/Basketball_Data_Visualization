#include "pageRank.h"
#include "ui_pageRank.h"

#include <iostream>

pageRank::pageRank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageRank)
{
    ui->setupUi(this);

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
    para = make_shared<rankParameter>("fgper", 17);
    isTeam = true;

    showShoot();
}

void pageRank::showShoot()
{
    if (ui->stackedWidget->currentWidget() != ui->pageShoot)
        ui->stackedWidget->setCurrentWidget(ui->pageShoot);
    // modify parameter and send command
    para->option = "fgper";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->fgper;
            *set2 << (*iter)->fg;
            *set3 << (*iter)->fga;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->fgper;
            *set2 << (*iter)->fg;
            *set3 << (*iter)->fga;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);
    QBarSeries *series3 = new QBarSeries;
    series3->append(set3);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("投篮");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("命中");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->setTitle("出手");
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
    ui->layoutShoot->addWidget(view2, 0, 1);
    ui->layoutShoot->addWidget(view3, 1, 0);
}

void pageRank::showThree()
{
    if (ui->stackedWidget->currentWidget() != ui->pageThree)
        ui->stackedWidget->setCurrentWidget(ui->pageThree);
    // modify parameter and send command
    para->option = "threepper";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->threepper;
            *set2 << (*iter)->threep;
            *set3 << (*iter)->threepa;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->threepper;
            *set2 << (*iter)->threep;
            *set3 << (*iter)->threepa;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);
    QBarSeries *series3 = new QBarSeries;
    series3->append(set3);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("三分");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("命中");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->setTitle("出手");

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
    ui->layoutThree->addWidget(view2, 0, 1);
    ui->layoutThree->addWidget(view3, 1, 0);
}

void pageRank::showPenalty()
{
    if (ui->stackedWidget->currentWidget() != ui->pagePenalty)
        ui->stackedWidget->setCurrentWidget(ui->pagePenalty);
    // modify parameter and send command
    para->option = "ftper";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->ftper;
            *set2 << (*iter)->ft;
            *set3 << (*iter)->fta;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->ftper;
            *set2 << (*iter)->ft;
            *set3 << (*iter)->fta;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);
    QBarSeries *series3 = new QBarSeries;
    series3->append(set3);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("罚球");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("命中");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->setTitle("出手");

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
    ui->layoutPenalty->addWidget(view2, 0, 1);
    ui->layoutPenalty->addWidget(view3, 1, 0);
}

void pageRank::showBackboard()
{
    if (ui->stackedWidget->currentWidget() != ui->pageBackboard)
        ui->stackedWidget->setCurrentWidget(ui->pageBackboard);
    // modify parameter and send command
    para->option = "trb";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->trb;
            *set2 << (*iter)->orb;
            *set3 << (*iter)->drb;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->trb;
            *set2 << (*iter)->orb;
            *set3 << (*iter)->drb;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);
    QBarSeries *series3 = new QBarSeries;
    series3->append(set3);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("篮板");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("前场");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->setTitle("后场");

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
    ui->layoutBackboard->addWidget(view2, 0, 1);
    ui->layoutBackboard->addWidget(view3, 1, 0);
}

void pageRank::showAssisting()
{
    if (ui->stackedWidget->currentWidget() != ui->pageAssisting)
        ui->stackedWidget->setCurrentWidget(ui->pageAssisting);
    // modify parameter and send command
    para->option = "ast";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->ast;
            *set2 << (*iter)->stl;
            *set3 << (*iter)->blk;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->ast;
            *set2 << (*iter)->stl;
            *set3 << (*iter)->blk;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);
    QBarSeries *series3 = new QBarSeries;
    series3->append(set3);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("助攻");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("抢断");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->setTitle("盖帽");

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
    ui->layoutAssisting->addWidget(view2, 0, 1);
    ui->layoutAssisting->addWidget(view3, 1, 0);
}

void pageRank::showFalut()
{
    if (ui->stackedWidget->currentWidget() != ui->pageFalut)
        ui->stackedWidget->setCurrentWidget(ui->pageFalut);
    // modify parameter and send command
    para->option = "tov";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->tov;
            *set2 << (*iter)->pf;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->tov;
            *set2 << (*iter)->pf;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("失误");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("犯规");

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
    ui->layoutFalut->addWidget(view2, 0, 1);
}

void pageRank::showScore()
{
    if (ui->stackedWidget->currentWidget() != ui->pageScore)
        ui->stackedWidget->setCurrentWidget(ui->pageScore);
    // modify parameter and send command
    para->option = "pts";
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
            *set1 << (*iter)->pts;
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
            *set1 << (*iter)->pts;

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("得分");

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
    // modify parameter and send command
    para->season = ui->boxSeason->value();
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
    if (isTeam)
    {
        vector<shared_ptr<team_avg>>::iterator iter;
        for (iter = teamRank->begin(); iter != teamRank->end(); iter++)
        {
            *set1 << (*iter)->wg;
            *set2 << (*iter)->lg;
        }
    }
    else
    {
        vector<shared_ptr<player_avg>>::iterator iter;
        for (iter = playerRank->begin(); iter != playerRank->end(); iter++)
        {
            *set1 << (*iter)->w;
            *set2 << (*iter)->l;
        }

    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("胜");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->setTitle("负");

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
    ui->layoutVictory->addWidget(view2, 0, 1);
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

void pageRank::on_boxSeason_valueChanged(int arg1)
{
    if (isTeam == true)
    {
        para->season = arg1;

        teamRankCommand->setParameter(para);
        teamRankCommand->action();
    }
    else
    {
        para->season = arg1;
        playerRankCommand->setParameter(para);
        playerRankCommand->action();
    }
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
