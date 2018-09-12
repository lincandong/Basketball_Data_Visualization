#include "pagePlayer.h"
#include "ui_pagePlayer.h"
#include "myLabel.h"

pagePlayer::pagePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pagePlayer)
{
    ui->setupUi(this);

    // connection
    connect(ui->buttonShoot, &QPushButton::clicked, this, &pagePlayer::showShoot);
    connect(ui->buttonThree, &QPushButton::clicked, this, &pagePlayer::showThree);
    connect(ui->buttonPenalty, &QPushButton::clicked, this, &pagePlayer::showPenalty);
    connect(ui->buttonBackboard, &QPushButton::clicked, this, &pagePlayer::showBackboard);
    connect(ui->buttonAssisting, &QPushButton::clicked, this, &pagePlayer::showAssisting);
    connect(ui->buttonFalut, &QPushButton::clicked, this, &pagePlayer::showFalut);
    connect(ui->buttonScore, &QPushButton::clicked, this, &pagePlayer::showScore);
    connect(ui->buttonVictory, &QPushButton::clicked, this, &pagePlayer::showVictory);
}

pagePlayer::~pagePlayer()
{
    delete ui;
}

void pagePlayer::init()
{
    // show player's name
    ui->labelPlayerName->setText(QString::fromStdString(name.c_str()));
    QString filename = ":/full/full/";
    filename.append(QString::fromStdString(name));
    filename.append(".jpg");

    // show player's picture
    QPixmap *pix = new QPixmap(filename);
    if (pix->data_ptr() == nullptr)
        pix = new QPixmap(QString::fromStdString(":/full/full/默认.jpg"));
    ui->labelPlayerPix->setPixmap(*pix);

    // show chart
    para = make_shared<dataParameter>(name, "fgper", "12-13", "17-18");
    showShoot();
}

void pagePlayer::showShoot()
{
    // show chart page and set scroll area's height
    if (ui->stackedWidget->currentWidget() != ui->pageShoot)
        ui->stackedWidget->setCurrentWidget(ui->pageShoot);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);

    // modify parameter and send command
    para->option = "fgper";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->fgper);
        series2->append(count, (*iter)->fg);
        series3->append(count, (*iter)->fga);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    // set axis
    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisX(axis1, series1);
    chart1->setTitle("投篮");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis2, series2);
    chart2->setTitle("命中");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisX(axis3, series3);
    chart3->setTitle("出手");
    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child = ui->layoutShoot->takeAt(0)) != 0) {
            if (child->widget() != 0)
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
    ui->layoutShoot->addWidget(view2, 1, 0);
    ui->layoutShoot->addWidget(view3, 2, 0);
}

void pagePlayer::showThree()
{
    if (ui->stackedWidget->currentWidget() != ui->pageThree)
        ui->stackedWidget->setCurrentWidget(ui->pageThree);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "threepper";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->threepper);
        series2->append(count, (*iter)->threep);
        series3->append(count, (*iter)->threepa);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisX(axis1, series1);
    chart1->setTitle("三分");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis2, series2);
    chart2->setTitle("命中");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisX(axis3, series3);
    chart3->setTitle("出手");

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutThree->takeAt(0)) != 0) {
            if (child->widget() != 0)
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
    ui->layoutThree->addWidget(view2, 1, 0);
    ui->layoutThree->addWidget(view3, 2, 0);
}

void pagePlayer::showPenalty()
{
    if (ui->stackedWidget->currentWidget() != ui->pagePenalty)
        ui->stackedWidget->setCurrentWidget(ui->pagePenalty);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "ftper";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->ftper);
        series2->append(count, (*iter)->ft);
        series3->append(count, (*iter)->fta);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisX(axis1, series1);
    chart1->setTitle("罚球");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis2, series2);
    chart2->setTitle("命中");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisX(axis3, series3);
    chart3->setTitle("出手");

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutPenalty->takeAt(0)) != 0) {
            if (child->widget() != 0)
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
    ui->layoutPenalty->addWidget(view2, 1, 0);
    ui->layoutPenalty->addWidget(view3, 2, 0);
}

void pagePlayer::showBackboard()
{
    if (ui->stackedWidget->currentWidget() != ui->pageBackboard)
        ui->stackedWidget->setCurrentWidget(ui->pageBackboard);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "trb";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->trb);
        series2->append(count, (*iter)->orb);
        series3->append(count, (*iter)->drb);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisX(axis1, series1);
    chart1->setTitle("篮板");
    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis2, series2);
    chart2->setTitle("前场");
    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisX(axis3, series3);
    chart3->setTitle("后场");

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutBackboard->takeAt(0)) != 0) {
            if (child->widget() != 0)
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
    ui->layoutBackboard->addWidget(view2, 1, 0);
    ui->layoutBackboard->addWidget(view3, 2, 0);
}

