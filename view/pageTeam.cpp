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

    para = make_shared<dataParameter>(name.toStdString(), "fgper", "17", "17");
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
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->fgper);
        series2->append(count, (*iter)->fg);
        series3->append(count, (*iter)->fga);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("投篮");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("命中");
        QChart *chart3 = new QChart;
        chart3->setAnimationOptions(QChart::SeriesAnimations);
        chart3->addSeries(series3);
        chart3->setTitle("出手");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);
        QChartView *view3 = new QChartView;
        view3->setChart(chart3);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
        ui->layoutShoot->addWidget(view3, 1, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageTeam::showThree()
{
    // modify parameter and send command
    para->option = "threepper";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->threepper);
        series2->append(count, (*iter)->threep);
        series3->append(count, (*iter)->threepa);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("三分");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("命中");
        QChart *chart3 = new QChart;
        chart3->setAnimationOptions(QChart::SeriesAnimations);
        chart3->addSeries(series3);
        chart3->setTitle("出手");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);
        QChartView *view3 = new QChartView;
        view3->setChart(chart3);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
        ui->layoutShoot->addWidget(view3, 1, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageTeam::showPenalty()
{
    // modify parameter and send command
    para->option = "ftper";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->ftper);
        series2->append(count, (*iter)->ft);
        series3->append(count, (*iter)->fta);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("罚球");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("命中");
        QChart *chart3 = new QChart;
        chart3->setAnimationOptions(QChart::SeriesAnimations);
        chart3->addSeries(series3);
        chart3->setTitle("出手");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);
        QChartView *view3 = new QChartView;
        view3->setChart(chart3);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
        ui->layoutShoot->addWidget(view3, 1, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageTeam::showBackboard()
{
    // modify parameter and send command
    para->option = "trb";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->trb);
        series2->append(count, (*iter)->orb);
        series3->append(count, (*iter)->drb);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("篮板");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("前场");
        QChart *chart3 = new QChart;
        chart3->setAnimationOptions(QChart::SeriesAnimations);
        chart3->addSeries(series3);
        chart3->setTitle("后场");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);
        QChartView *view3 = new QChartView;
        view3->setChart(chart3);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
        ui->layoutShoot->addWidget(view3, 1, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageTeam::showAssisting()
{
    // modify parameter and send command
    para->option = "ast";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->ast);
        series2->append(count, (*iter)->stl);
        series3->append(count, (*iter)->blk);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("助攻");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("抢断");
        QChart *chart3 = new QChart;
        chart3->setAnimationOptions(QChart::SeriesAnimations);
        chart3->addSeries(series3);
        chart3->setTitle("盖帽");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);
        QChartView *view3 = new QChartView;
        view3->setChart(chart3);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
        ui->layoutShoot->addWidget(view3, 1, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));
        QChartView *view3 = (QChartView *)(ui->layoutShoot->itemAtPosition(1, 0));

        view1->chart()->series().clear();
        view2->chart()->series().clear();
        view3->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
        view3->chart()->addSeries(series3);
    }
}

void pageTeam::showFalut()
{
    // modify parameter and send command
    para->option = "tov";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->tov);
        series2->append(count, (*iter)->pf);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("失误");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("犯规");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));

        view1->chart()->series().clear();
        view2->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
    }
}

void pageTeam::showScore()
{
    // modify parameter and send command
    para->option = "pts";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->pts);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("得分");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);

        ui->layoutShoot->addWidget(view1, 0, 0);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        view1->chart()->series().clear();
        view1->chart()->addSeries(series1);
    }
}

void pageTeam::showVictory()
{
    // modify parameter and send command
    para->option = "wg";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;

    vector<shared_ptr<team_avg>>::iterator iter;
    int count = 1;
    for (iter = teamData->begin(); iter != teamData->end(); iter++)
    {
        series1->append(count, (*iter)->wg);
        series2->append(count, (*iter)->lg);
        count++;
    }

    // update view
    if (ui->layoutShoot->itemAt(0) == nullptr)
    {
        QChart *chart1 = new QChart;
        chart1->setAnimationOptions(QChart::SeriesAnimations);
        chart1->addSeries(series1);
        chart1->setTitle("胜");
        QChart *chart2 = new QChart;
        chart2->setAnimationOptions(QChart::SeriesAnimations);
        chart2->addSeries(series2);
        chart2->setTitle("负");

        QChartView *view1 = new QChartView;
        view1->setChart(chart1);
        QChartView *view2 = new QChartView;
        view2->setChart(chart2);

        ui->layoutShoot->addWidget(view1, 0, 0);
        ui->layoutShoot->addWidget(view2, 0, 1);
    }
    else
    {
        QChartView *view1 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 0));
        QChartView *view2 = (QChartView *)(ui->layoutShoot->itemAtPosition(0, 1));

        view1->chart()->series().clear();
        view2->chart()->series().clear();

        view1->chart()->addSeries(series1);
        view2->chart()->addSeries(series2);
    }
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
    this->name = name;
}
