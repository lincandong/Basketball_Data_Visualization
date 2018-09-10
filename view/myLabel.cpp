#include "myLabel.h"

myLabel::myLabel()
{
    name = " ";
}

void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        Q_UNUSED(event)
        emit clickedForName(name);
}

void myLabel::setValue(int v)
{
    value = v;
}

int myLabel::getValue() const
{
    return value;
}

void myLabel::setName(string name)
{
    this->name = name;
}

string myLabel::getName() const
{
    return name;
}
