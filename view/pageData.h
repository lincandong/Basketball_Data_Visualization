#ifndef PAGEDATA_H
#define PAGEDATA_H

#include <QWidget>
#include <QList>
#include "myLabel.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "../common/dataType.h"
=======
#include "../common/data.h"
>>>>>>> aff148d556a7acb797fa639d41fcc4d63a296c6d
=======
#include "../common/data.h"
>>>>>>> origin/master

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

    void setTeamName(int value);
    void initialize();

signals:
    void showPageTeam(QString name);

private:
    Ui::pageData *ui;

    void addLabel(myLabel *label, int row, int col);
};

#endif // PAGEDATA_H
