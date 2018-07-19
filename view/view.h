#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

#include "pageStart.h"
#include "pageRank.h"
#include "pageData.h"
#include "pageTeam.h"
#include "pagePlayer.h"

namespace Ui {
class view;
}

class view : public QMainWindow
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = 0);
    ~view();

private:
    Ui::view *ui;

    pageStart *page_start;
    pageRank *page_rank;
    pageData *page_data;
    pageTeam *page_team;
    pagePlayer *page_player;

    // switch pages
    void switchPageStart();
    void switchPageRank();
    void switchPageData();
    void switchPageTeam();
    void switchPagePlayer();

    // set commands
    // void setCommand(shared_ptr<command> pCommand);
    // view_receiver rec;
};

#endif // VIEW_H
