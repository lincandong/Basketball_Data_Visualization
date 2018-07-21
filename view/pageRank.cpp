#include "pageRank.h"
#include "ui_pageRank.h"

pageRank::pageRank(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageRank)
{
    ui->setupUi(this);

    //para = make_shared<rankParameter>("fgper", 17);
    isTeam = true;
/*
  connect(ui->buttonShoot, &QPushButton::clicked, this, &pageRank::showShoot);
   connect(ui->buttonThree, &QPushButton::clicked, this, &pageRank::showThree);
    connect(ui->buttonPenalty, &QPushButton::clicked, this, &pageRank::showPenalty);
    connect(ui->buttonBackboard, &QPushButton::clicked, this, &pageRank::showBackboard);
    connect(ui->buttonAssisting, &QPushButton::clicked, this, &pageRank::showAssisting);
    connect(ui->buttonFalut, &QPushButton::clicked, this, &pageRank::showFalut);
    connect(ui->buttonScore, &QPushButton::clicked, this, &pageRank::showScore);
    connect(ui->buttonVictory, &QPushButton::clicked, this, &pageRank::showVictory);

    showShoot();*/
    //para = std::make_shared<rankParameter>("fgper", 17);
   // teamRankCommand->setParameter(std::static_pointer_cast<parameters, rankParameter>(para));
    //teamRankCommand->action();

    // 加判断当前对象为球队还是球员来切换球队球员
}

