#include "pageTeam.h"
#include "ui_pageTeam.h"
#include "myLabel.h"


pageTeam::pageTeam(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageTeam)
{
    ui->setupUi(this);
    listLabel = new QList<myLabel *>;
}

pageTeam::~pageTeam()
{
    delete ui;
}

void pageTeam::init()
{
    QList<myLabel *>::iterator it;
    for (it = listLabel->begin(); it != listLabel->end(); it++)
    {
        (*it)->setParent(nullptr);
        ui->layoutPlayers->removeWidget(*it);
    }
    listLabel->clear();

    QString str = ":/gif/gif/";
    str.append(QString::fromStdString(name));
    str.append(".gif");
    QPixmap pix(str);
    ui->labelTeamPix->setPixmap(pix);
    ui->labelTeamEn->setText(QString::fromStdString(name));

    para = make_shared<dataParameter>(name, "fgper", "17", "17");
    showTeamData();
    if (ui->tabWidget->currentWidget() != ui->tab)
        ui->tabWidget->setCurrentWidget(ui->tab);

    // initialize players
    int size = teamData->at(0)->players.size();
    int row, col = 4;

    if (size % col != 0)
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


void pageTeam::showTeamData()
{
    if (ui->tabWidget->currentWidget() != ui->tab)
        ui->tabWidget->setCurrentWidget(ui->tab);

    ui->scrollAreaWidgetContents_2->setMinimumHeight(2000);

    // modify parameter and send command
    para->option = "fgper";
    teamDataCommand->setParameter(para);
    teamDataCommand->action();

    // get current data
    QBarSet *set1 = new QBarSet("投篮");
    QBarSet *set2 = new QBarSet("三分");
    QBarSet *set3 = new QBarSet("罚球");
    QBarSet *set4 = new QBarSet("篮板");
    QBarSet *set5 = new QBarSet("助攻/抢断/盖帽");
    QBarSet *set6 = new QBarSet("失误/犯规");
    QBarSet *set7 = new QBarSet("得分");
    QBarSet *set8 = new QBarSet("胜负");
    if (teamData->begin() != teamData->end())
    {
        shared_ptr<team_avg> temp = teamData->at(0);
        *set1 << temp->fgper << temp->fg << temp->fga;
        *set2 << temp->threepper << temp->threep << temp->threepa;
        *set3 << temp->ftper << temp->ft << temp->fta;
        *set4 << temp->trb << temp->orb << temp->drb;
        *set5 << temp->ast << temp->stl << temp->blk;
        *set6 << temp->tov << temp->pf;
        *set7 << temp->pts;
        *set8 << temp->wg << temp->lg;
    }
    QBarSeries *series1 = new QBarSeries;
    series1->append(set1);
    series1->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series1->setLabelsVisible(true);

    QBarSeries *series2 = new QBarSeries;
    series2->append(set2);
    series2->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series2->setLabelsVisible(true);

    QBarSeries *series3 = new QBarSeries;
    series3->append(set3);
    series3->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series3->setLabelsVisible(true);

    QBarSeries *series4 = new QBarSeries;
    series4->append(set4);
    series4->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series4->setLabelsVisible(true);

    QBarSeries *series5 = new QBarSeries;
    series5->append(set5);
    series5->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series5->setLabelsVisible(true);

    QBarSeries *series6 = new QBarSeries;
    series6->append(set6);
    series6->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series6->setLabelsVisible(true);

    QBarSeries *series7 = new QBarSeries;
    series7->append(set7);
    series7->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series7->setLabelsVisible(true);

    QBarSeries *series8 = new QBarSeries;
    series8->append(set8);
    series8->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series8->setLabelsVisible(true);

    QStringList categories1 = {"投篮", "命中", "出手"};
    QStringList categories2 = {"三分", "命中", "出手"};
    QStringList categories3 = {"罚球", "命中", "出手"};
    QStringList categories4 = {"篮板", "前场", "后场"};
    QStringList categories5 = {"助攻", "抢断", "盖帽"};
    QStringList categories6 = {"失误", "犯规"};
    QStringList categories7 = {"得分"};
    QStringList categories8 = {"胜", "负"};
    QBarCategoryAxis *axis1 = new QBarCategoryAxis();
    axis1->append(categories1);
    QBarCategoryAxis *axis2 = new QBarCategoryAxis();
    axis2->append(categories2);
    QBarCategoryAxis *axis3 = new QBarCategoryAxis();
    axis3->append(categories3);
    QBarCategoryAxis *axis4 = new QBarCategoryAxis();
    axis4->append(categories4);
    QBarCategoryAxis *axis5 = new QBarCategoryAxis();
    axis5->append(categories5);
    QBarCategoryAxis *axis6 = new QBarCategoryAxis();
    axis6->append(categories6);
    QBarCategoryAxis *axis7 = new QBarCategoryAxis();
    axis7->append(categories7);
    QBarCategoryAxis *axis8 = new QBarCategoryAxis();
    axis8->append(categories8);

    // update view
    if (ui->layoutTeamData->itemAt(0) != nullptr)
    {
        QLayoutItem *child;
        while ((child =ui->layoutTeamData->takeAt(0)) != 0) {
            child->widget()->setParent(nullptr);
            ui->layoutTeamData->removeItem(child);
        }
    }
    QChart *chart1 = new QChart;
    chart1->setAnimationOptions(QChart::SeriesAnimations);
    chart1->addSeries(series1);
    chart1->createDefaultAxes();
    chart1->setAxisX(axis1, series1);
    QChartView *view1 = new QChartView;
    view1->setChart(chart1);
    ui->layoutTeamData->addWidget(view1, 0, 0);

    QChart *chart2 = new QChart;
    chart2->setAnimationOptions(QChart::SeriesAnimations);
    chart2->addSeries(series2);
    chart2->createDefaultAxes();
    chart2->setAxisX(axis2, series2);
    QChartView *view2 = new QChartView;
    view2->setChart(chart2);
    ui->layoutTeamData->addWidget(view2, 0, 1);

    QChart *chart3 = new QChart;
    chart3->setAnimationOptions(QChart::SeriesAnimations);
    chart3->addSeries(series3);
    chart3->createDefaultAxes();
    chart3->setAxisX(axis3, series3);
    QChartView *view3 = new QChartView;
    view3->setChart(chart3);
    ui->layoutTeamData->addWidget(view3, 1, 0);

    QChart *chart4 = new QChart;
    chart4->setAnimationOptions(QChart::SeriesAnimations);
    chart4->addSeries(series4);
    chart4->createDefaultAxes();
    chart4->setAxisX(axis4, series4);
    QChartView *view4 = new QChartView;
    view4->setChart(chart4);
    ui->layoutTeamData->addWidget(view4, 1, 1);

    QChart *chart5 = new QChart;
    chart5->setAnimationOptions(QChart::SeriesAnimations);
    chart5->addSeries(series5);
    chart5->createDefaultAxes();
    chart5->setAxisX(axis5, series5);
    QChartView *view5 = new QChartView;
    view5->setChart(chart5);
    ui->layoutTeamData->addWidget(view5, 2, 0);

    QChart *chart6 = new QChart;
    chart6->setAnimationOptions(QChart::SeriesAnimations);
    chart6->addSeries(series6);
    chart6->createDefaultAxes();
    chart6->setAxisX(axis6, series6);
    QChartView *view6 = new QChartView;
    view6->setChart(chart6);
    ui->layoutTeamData->addWidget(view6, 2, 1);

    QChart *chart7 = new QChart;
    chart7->setAnimationOptions(QChart::SeriesAnimations);
    chart7->addSeries(series7);
    chart7->createDefaultAxes();
    chart7->setAxisX(axis7, series7);
    QChartView *view7 = new QChartView;
    view7->setChart(chart7);
    ui->layoutTeamData->addWidget(view7, 3, 0);

    QChart *chart8 = new QChart;
    chart8->setAnimationOptions(QChart::SeriesAnimations);
    chart8->addSeries(series8);
    chart8->createDefaultAxes();
    chart8->setAxisX(axis8, series8);
    QChartView *view8 = new QChartView;
    view8->setChart(chart8);
    ui->layoutTeamData->addWidget(view8, 3, 1);
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
