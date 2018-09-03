#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT

public:
    myLabel();
    void setValue(int v);
    int getValue() const;

protected:
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void clicked(int value);

private:
    int value;
};

#endif // MYLABEL_H
