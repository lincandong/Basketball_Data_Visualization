#ifndef PAGESTART_H
#define PAGESTART_H

#include <QWidget>
//#include "../commands/command.h"

namespace Ui {
class pageStart;
}

class pageStart : public QWidget
{
    Q_OBJECT

public:
    explicit pageStart(QWidget *parent = 0);
    ~pageStart();

    //void setTeamRankCommand(std::shared_ptr<command> ptr);

signals:
    void showPageData();
    void showPageRank();

private slots:
    void on_buttonRank_clicked();
    void on_buttonData_clicked();

private:
    Ui::pageStart *ui;

   // std::shared_ptr<rankParameter> para;
    //std::shared_ptr<command> teamRankCommand;
};

#endif // PAGESTART_H
