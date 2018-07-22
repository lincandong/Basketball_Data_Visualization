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

    view1 = new QChartView;
    view2 = new QChartView;
    view3 = new QChartView;
    view4 = new QChartView;
    ui->gridLayoutTable->addWidget(view1, 0, 0);
    ui->gridLayoutTable->addWidget(view2, 0, 1);
    ui->gridLayoutTable->addWidget(view3, 1, 0);
    ui->gridLayoutTable->addWidget(view4, 1, 1);

    para = make_shared<rankParameter>("fgper", 17);
    isTeam = true;
}

pageRank::~pageRank()
{
    delete ui;
}

void pageRank::init()
{
    showShoot();
}

void pageRank::getData()
{
    data.clear();
    dataName.clear();
    if (isTeam)
    {
        if (para->option == "fgper")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->fgper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "threepper")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->threepper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "ftper")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->threepper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "trb")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->threepper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "ast")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->ast);
                dataName.push_back(temp->name);
            }
        else if (para->option == "tov")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->tov);
                dataName.push_back(temp->name);
            }
        else if (para->option == "pts")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->pts);
                dataName.push_back(temp->name);
            }
        else if (para->option == "wg")
            foreach(team_avg *temp, *teamRank)
            {
                data.push_back(temp->wg);
                dataName.push_back(temp->name);
            }
    }
    else
    {
        if (para->option == "fgper")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->fgper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "threepper")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->threepper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "ftper")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->threepper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "trb")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->threepper);
                dataName.push_back(temp->name);
            }
        else if (para->option == "ast")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->ast);
                dataName.push_back(temp->name);
            }
        else if (para->option == "tov")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->tov);
                dataName.push_back(temp->name);
            }
        else if (para->option == "pts")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->pts);
                dataName.push_back(temp->name);
            }
        else if (para->option == "w")
            foreach(player_avg *temp, *playerRank)
            {
                data.push_back(temp->w);
                dataName.push_back(temp->name);
            }
    }
}

QChart *pageRank::drawTable(const QString &title)
{
    QBarSet *set;
    QBarSeries *series = new QBarSeries;
    QChart *chart = new QChart;
    for (unsigned int i = 0; i < data.size(); i++)
    {
        set = new QBarSet(QString::fromStdString(dataName.at(i)));
        *set << data.at(i);
        series->append(set);
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(title);
    return chart;
}

void pageRank::showShoot()
{
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
    view1->setChart(drawTable("投篮"));
}

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

void pageRank::setTeamRankCommand(std::shared_ptr<command> ptr)
{
    teamRankCommand = ptr;
}


void pageRank::setPlayerRankCommand(shared_ptr<command> ptr)
{
    playerRankCommand = ptr;
}

void pageRank::setPlayerRank(shared_ptr<vector<player_avg *>> playerRank)
{
    this->playerRank = playerRank;
}

void pageRank::setTeamRank(shared_ptr<vector<team_avg *>> teamRank)
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
    init();
}

void pageRank::on_buttonPlayer_clicked()
{
    isTeam = false;
    init();
}
