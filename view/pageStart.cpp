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
{
    emit showPageRank();
}

void pageStart::on_buttonData_clicked()
{
    emit showPageData();
}
