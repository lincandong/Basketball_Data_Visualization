#include "pageTeam.h"
#include "ui_pageTeam.h"
#include "myLabel.h"


pageTeam::pageTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageTeam)
{
    ui->setupUi(this);
    listLabel = new QList<myLabel *>;

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
    str.append(QString::fromStdString(name));
    str.append(".gif");
    QPixmap pix(str);
    ui->labelTeamPix->setPixmap(pix);
    ui->labelTeamEn->setText(QString::fromStdString(name));

    para = make_shared<dataParameter>(name, "fgper", "17", "17");
    showShoot();

    // initialize players
    int size = teamData->at(0)->players.size();
    int row, col = 4;

    if (size % row != 0)
        row = size / col + 1;
    else
        row = size / col;

    for (int i = 0; i <  row; i++)
    {
        for (int j = 0; j < col && i * col + j < size; j++)
        {
            QString name = ":/full/full/";
            string temp = (teamData->at(0)->players).at(i * col + j);
            name.append(QString::fromStdString(temp));
            name.append(".jpg");
            QPixmap *pix = new QPixmap(name);
            if (pix->data_ptr() == nullptr)
                pix = new QPixmap(QString::fromStdString(":/full/full/默认.jpg"));
            myLabel *qlabel = new myLabel;
            qlabel->setPixmap(*pix);
            qlabel->setScaledContents(true);
            qlabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            qlabel->setValue(i * col + j);
            qlabel->setName(temp);
            listLabel->push_back(qlabel);
            addLabel(qlabel, i * 2, j);

            myLabel *qlabelName = new myLabel;
            qlabelName->setText(QString::fromStdString(temp));
            qlabelName->setAlignment(Qt::AlignVCenter);
            qlabelName->setAlignment(Qt::AlignHCenter);
            qlabelName->setValue(i * col + j);
            listLabel->push_back(qlabelName);
            addLabel(qlabelName, i * 2 + 1, j);
        }
    }
    ui->scrollAreaWidgetContents->setMinimumHeight(size * 80);

    for (int i = 0; i < 2 * size; i++)
        connect(listLabel->at(i), &myLabel::clickedForName, this, &pageTeam::setPlayerName);
}

void pageTeam::addLabel(myLabel *label, int row, int col)
{
    ui->layoutPlayers->addWidget(label, row, col);
}


void pageTeam::showShoot()
{
   if (ui->stackedWidget->currentWidget() != ui->pageShoot)
       ui->stackedWidget->setCurrentWidget(ui->pageShoot);

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
    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutShoot->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutShoot->removeItem(child);
        }
    }
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

void pageTeam::showThree()
{
    if (ui->stackedWidget->currentWidget() != ui->pageThree)
        ui->stackedWidget->setCurrentWidget(ui->pageThree);

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

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutThree->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutThree->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutThree->addWidget(view1, 0, 0);
    ui->layoutThree->addWidget(view2, 0, 1);
    ui->layoutThree->addWidget(view3, 1, 0);
}

void pageTeam::showPenalty()
{
    if (ui->stackedWidget->currentWidget() != ui->pagePenalty)
        ui->stackedWidget->setCurrentWidget(ui->pagePenalty);

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

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutPenalty->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutPenalty->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutPenalty->addWidget(view1, 0, 0);
    ui->layoutPenalty->addWidget(view2, 0, 1);
    ui->layoutPenalty->addWidget(view3, 1, 0);
}

void pageTeam::showBackboard()
{
    if (ui->stackedWidget->currentWidget() != ui->pageBackboard)
        ui->stackedWidget->setCurrentWidget(ui->pageBackboard);

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

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutBackboard->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutBackboard->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);

    ui->layoutBackboard->addWidget(view1, 0, 0);
    ui->layoutBackboard->addWidget(view2, 0, 1);
    ui->layoutBackboard->addWidget(view3, 1, 0);
}

