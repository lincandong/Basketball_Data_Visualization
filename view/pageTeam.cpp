#include "pageTeam.h"
#include "ui_pageTeam.h"
#include "myLabel.h"


pageTeam::pageTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageTeam)
{
    ui->setupUi(this);

    //para = make_shared<dataParameter>("name", "fgper");
    // 初始化队伍
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
}

pageTeam::~pageTeam()
{
    delete ui;
}

void pageTeam::update()
{
    QString str = ":/gif/gif/";
    str.append(name);
    str.append(".gif");
    QPixmap pix(str);
    ui->labelTeamPix->setPixmap(pix);
    ui->labelTeamEn->setText(name);

    // 更新数据
//    shared_ptr<dataParameter> temp = make_ptr<dataParameter>(name, "fgper");
//    teamDataCommand->setParameter(temp);
//    teamDataCommand->action();
    // 更新图表
//    QLineSeries *series = new QLineSeries;
<<<<<<< HEAD
<<<<<<< HEAD
//    foreach(shared_ptr<team_avg> temp, *teamData)
=======
//    foreach(team_avg *temp, *teamData)
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
//    foreach(team_avg *temp, *teamData)
>>>>>>> origin/master
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
}

<<<<<<< HEAD
<<<<<<< HEAD
void pageTeam::getData()
{
    data.clear();
    season.clear();
    if (para->option == "fgper")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->fgper);
            season.push_back(temp->season);
        }
    else if (para->option == "threepper")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->threepper);
            season.push_back(temp->season);
        }
    else if (para->option == "ftper")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->threepper);
            season.push_back(temp->season);
        }
    else if (para->option == "trb")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->threepper);
            season.push_back(temp->season);
        }
    else if (para->option == "ast")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->ast);
            season.push_back(temp->season);
        }
    else if (para->option == "tov")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->tov);
            season.push_back(temp->season);
        }
    else if (para->option == "pts")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->pts);
            season.push_back(temp->season);
        }
    else if (para->option == "wg")
        foreach(shared_ptr<team_avg> temp, *teamData)
        {
            data.push_back(temp->wg);
            season.push_back(temp->season);
        }
}
/*
QChart *pageTeam::drawTable(const QString &title)
{
    QBarSet *set;
    QLineSeries *series = new QLineSeries;
    QChart *chart = new QChart;
    for (unsigned int i = 0; i < data.size(); i++)
    {
        set = new QBarSet(QString::fromStdString());
        *set << data.at(i);
        series
    }
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle(title);
    return chart;
}*/

void pageTeam::setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr)
=======
void pageTeam::setTeam(shared_ptr<vector<team_avg *>> ptr)
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
void pageTeam::setTeam(shared_ptr<vector<team_avg *>> ptr)
>>>>>>> origin/master
{
    teamData = ptr;
}

void pageTeam::setTeamDataCommand(shared_ptr<command> ptr)
{
    teamDataCommand = ptr;
}

void pageTeam::setName(QString name)
{
    this->name = name;
}
