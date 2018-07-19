#include "pageData.h"
#include "ui_pageData.h"

QString teamName[6][5] = {
    {"ATL", "CHA", "MIA", "ORL", "WAS"},
    {"CHI", "CLE", "DET", "IND", "MIL"},
    {"BKN", "BOS", "NYK", "PHI", "TOR"},
    {"GSW", "LAC", "LAL", "PHO", "SAC"},
    {"DEN", "MIN", "OKC", "POR", "UTA"},
    {"DAL", "HOU", "MEM", "NOH", "SAS"}
};

pageData::pageData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageData)
{
    ui->setupUi(this);

    // show picture
    int width = 92;
    int height = 30;

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

pageData::~pageData()
{
    delete ui;
}

void pageData::addLabel(myLabel *label, int row, int col)
{
    ui->gridLayoutTeam->addWidget(label, row, col);
}
