#include "myLabel.h"

myLabel::myLabel()
{

}

void myLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        Q_UNUSED(event)
            emit clicked(value);
}

void myLabel::setValue(int v)
{
    value = v;
}

int myLabel::getValue() const
{
    return value;
}
