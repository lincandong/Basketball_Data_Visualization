#ifndef PAGEDATA_H
#define PAGEDATA_H

#include <QWidget>
#include <QList>
#include "myLabel.h"
#include "../common/dataType.h"

namespace Ui {
class pageData;
}

class pageData : public QWidget
{
    Q_OBJECT

public:
    QList<myLabel *> *listLabel;

    explicit pageData(QWidget *parent = 0);
    ~pageData();

    void setTeamName(string name);  // set team's name
    void initialize();              // initialize page elements

signals:
    void showPageTeam(string name);

private:
    Ui::pageData *ui;

    void addLabel(myLabel *label, int row, int col);    // add label to layout
};

#endif // PAGEDATA_H
