#include "view.h"
#include "ui_view.h"

#include <QLabel>

////////// 需要实现的部分 //////////////
/*void view::set_cmd1(openfile* ptr)
{
    c1 = ptr;
}
/* ... */
///////////////////////////////////////

QString teamName[6][5] = {
    {"ATL", "CHA", "MIA", "ORL", "WAS"},
    {"CHI", "CLE", "DET", "IND", "MIL"},
    {"BKN", "BOS", "NYK", "PHI", "TOR"},
    {"GSW", "LAC", "LAL", "PHO", "SAC"},
    {"DEN", "MIN", "OKC", "POR", "UTA"},
    {"DAL", "HOU", "MEM", "NOH", "SAS"}
};

view::view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);

    // connect
    connect(ui->actionStart, &QAction::triggered, this, &view::switchPageStart);
    connect(ui->actionRank, &QAction::triggered, this, &view::switchPageRank);
    connect(ui->actionData, &QAction::triggered, this, &view::switchPageData);

    connect(ui->pushButtonRank, &QPushButton::clicked, this, &view::switchPageRank);
    connect(ui->pushButtonData, &QPushButton::clicked, this, &view::switchPageData);

    connect(ui->pushButtonTeam, &QPushButton::clicked, this, &view::switchPageTeamDetail);
    connect(ui->pushButtonPlayer, &QPushButton::clicked, this, &view::switchPagePlayer);

    // show picture
    int width = 99;
    int height = 66;

    listLabel = new QList<myLabel *>;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            QString name = ":/gif/gif/";
            name.append(teamName[i][j]);
            name.append(".gif");
            QPixmap pix(name);
            myLabel *qlabel = new myLabel;
            pix = pix.scaled(QSize(width, height), Qt::KeepAspectRatio);
            qlabel->setPixmap(pix);
            qlabel->setScaledContents(true);
            qlabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            qlabel->setValue(i * 5 + j);
            listLabel->push_back(qlabel);
            addLabel(qlabel, j * 2, i);

            myLabel *qlabelName = new myLabel;
            qlabelName->setText(teamName[i][j]);
            qlabelName->setAlignment(Qt::AlignVCenter);
            qlabelName->setAlignment(Qt::AlignHCenter);
            qlabelName->setValue(i * 5 + j);
            listLabel->push_back(qlabelName);
            addLabel(qlabelName, j * 2 + 1, i);
        }
    }
}

view::~view()
{
    listLabel->clear();

    delete ui;
}

void view::updatePageTeam()
{
    int i = currentTeamIndex / 5;
    int j = currentTeamIndex % 5;

    QString name = ":/gif/gif/";
    name.append(teamName[i][j]);
    name.append(".gif");
    QPixmap pix(name);

    ui->labelTeamPix->setPixmap(pix);
    ui->labelTeamName->setText(teamName[i][j]);
}

void view::switchPageStart()
{
    ui->stackedWidget->setCurrentWidget(ui->pageStart);
}

void view::switchPageRank()
{
    ui->stackedWidget->setCurrentWidget(ui->pageRank);
}

void view::switchPageData()
{
    ui->stackedWidget->setCurrentWidget(ui->pageData);
}

void view::switchPageTeam(int index)
{
    currentTeamIndex = index;

    updatePageTeam();

    ui->stackedWidget->setCurrentWidget(ui->pageTeam);
}

void view::switchPageTeamDetail()
{
    ui->stackedWidgetTeam->setCurrentWidget(ui->pageTeamDetail);
}

void view::switchPagePlayer()
{
    ui->stackedWidgetTeam->setCurrentWidget(ui->pagePlayer);
}

void view::addLabel(myLabel *label, int row, int col)
{
    ui->gridLayoutTeam->addWidget(label, row, col);
    connect(label, &myLabel::clicked, this, &view::switchPageTeam);
}