void pagePlayer::showAssisting()
{
    if (ui->stackedWidget->currentWidget() != ui->pageAssisting)
        ui->stackedWidget->setCurrentWidget(ui->pageAssisting);
    ui->scrollAreaWidgetContents->setMinimumHeight(1500);
    // modify parameter and send command
    para->option = "ast";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QLineSeries *series3 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->ast);
        series2->append(count, (*iter)->stl);
        series3->append(count, (*iter)->blk);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);
    axis3->append(categories);

    // update view
     QChart *chart1 = new QChart;
     chart1->setAnimationOptions(QChart::SeriesAnimations);
     chart1->addSeries(series1);
     chart1->createDefaultAxes();
     chart1->setAxisX(axis1, series1);
     chart1->setTitle("助攻");
     QChart *chart2 = new QChart;
     chart2->setAnimationOptions(QChart::SeriesAnimations);
     chart2->addSeries(series2);
     chart2->createDefaultAxes();
     chart2->setAxisX(axis2, series2);
     chart2->setTitle("抢断");
     QChart *chart3 = new QChart;
     chart3->setAnimationOptions(QChart::SeriesAnimations);
     chart3->addSeries(series3);
     chart3->createDefaultAxes();
     chart3->setAxisX(axis3, series3);
     chart3->setTitle("盖帽");

     if (ui->layoutShoot->itemAt(0) != nullptr)
     {
         QLayoutItem *child;
         while ((child =ui->layoutAssisting->takeAt(0)) != 0) {
             if (child->widget() != 0)
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
     ui->layoutAssisting->addWidget(view2, 1, 0);
     ui->layoutAssisting->addWidget(view3, 2, 0);
}

void pagePlayer::showFalut()
{
    if (ui->stackedWidget->currentWidget() != ui->pageFalut)
        ui->stackedWidget->setCurrentWidget(ui->pageFalut);
    ui->scrollAreaWidgetContents->setMinimumHeight(1000);
    // modify parameter and send command
    para->option = "tov";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->tov);
        series2->append(count, (*iter)->pf);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);

    // update view
     QChart *chart1 = new QChart;
     chart1->setAnimationOptions(QChart::SeriesAnimations);
     chart1->addSeries(series1);
     chart1->createDefaultAxes();
     chart1->setAxisX(axis1, series1);
     chart1->setTitle("失误");
     QChart *chart2 = new QChart;
     chart2->setAnimationOptions(QChart::SeriesAnimations);
     chart2->addSeries(series2);
     chart2->createDefaultAxes();
     chart2->setAxisX(axis2, series2);
     chart2->setTitle("犯规");

     if (ui->layoutShoot->itemAt(0) != nullptr)
     {
         QLayoutItem *child;
         while ((child =ui->layoutFalut->takeAt(0)) != 0) {
             if (child->widget() != 0)
                 child->widget()->setParent(nullptr);
             ui->layoutFalut->removeItem(child);
         }
     }

     QChartView *view1 = new QChartView;
     view1->setChart(chart1);
     QChartView *view2 = new QChartView;
     view2->setChart(chart2);

     ui->layoutFalut->addWidget(view1, 0, 0);
     ui->layoutFalut->addWidget(view2, 1, 0);
}

void pagePlayer::showScore()
{
    if (ui->stackedWidget->currentWidget() != ui->pageScore)
        ui->stackedWidget->setCurrentWidget(ui->pageScore);
    ui->scrollAreaWidgetContents->setMinimumHeight(500);
    // modify parameter and send command
    para->option = "pts";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->pts);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    axis1->append(categories);

    // update view
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisX(axis1, series1);
    chart1->setTitle("得分");

    if (ui->layoutShoot->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutScore->takeAt(0)) != 0) {
            if (child->widget() != 0)
                child->widget()->setParent(nullptr);
            ui->layoutScore->removeItem(child);
        }
    }

    QChartView *view1 = new QChartView;
    view1->setChart(chart1);

    ui->layoutScore->addWidget(view1, 0, 0);
}

void pagePlayer::showVictory()
{
    if (ui->stackedWidget->currentWidget() != ui->pageVictory)
        ui->stackedWidget->setCurrentWidget(ui->pageVictory);
    ui->scrollAreaWidgetContents->setMinimumHeight(1000);
    // modify parameter and send command
    para->option = "w";
    playerDataCommand->setParameter(para);
    playerDataCommand->action();

    // get current data
    QLineSeries *series1 = new QLineSeries;
    QLineSeries *series2 = new QLineSeries;
    QStringList categories;

    vector<shared_ptr<player_avg>>::iterator iter;
    int count = 4;
    for (iter = player->begin(); iter != player->end(); iter++)
    {
        series1->append(count, (*iter)->w);
        series2->append(count, (*iter)->l);
        count--;
    }
    vector<shared_ptr<player_avg>>::reverse_iterator riter;
    for (riter = player->rbegin(); riter != player->rend(); riter++)
        categories << QString::fromStdString((*riter)->season);

    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    axis1->append(categories);
    axis2->append(categories);

    // update view
     QChart *chart1 = new QChart;
     chart1->setAnimationOptions(QChart::SeriesAnimations);
     chart1->addSeries(series1);
     chart1->createDefaultAxes();
     chart1->setAxisX(axis1, series1);
     chart1->setTitle("胜");
     QChart *chart2 = new QChart;
     chart2->setAnimationOptions(QChart::SeriesAnimations);
     chart2->addSeries(series2);
     chart2->createDefaultAxes();
     chart2->setAxisX(axis2, series2);
     chart2->setTitle("负");

     if (ui->layoutShoot->itemAt(0) != nullptr)
     {
         QLayoutItem *child;
         while ((child =ui->layoutVictory->takeAt(0)) != 0) {
             if (child->widget() != 0)
                 child->widget()->setParent(nullptr);
             ui->layoutVictory->removeItem(child);
         }
     }

     QChartView *view1 = new QChartView;
     view1->setChart(chart1);
     QChartView *view2 = new QChartView;
     view2->setChart(chart2);

     ui->layoutVictory->addWidget(view1, 0, 0);
     ui->layoutVictory->addWidget(view2, 1, 0);
}

void pagePlayer::setPlayerDataCommand(shared_ptr<command> ptr)
{
    playerDataCommand = ptr;
}

void pagePlayer::setPlayer(shared_ptr<vector<shared_ptr<player_avg>> > player)
{
    this->player = player;
}

void pagePlayer::setName(string name)
{
    this->name = name;
}
