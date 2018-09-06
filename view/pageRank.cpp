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

    para = make_shared<rankParameter>("fgper", 17);
    isTeam = true;
    showShoot();
}

pageRank::~pageRank()
{
    delete ui;
}

void pageRank::showShoot()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
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
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageRank::showThree()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
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
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageRank::showPenalty()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
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
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageRank::showBackboard()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
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
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageRank::showAssisting()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
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
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageRank::showFalut()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("失误");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("犯规");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));

        view1->chart()->series().clear();
        view2->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
    }
}

void pageRank::showScore()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("得分");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);

        ui->layoutShoot->addWidget(view1, 0, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        view1->chart()->series().clear();
        view1->chart()->addSeries(series1);
    }
}

void pageRank::showVictory()
{
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
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("胜");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("负");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));

        view1->chart()->series().clear();
        view2->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
    }
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
}

void pageRank::on_buttonPlayer_clicked()
{
    isTeam = false;
}
