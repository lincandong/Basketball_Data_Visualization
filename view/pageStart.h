#ifndef PAGESTART_H
#define PAGESTART_H

#include <QWidget>

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
    void showPageRank();
    void showPageData();

private slots:
    void on_buttonRank_clicked();

    void on_buttonData_clicked();

private:
    Ui::pageStart *ui;
};

#endif // PAGESTART_H
