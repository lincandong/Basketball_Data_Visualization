#include "pagePlayer.h"
#include "ui_pagePlayer.h"

pagePlayer::pagePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pagePlayer)
{
    ui->setupUi(this);
}

pagePlayer::~pagePlayer()
{
    delete ui;
}
