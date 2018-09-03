#include "pageRank.h"
#include "ui_pageRank.h"

#include <iostream>

pageRank::pageRank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageRank)
{
    ui->setupUi(this);

    connect(ui->buttonShoot, &QPushButton::clicked, this, &pageRank::showShoot);
    /*connect(ui->buttonThree, &QPushButton::clicked, this, &pageRank::showThree);
    connect(ui->buttonPenalty, &QPushButton::clicked, this, &pageRank::showPenalty);
    connect(ui->buttonBackboard, &QPushButton::clicked, this, &pageRank::showBackboard);
    connect(ui->buttonAssisting, &QPushButton::clicked, this, &pageRank::showAssisting);
    connect(ui->buttonFalut, &QPushButton::clicked, this, &pageRank::showFalut);
    connect(ui->buttonScore, &QPushButton::clicked, this, &pageRank::showScore);
    connect(ui->buttonVictory, &QPushButton::clicked, this, &pageRank::showVictory);*/

    para = make_shared<rankParameter>("fgper", 17);
    isTeam = true;
}

pageRank::~pageRank()
{
    delete ui;
}

void pageRank::showShoot()
{
    // 改变参数，发出命令
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

    // 初始化布局
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
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

        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        QChart *chart3 = new QChart;
        chart3->setAnimationOptions(QChart::SeriesAnimations);
        chart3->addSeries(series3);

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


    // chart view

}
/*
void pageRank::showThree()
{
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
    view1->setChart(drawTable("三分"));
}

void pageRank::showPenalty()
{
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
    view1->setChart(drawTable("罚球"));
}

void pageRank::showBackboard()
{
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
    view1->setChart(drawTable("篮板"));
}

void pageRank::showAssisting()
{
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
    view1->setChart(drawTable("助攻"));
}

void pageRank::showFalut()
{
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
    view1->setChart(drawTable("失误"));
}

void pageRank::showScore()
{
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
    view1->setChart(drawTable("分数"));
}

void pageRank::showVictory()
{
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
    view1->setChart(drawTable("胜"));
}
*/
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