void pageTeam::showAssisting()
{
    if (ui->stackedWidget->currentWidget() != ui->pageAssisting)
        ui->stackedWidget->setCurrentWidget(ui->pageAssisting);

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

     if (ui->layoutShoot->itemAt(0) != nullptr)
     {
         QLayoutItem *child;
         while ((child =ui->layoutAssisting->takeAt(0)) != 0) {
             child->widget()->setParent(nullptr);
             ui->layoutAssisting->removeItem(child);
         }
     }

     QChartView *view1 = new QChartView;
     view1->setChart(chart1);
     QChartView *view2 = new QChartView;
     view2->setChart(chart2);
     QChartView *view3 = new QChartView;
     view3->setChart(chart3);

     ui->layoutAssisting->addWidget(view1, 0, 0);
     ui->layoutAssisting->addWidget(view2, 0, 1);
     ui->layoutAssisting->addWidget(view3, 1, 0);
}

void pageTeam::showFalut()
{
    if (ui->stackedWidget->currentWidget() != ui->pageFalut)
        ui->stackedWidget->setCurrentWidget(ui->pageFalut);

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
     QChart *chart1 = new QChart;
     chart1->setAnimationOptions(QChart::SeriesAnimations);
     chart1->addSeries(series1);
     chart1->setTitle("失误");
     QChart *chart2 = new QChart;
     chart2->setAnimationOptions(QChart::SeriesAnimations);
     chart2->addSeries(series2);
     chart2->setTitle("犯规");

     if (ui->layoutShoot->itemAt(0) != nullptr)
     {
         QLayoutItem *child;
         while ((child =ui->layoutFalut->takeAt(0)) != 0) {
             child->widget()->setParent(nullptr);
             ui->layoutFalut->removeItem(child);
         }
     }

     QChartView *view1 = new QChartView;
     view1->setChart(chart1);
     QChartView *view2 = new QChartView;
     view2->setChart(chart2);

     ui->layoutFalut->addWidget(view1, 0, 0);
     ui->layoutFalut->addWidget(view2, 0, 1);
}

void pageTeam::showScore()
{
    if (ui->stackedWidget->currentWidget() != ui->pageScore)
        ui->stackedWidget->setCurrentWidget(ui->pageScore);

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
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->setTitle("得分");

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutScore->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutScore->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);

    ui->layoutScore->addWidget(view1, 0, 0);
}

void pageTeam::showVictory()
{
    if (ui->stackedWidget->currentWidget() != ui->pageVictory)
        ui->stackedWidget->setCurrentWidget(ui->pageVictory);

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
     QChart *chart1 = new QChart;
     chart1->setAnimationOptions(QChart::SeriesAnimations);
     chart1->addSeries(series1);
     chart1->setTitle("胜");
     QChart *chart2 = new QChart;
     chart2->setAnimationOptions(QChart::SeriesAnimations);
     chart2->addSeries(series2);
     chart2->setTitle("负");

     if (ui->layoutShoot->itemAt(0) != nullptr)
     {
         QLayoutItem *child;
         while ((child =ui->layoutVictory->takeAt(0)) != 0) {
             child->widget()->setParent(nullptr);
             ui->layoutVictory->removeItem(child);
         }
     }

     QChartView *view1 = new QChartView;
     view1->setChart(chart1);
     QChartView *view2 = new QChartView;
     view2->setChart(chart2);

     ui->layoutVictory->addWidget(view1, 0, 0);
     ui->layoutVictory->addWidget(view2, 0, 1);
}

void pageTeam::setTeam(shared_ptr<vector<shared_ptr<team_avg>>> ptr)
{
    teamData = ptr;
}

void pageTeam::setTeamDataCommand(shared_ptr<command> ptr)
{
    teamDataCommand = ptr;
}

void pageTeam::setName(string name)
{
    this->name = name;
}

void pageTeam::setPlayerName(string name)
{
   emit showPagePlayer(name);
}
