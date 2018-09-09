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
    void setName(QString name);
    QString getName() const;

protected:
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void clicked(int value);
    void clickedForName(QString name);

private:
    int value;
    QString name;
};

#endif // MYLABEL_H
