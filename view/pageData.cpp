#include "pageData.h"
#include "ui_pageData.h"

string teamName[6][5] = {
    {"亚特兰大老鹰", "夏洛特黄蜂", "迈阿密热火", "奥兰多魔术", "华盛顿奇才"},
    {"芝加哥公牛", "克里夫兰骑士", "底特律活塞", "印第安纳步行者", "密尔沃基雄鹿"},
    {"布鲁克林篮网", "波士顿凯尔特人", "纽约尼克斯", "费城76人", "多伦多猛龙"},
    {"金州勇士", "洛杉矶快船", "洛杉矶湖人", "菲尼克斯太阳", "萨克拉门托国王"},
    {"丹佛掘金", "明尼苏达森林狼", "俄克拉荷马雷霆", "波特兰开拓者", "犹他爵士"},
    {"达拉斯独行侠", "休斯顿火箭", "孟菲斯灰熊", "新奥尔良鹈鹕", "圣安东尼奥马刺"}
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
            name.append(QString::fromStdString(teamName[i][j]));
            name.append(".gif");
            QPixmap pix(name);
            myLabel *qlabel = new myLabel;

            qlabel->setPixmap(pix);
            qlabel->setScaledContents(true);
            qlabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
            qlabel->setName(teamName[i][j]);
            listLabel->push_back(qlabel);
            addLabel(qlabel, j * 2, i);

            myLabel *qlabelName = new myLabel;
            qlabelName->setText(QString::fromStdString(teamName[i][j]));
            qlabelName->setAlignment(Qt::AlignVCenter);
            qlabelName->setAlignment(Qt::AlignHCenter);
            qlabel->setName(teamName[i][j]);
            listLabel->push_back(qlabelName);
            addLabel(qlabelName, j * 2 + 1, i);
        }
    }

    for (int i = 0; i < 60; i++)
        connect(listLabel->at(i), &myLabel::clickedForName, this, &pageData::setTeamName);
}

pageData::~pageData()
{
    delete ui;
}

void pageData::setTeamName(string name)
{
   emit showPageTeam(name);
}


void pageData::addLabel(myLabel *label, int row, int col)
{
    ui->gridLayoutTeam->addWidget(label, row, col);
}
