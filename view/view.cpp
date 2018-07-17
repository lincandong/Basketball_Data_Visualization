#include "view.h"
#include "ui_view.h"

////////// 需要实现的部分 //////////////
void view::set_cmd1(openfile* ptr)
{
    c1 = ptr;
}
/* ... */
///////////////////////////////////////

view::view(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::view)
{
    ui->setupUi(this);

    connect(ui->actionStart, &QAction::triggered, this, &view::switchPageStart);
    connect(ui->actionRank, &QAction::triggered, this, &view::switchPageRank);
    connect(ui->actionData, &QAction::triggered, this, &view::switchPageData);

    connect(ui->pushButtonRank, &QPushButton::clicked, this, &view::switchPageRank);
    connect(ui->pushButtonData, &QPushButton::clicked, this, &view::switchPageData);
}

view::~view()
{
    delete ui;
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
