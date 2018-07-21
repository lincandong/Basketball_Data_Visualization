#include "pageTeam.h"
#include "ui_pageTeam.h"
#include "myLabel.h"


pageTeam::pageTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageTeam)
{
    ui->setupUi(this);

    // 初始化队伍
    /*QPixmap pix(":/gif/gif/ATL.gif");
    ui->labelTeamPix->setPixmap(pix);
    ui->labelTeamEn->setText("NULL");
    ui->labelTeamCh->setText("NULL");

    myLabel *label1 = new myLabel;
    myLabel *label2 = new myLabel;
    QPixmap pix2(":/gif/gif/1717.jpg");
    pix2 = pix2.scaled(85, 110);
    label1->setPixmap(pix2);
    label2->setText(QString::fromStdString(basePlayer1.name));
    QVBoxLayout *vb = new QVBoxLayout();
    vb->addWidget(label1);
    vb->addWidget(label2);
    QHBoxLayout *hb = new QHBoxLayout();
    hb->addLayout(vb);
    hb->addStretch();
    ui->verticalLayoutPlayer->addLayout(hb);
    ui->verticalLayoutPlayer->addStretch();

    connect(label1, &myLabel::clicked, this, &pageTeam::showPagePlayer);
    connect(label2, &myLabel::clicked, this, &pageTeam::showPagePlayer);*/
}

pageTeam::~pageTeam()
{
    delete ui;
}
/*
void pageTeam::setTeamData(shared_ptr<team_avg> ptr)
{
    teamData = ptr;
}
*/
