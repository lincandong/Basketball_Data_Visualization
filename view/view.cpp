#include "view.h"
#include "ui_view.h"

#include <QLabel>

view::view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);

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
    this->resize(800, 600);

    // connect
    connect(page_start, &pageStart::showPageRank, this, &view::switchPageRank);
    connect(page_start, &pageStart::showPageData, this, &view::switchPageData);

    // connect
    connect(ui->actionStart, &QAction::triggered, this, &view::switchPageStart);
    connect(ui->actionRank, &QAction::triggered, this, &view::switchPageRank);
    connect(ui->actionData, &QAction::triggered, this, &view::switchPageData);

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
{
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
