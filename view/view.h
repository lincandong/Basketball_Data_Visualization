#ifndef VIEW_H
#define VIEW_H
#include "..\command\base\command.h"
#include "..\notification\inherit\view_receiver.h"

#include <QMainWindow>
#include <QStackedWidget>
////////// 需要实现的部分 ////////////////////////////
#include "..\command\inherit\openfile.h"

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
    
    void set_cmd1(command*& ptr);
    /* ... */

    view_receiver rec;
private:
    Ui::view *ui;

    //QPushButtion* q;
    /* ... */
    
    command* c1;
    /* ... */
};

#endif // VIEW_H
