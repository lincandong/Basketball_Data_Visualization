#include "pageTeam.h"
#include "ui_pageTeam.h"

pageTeam::pageTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageTeam)
{
    ui->setupUi(this);
}

pageTeam::~pageTeam()
{
    delete ui;
}
