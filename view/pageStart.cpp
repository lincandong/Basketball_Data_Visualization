#include "pageStart.h"
#include "ui_pageStart.h"

pageStart::pageStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageStart)
{
    ui->setupUi(this);
}

pageStart::~pageStart()
{
    delete ui;
}


void pageStart::on_buttonRank_clicked()
{/*
    para = std::make_shared<rankParameter>("fgper", 17);
    teamRankCommand->setParameter(std::static_pointer_cast<parameters, rankParameter>(para));
    teamRankCommand->action();
*/
    emit showPageRank();
}

void pageStart::on_buttonData_clicked()
{
    emit showPageData();
}
/*
void pageStart::setTeamRankCommand(std::shared_ptr<command> ptr)
{
    teamRankCommand = ptr;
}*/
