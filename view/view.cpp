#include "view.h"
#include "ui_view.h"

#include <QLabel>

view::view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);

    commandReceiver = make_shared<ViewCommandReceiver>(this);
    propertyReceiver = make_shared<ViewPropertyReceiver>(this);

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
    connect(page_data, &pageData::showPageTeam, this, &view::switchPageTeam);
}

view::~view()
{
    delete ui;
}
shared_ptr<ViewCommandReceiver> view::getCommandReceiver()
{
    return commandReceiver;
}

shared_ptr<ViewPropertyReceiver> view::getPropertyReceiver()
{
    return propertyReceiver;
}

void view::switchPageStart()
{
    if (ui->stackedWidget->currentWidget() != page_start)
        ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_start);
}

void view::switchPageRank()
{
    if (ui->stackedWidget->currentWidget() != page_rank)
        ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_rank);

    page_rank->init();
}

void view::switchPageData()
{
    if (ui->stackedWidget->currentWidget() != page_data)
        ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_data);
}

void view::switchPageTeam(string name)
{
    if (ui->stackedWidget->currentWidget() != page_team)
        ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_team);

    page_team->setName(name);
    page_team->init();
}

void view::switchPagePlayer(string name)
{
    if (ui->stackedWidget->currentWidget() != page_player)
        ui->stackedWidget->currentWidget()->hide();
    ui->stackedWidget->setCurrentWidget(page_player);

    page_player->setName(name);
    page_player->init();
}

void view::setPlayerDataCommand(shared_ptr<command> ptr)
{
    this->playerDataCommand = ptr;

    page_player->setPlayerDataCommand(ptr);
}

void view::setPlayerRankCommand(shared_ptr<command> ptr)
{
    this->playerRankCommand = ptr;
    page_rank->setPlayerRankCommand(ptr);
}

void view::setTeamDataCommand(shared_ptr<command> ptr)
{
    this->teamDataCommand = ptr;

    page_team->setTeamDataCommand(ptr);
}

void view::setTeamRankCommand(shared_ptr<command> ptr)
{
    this->teamRankCommand = ptr;

    page_rank->setTeamRankCommand(ptr);
}

void view::setPlayerRank(shared_ptr<vector<shared_ptr<player_avg>>> playerRank)
{
    page_rank->setPlayerRank(playerRank);
}

void view::setTeamRank(shared_ptr<vector<shared_ptr<team_avg>>> teamRank)
{
    page_rank->setTeamRank(teamRank);
}

void view::setPlayer(shared_ptr<vector<shared_ptr<player_avg>>> player)
{
    page_player->setPlayer(player);
}

void view::setTeam(shared_ptr<vector<shared_ptr<team_avg>>> team)
{
    page_team->setTeam(team);
}
