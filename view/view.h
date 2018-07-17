#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <QStackedWidget>
////////// 需要实现的部分 ////////////////////////////
#include "..\command\inherit\openfile.h"

class view
{
private:
    //QPushButtion* q;
    /* ... */
    
    openfile* c1;
    /* ... */
public:
    void set_cmd1(openfile* ptr);
    /* ... */

    view_receiver rec;
}
///////////////////////////////////////////////////
namespace Ui {
class view;
}

class view : public QMainWindow
{
    Q_OBJECT

public:
    explicit view(QWidget *parent = 0);
    ~view();

    void switchPageStart();
    void switchPageRank();
    void switchPageData();

private:
    Ui::view *ui;
};

#endif // VIEW_H
