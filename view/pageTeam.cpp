#include "pageTeam.h"
#include "ui_pageTeam.h"
#include "myLabel.h"


pageTeam::pageTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageTeam)
{
    ui->setupUi(this);

    // players
    /*QVBoxLayout *vb = new QVBoxLayout();
    vb->addWidget(label1);
    vb->addWidget(label2);
    QHBoxLayout *hb = new QHBoxLayout();
    hb->addLayout(vb);
    hb->addStretch();
    ui->verticalLayoutPlayer->addLayout(hb);
    ui->verticalLayoutPlayer->addStretch();

    connect(label1, &myLabel::clicked, this, &pageTeam::showPagePlayer);
    connect(label2, &myLabel::clicked, this, &pageTeam::showPagePlayer);*/

    // team data
    connect(ui->buttonShoot, &QPushButton::clicked, this, &pageTeam::showShoot);
    connect(ui->buttonThree, &QPushButton::clicked, this, &pageTeam::showThree);
    connect(ui->buttonPenalty, &QPushButton::clicked, this, &pageTeam::showPenalty);
    connect(ui->buttonBackboard, &QPushButton::clicked, this, &pageTeam::showBackboard);
    connect(ui->buttonAssisting, &QPushButton::clicked, this, &pageTeam::showAssisting);
    connect(ui->buttonFalut, &QPushButton::clicked, this, &pageTeam::showFalut);
    connect(ui->buttonScore, &QPushButton::clicked, this, &pageTeam::showScore);
    connect(ui->buttonVictory, &QPushButton::clicked, this, &pageTeam::showVictory);
}

pageTeam::~pageTeam()
{
    delete ui;
}

void pageTeam::init()
{
    QString str = ":/gif/gif/";
    str.append(name);
    str.append(".gif");
    QPixmap pix(str);
    ui->labelTeamPix->setPixmap(pix);
    ui->labelTeamEn->setText(name);

    para = make_shared<dataParameter>(name, "fgper", "17", "17");
    showShoot();
}
/*
void update()
{

    // 更新数据
//    shared_ptr<dataParameter> temp = make_ptr<dataParameter>(name, "fgper");
//    teamDataCommand->setParameter(temp);
//    teamDataCommand->action();
    // 更新图表
//    QLineSeries *series = new QLineSeries;
//    foreach(shared_ptr<team_avg> temp, *teamData)
//    {
//        QPoint *point = new QPoint(temp->season, temp->fgper);
//        series->append(point);
//    }
//    QChart *chart = new QChart;
//    chart->addSeries(series);
//    ui->widget->setChart(chart);
    // 更新队员列表
    // ...
    // 使用QVBoxLayout,每5个队员用一个QHBoxLayout
    // int cout = 0;
    // foreach() { count++; if (count == 5) {count = 0; //创建新的layout }}
    // layout->addStretch();
    // 循环中为队员标签添加点击事件 myLabel... connect();
}*/

void pageTeam::showShoot()
{
    // modify parameter and send command
    para->option = "fgper";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data

}

void pageTeam::showThree()
{

}

void pageTeam::showPenalty()
{

}

void pageTeam::showBackboard()
{

}

void pageTeam::showAssisting()
{

}

void pageTeam::showFalut()
{

}

void pageTeam::showScore()
{

}

void pageTeam::showVictory()
{

}

void pageTeam::setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr)
{
    teamData = ptr;
}

void pageTeam::setTeamDataCommand(shared_ptr<command> ptr)
{
    teamDataCommand = ptr;
}

void pageTeam::setName(QString name)
{
    this->name = name.toStdString();
}
