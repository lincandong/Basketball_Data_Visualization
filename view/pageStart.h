#ifndef PAGESTART_H
#define PAGESTART_H

#include <QWidget>
<<<<<<< HEAD
#include "../commands/base/command.h"
=======
#include "../commands/command.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d

namespace Ui {
class pageStart;
}

class pageStart : public QWidget
{
    Q_OBJECT

public:
    explicit pageStart(QWidget *parent = 0);
    ~pageStart();

signals:
    void showPageData();
    void showPageRank();

private slots:
    void on_buttonRank_clicked();
    void on_buttonData_clicked();

private:
    Ui::pageStart *ui;
};

#endif // PAGESTART_H
