#include "pageData.h"
#include "ui_pageData.h"

QString teamName[6][5] = {
    {QString::fromLocal8Bit("亚特兰大老鹰"), QString::fromLocal8Bit("夏洛特黄蜂"), QString::fromLocal8Bit("迈阿密热火"), QString::fromLocal8Bit("奥兰多魔术"), QString::fromLocal8Bit("华盛顿奇才")},
    {QString::fromLocal8Bit("芝加哥公牛"), QString::fromLocal8Bit("克里夫兰骑士"), QString::fromLocal8Bit("底特律活塞"), QString::fromLocal8Bit("印第安纳步行者"), QString::fromLocal8Bit("密尔沃基雄鹿")},
    {QString::fromLocal8Bit("布鲁克林篮网"), QString::fromLocal8Bit("波士顿凯尔特人"), QString::fromLocal8Bit("纽约尼克斯"), QString::fromLocal8Bit("费城76人"), QString::fromLocal8Bit("多伦多猛龙")},
    {QString::fromLocal8Bit("金州勇士"), QString::fromLocal8Bit("洛杉矶快船"), QString::fromLocal8Bit("洛杉矶湖人"), QString::fromLocal8Bit("菲尼克斯太阳"), QString::fromLocal8Bit("萨克拉门托国王")},
    {QString::fromLocal8Bit("丹佛掘金"), QString::fromLocal8Bit("明尼苏达森林狼"), QString::fromLocal8Bit("俄克拉荷马雷霆"), QString::fromLocal8Bit("波特兰开拓者"), QString::fromLocal8Bit("犹他爵士")},
    {QString::fromLocal8Bit("达拉斯独行侠"), QString::fromLocal8Bit("休斯顿火箭"), QString::fromLocal8Bit("孟菲斯灰熊"), QString::fromLocal8Bit("新奥尔良鹈鹕"), QString::fromLocal8Bit("圣安东尼奥马刺")}
};

pageData::pageData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pageData)
{
    ui->setupUi(this);

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

    for (int i = 0; i < 60; i++)
        connect(listLabel->at(i), &myLabel::clicked, this, &pageData::setTeamName);
}

pageData::~pageData()
{
    delete ui;
}

void pageData::setTeamName(int value)
{
    int i, j;
    i = value / 5;
    j = value % 5;

   emit showPageTeam(teamName[i][j]);
}


void pageData::addLabel(myLabel *label, int row, int col)
{
    ui->gridLayoutTeam->addWidget(label, row, col);
}
