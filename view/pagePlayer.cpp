#include "pagePlayer.h"
#include "ui_pagePlayer.h"
#include "myLabel.h"

class Option {
public:
    int index;		// 编号
    std::string name;	// 名字

    int count;	// 子选项数目
    std::vector<std::string> nameList;	// 子选项的名字，下标是它们的编号

    Option(int index, std::string name, int count) : index(index), name(name), count(count) {}
};

pagePlayer::pagePlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pagePlayer)
{
    ui->setupUi(this);
/*
    ui->labelPlayerName->setText(QString::fromStdString(basePlayer1.name));
    QPixmap pix(":/gif/gif/1717.jpg");
    pix = pix.scaled(85, 110);
    ui->labelPlayerPix->setPixmap(pix);

    connect(ui->buttonTotal, &QPushButton::clicked, this, &pagePlayer::showTotal);
    connect(ui->buttonShoot, &QPushButton::clicked, this, &pagePlayer::showShoot);
    connect(ui->buttonThree, &QPushButton::clicked, this, &pagePlayer::showThree);
    connect(ui->buttonPenalty, &QPushButton::clicked, this, &pagePlayer::showPenalty);
    connect(ui->buttonBackboard, &QPushButton::clicked, this, &pagePlayer::showBackboard);
    connect(ui->buttonAssisting, &QPushButton::clicked, this, &pagePlayer::showAssisting);
    connect(ui->buttonFalut, &QPushButton::clicked, this, &pagePlayer::showFalut);
    connect(ui->buttonScore, &QPushButton::clicked, this, &pagePlayer::showScore);
    connect(ui->buttonVictory, &QPushButton::clicked, this, &pagePlayer::showVictory);

    viewTemp = NULL;

    showTotal();*/
}

pagePlayer::~pagePlayer()
{
    delete ui;
}

void pagePlayer::update()
{

}
/*
void pagePlayer::showTotal()
{
    if (viewTemp != NULL)
    {
        ui->gridLayoutTable->removeWidget(viewTemp);
        delete(viewTemp);
    }
    QBarSet *set0 = new QBarSet("投篮");
    QBarSet *set1 = new QBarSet("三分");
    QBarSet *set2 = new QBarSet("罚球");
    *set0 << basePlayer1.shoot;
    *set1 << basePlayer1.threePoint;
    *set2 << basePlayer1.penaltyShot;

    QBarSeries *series = new QBarSeries;
    series->append(set0);
    series->append(set1);
    series->append(set2);
    QChart *chart = new QChart;
    chart->addSeries(series);
    QChartView *view = new QChartView;
    view->setChart(chart);
    ui->gridLayoutTable->addWidget(view, 0, 1);

    viewTemp = view;
}
void pagePlayer::showShoot()
{
    if (viewTemp != NULL)
    {
        ui->gridLayoutTable->removeWidget(viewTemp);
        delete(viewTemp);
    }
    QLineSeries *series = new QLineSeries;
    series->append(1, basePlayer1.shoot);
    series->append(2, basePlayer2.shoot);
    QChart *chart = new QChart;
    chart->addSeries(series);
    QChartView *view = new QChartView;
    view->setChart(chart);
    ui->gridLayoutTable->addWidget(view, 0, 0);

    viewTemp = view;
}
void pagePlayer::showThree()
{

}
void pagePlayer::showPenalty()
{

}
void pagePlayer::showBackboard()
{

}
void pagePlayer::showAssisting()
{

}
void pagePlayer::showFalut()
{

}
void pagePlayer::showScore()
{

}
void pagePlayer::showVictory()
{

}
*/

void pagePlayer::setPlayerDataCommand(shared_ptr<command> ptr)
{
    playerDataCommand = ptr;
}

<<<<<<< HEAD
void pagePlayer::setPlayer(shared_ptr<vector<shared_ptr<player_avg>> > player)
=======
void pagePlayer::setPlayer(shared_ptr<vector<player_avg *> > player)
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
{
    this->player = player;
}
