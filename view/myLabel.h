#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <string>
using namespace std;

class myLabel : public QLabel
{
    Q_OBJECT

public:
    myLabel();
    void setValue(int v);
    int getValue() const;
    void setName(string name);
    string getName() const;

protected:
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void clickedForName(string name);

private:
    int value;
    string name;
};

#endif // MYLABEL_H
