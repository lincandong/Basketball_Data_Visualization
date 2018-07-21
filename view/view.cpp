#include "view.h"
#include "ui_view.h"

#include <QLabel>

view::view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);

    //viewCommandReceiver = make_shared<ViewCommandReceiver>(this);

    page_start = new pageStart;
    page_rank = new pageRank;
    page_data = new pageData;
    page_team = new pageTeam;
    page_player = new pagePlayer;

    ui->stackedWidget->addWidget(page_start);
    ui->stackedWidget->addWidget(page_rank);
    ui->stackedWidget->addWidget(page_data);
    ui->stackedWidget->addWidget(page_team);
    ui->stackedWidget->addWidget(page_player);

    ui->stackedWidget->setCurrentWidget(page_start);
    this->move(0, 0);

    // connect
    connect(page_start, &pageStart::showPageData, this, &view::switchPageData);
    connect(page_start, &pageStart::showPageRank, this, &view::switchPageRank);

    // connect
    connect(ui->actionStart, &QAction::triggered, this, &view::switchPageStart);
    connect(ui->actionRank, &QAction::triggered, this, &view::switchPageRank);
    connect(ui->actionData, &QAction::triggered, this, &view::switchPageData);

    connect(page_team, &pageTeam::showPagePlayer, this, &view::switchPagePlayer);

    QList<myLabel *> *temp = page_data->listLabel;
    for (int i = 0; i < 60; i++)
        connect(temp->at(i), &myLabel::clicked, this, &view::switchPageTeam);
}

view::~view()
{
    delete ui;
}

void view::switchPageStart()
{
    ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_start);
}

void view::switchPageRank()
{/*
    shared_ptr<rankParameter> para = make_shared<rankParameter>("fgper", 17);
    teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
    teamRankCommand->action();
*/
    ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_rank);
}

void view::switchPageData()
{
    ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_data);
}

void view::switchPageTeam()
{
    ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_team);
}

void view::switchPagePlayer()
{
    ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_player);
}
/*
void view::setPlayerDataCommand(shared_ptr<command> ptr)
{
    this->playerDataCommand = ptr;
}

void view::setPlayerRankCommand(shared_ptr<command> ptr)
{
    this->playerRankCommand = ptr;

    page_rank->setPlayerRankCommand(ptr);
}

void view::setTeamDataCommand(shared_ptr<command> ptr)
{
    this->teamDataCommand = ptr;
}

void view::setTeamRankCommand(shared_ptr<command> ptr)
{
    this->teamRankCommand = ptr;

    page_start->setTeamRankCommand(ptr);
    page_rank->setTeamRankCommand(ptr);
}

void view::setPlayerRank(shared_ptr<vector<player_avg *>> playerRank)
{
    page_rank->setPlayerRank(playerRank);
}

void view::setTeamRank(shared_ptr<vector<team_avg *>> teamRank)
{
    page_rank->setTeamRank(teamRank);
}

void view::setPlayer(vector<float *> player)
{

}

void view::setTeam(vector<float *> team)
{

}*/