pageRank::~pageRank()
{
    delete ui;
}
/*
void pageRank::showShoot()
{


    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QBarSeries *series2 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChart *chart2 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    QChartView *view2 = new QChartView;
    if (isTeam == true) {
        //para->option = "fgper";
        //teamRankCommand->action();
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        //shared_ptr<rankParameter> t = shared_ptr<rankParameter>(new rankParameter("test", 17));
        //teamRankCommand->setParameter(t);
        //para = std::make_shared<rankParameter>("fgper", 17);
        //teamRankCommand->setParameter(std::static_pointer_cast<parameters, rankParameter>(para));
        //teamRankCommand->action();


        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->fgper;
            series0->append(set);
        }
        //para->option = "fg";
        //teamRankCommand->setparameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->fg;
            series1->append(set);
        }
        //para->option = "fga";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->fga;
            series2->append(set);
        }
    } else {
        //para->option = "fgper";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->fgper;
            series0->append(set);
        }
        //para->option = "fg";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->fg;
            series1->append(set);
        }
        //para->option = "fga";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->fga;
            series2->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("投篮");
    chart0->createDefaultAxes();
    chart0->axisY()->setRange(0, 100);
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    ui->gridLayoutTable->rowStretch(0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("投篮次数");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 1, 0);
    list.push_back(view1);

    chart2->addSeries(series2);
    chart2->setTitle("投篮命中数");
    chart2->createDefaultAxes();
    view2 = new QChartView;
    view2->setChart(chart2);
    ui->gridLayoutTable->addWidget(view2, 1, 1);
    list.push_back(view2);
}

void pageRank::showThree()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QBarSeries *series2 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChart *chart2 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    QChartView *view2 = new QChartView;
    if (isTeam == true) {
        //para->option = "threepper";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->threepper;
            series0->append(set);
        }
        //para->option = "threep";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->threep;
            series1->append(set);
        }
       // para->option = "threepa";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->threepa;
            series2->append(set);
        }
    } else {
        //para->option = "threepper";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->threepper;
            series0->append(set);
        }
        //para->option = "threep";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->threep;
            series1->append(set);
        }
        //para->option = "threepa";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->threepa;
            series2->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("三分");
    chart0->createDefaultAxes();
    chart0->axisY()->setRange(0, 100);
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    ui->gridLayoutTable->rowStretch(0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("三分次数");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 1, 0);
    list.push_back(view1);

    chart2->addSeries(series2);
    chart2->setTitle("三分命中数");
    chart2->createDefaultAxes();
    view2 = new QChartView;
    view2->setChart(chart2);
    ui->gridLayoutTable->addWidget(view2, 1, 1);
    list.push_back(view2);
}

void pageRank::showPenalty()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QBarSeries *series2 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChart *chart2 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    QChartView *view2 = new QChartView;
    if (isTeam == true) {
        //para->option = "ftper";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->ftper;
            series0->append(set);
        }
        //para->option = "ft";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->ft;
            series1->append(set);
        }
        //para->option = "fta";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->fta;
            series2->append(set);
        }
    } else {
        //para->option = "ftper";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->ftper;
            series0->append(set);
        }
        //para->option = "ft";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->ft;
            series1->append(set);
        }
        //para->option = "fta";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->fta;
            series2->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("罚球");
    chart0->createDefaultAxes();
    chart0->axisY()->setRange(0, 100);
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    ui->gridLayoutTable->rowStretch(0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("罚球次数");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 1, 0);
    list.push_back(view1);

    chart2->addSeries(series2);
    chart2->setTitle("罚球命中数");
    chart2->createDefaultAxes();
    view2 = new QChartView;
    view2->setChart(chart2);
    ui->gridLayoutTable->addWidget(view2, 1, 1);
    list.push_back(view2);
}

void pageRank::showBackboard()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QBarSeries *series2 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChart *chart2 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    QChartView *view2 = new QChartView;
    if (isTeam == true) {
        //para->option = "trb";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->trb;
            series0->append(set);
        }
        //para->option = "orb";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->orb;
            series1->append(set);
        }
        //para->option = "drb";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->drb;
            series2->append(set);
        }
    } else {
        //para->option = "trb";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->trb;
            series0->append(set);
        }
        //para->option = "orb";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->orb;
            series1->append(set);
        }
        //para->option = "drb";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->drb;
            series2->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("篮板");
    chart0->createDefaultAxes();
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    ui->gridLayoutTable->rowStretch(0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("前场");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 1, 0);
    list.push_back(view1);

    chart2->addSeries(series2);
    chart2->setTitle("后场");
    chart2->createDefaultAxes();
    view2 = new QChartView;
    view2->setChart(chart2);
    ui->gridLayoutTable->addWidget(view2, 1, 1);
    list.push_back(view2);
}

void pageRank::showAssisting()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QBarSeries *series2 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChart *chart2 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    QChartView *view2 = new QChartView;
    if (isTeam == true) {
        //para->option = "ast";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->ast;
            series0->append(set);
        }
        //para->option = "stl";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->stl;
            series1->append(set);
        }
        //para->option = "blk";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->blk;
            series2->append(set);
        }
    } else {
        //para->option = "ast";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->ast;
            series0->append(set);
        }
        //para->option = "stl";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->stl;
            series1->append(set);
        }
        //para->option = "blk";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->blk;
            series2->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("助攻");
    chart0->createDefaultAxes();
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    ui->gridLayoutTable->rowStretch(0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("抢断");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 1, 0);
    list.push_back(view1);

    chart2->addSeries(series2);
    chart2->setTitle("盖帽");
    chart2->createDefaultAxes();
    view2 = new QChartView;
    view2->setChart(chart2);
    ui->gridLayoutTable->addWidget(view2, 1, 1);
    list.push_back(view2);
}

void pageRank::showFalut()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    if (isTeam == true) {
       // para->option = "tov";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->tov;
            series0->append(set);
        }
        //para->option = "pf";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->pf;
            series1->append(set);
        }
    } else {
       // para->option = "tov";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->tov;
            series0->append(set);
        }
        //para->option = "pf";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->pf;
            series1->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("失误");
    chart0->createDefaultAxes();
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("犯规");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 0, 1);
    list.push_back(view1);
}

void pageRank::showScore()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSeries *series0 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChartView *view0 = new QChartView;
    if (isTeam == true) {
        //para->option = "pts";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            QBarSet *set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->pts;
            series0->append(set);
        }
    } else {
        //para->option = "pts";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            QBarSet *set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->pts;
            series0->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("得分");
    chart0->createDefaultAxes();
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    list.push_back(view0);
}

void pageRank::showVictory()
{
    foreach(QChartView *viewTemp, list)
    {
        viewTemp->setParent(NULL);
        ui->gridLayoutTable->removeWidget(viewTemp);
    }
    list.clear();

    QBarSet *set;
    QBarSeries *series0 = new QBarSeries;
    QBarSeries *series1 = new QBarSeries;
    QChart *chart0 = new QChart;
    QChart *chart1 = new QChart;
    QChartView *view0 = new QChartView;
    QChartView *view1 = new QChartView;
    if (isTeam == true) {
        //para->option = "wg";
        //teamRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->wg;
            series0->append(set);
        }
        for (unsigned int i = 0; i < teamRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(teamRank->at(i)->name));
            *set << teamRank->at(i)->lg;
            series1->append(set);
        }
    } else {
        //para->option = "w";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->w;
            series0->append(set);
        }
        //para->option = "l";
        //playerRankCommand->setParameter(static_pointer_cast<parameters, rankParameter>(para));
        for (unsigned int i = 0; i < playerRank->size(); i++) {
            set = new QBarSet(QString::fromStdString(playerRank->at(i)->name));
            *set << playerRank->at(i)->l;
            series1->append(set);
        }
    }
    chart0->addSeries(series0);
    chart0->setTitle("胜");
    chart0->createDefaultAxes();
    view0->setChart(chart0);
    ui->gridLayoutTable->addWidget(view0, 0, 0);
    list.push_back(view0);

    chart1->addSeries(series1);
    chart1->setTitle("负");
    chart1->createDefaultAxes();
    view1->setChart(chart1);
    ui->gridLayoutTable->addWidget(view1, 0, 1);
    list.push_back(view1);
}

void pageRank::setTeamRankCommand(shared_ptr<command> ptr)
{
    teamRankCommand = ptr;
}

void pageRank::setPlayerRankCommand(shared_ptr<command> ptr)
{
    playerRankCommand = ptr;
}

void pageRank::setPlayerRank(shared_ptr<vector<player_avg *>> playerRank)
{
    this->playerRank = playerRank;
}

void pageRank::setTeamRank(shared_ptr<vector<team_avg *>> teamRank)
{
    this->teamRank = teamRank;
}
*/
