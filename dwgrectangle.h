#ifndef DWGRECTANGLE_H
#define DWGRECTANGLE_H

#include "dwgobject.h"

class DwgRectangle: public DwgObject
{
    Q_OBJECT
public:
    explicit DwgRectangle(QObject *parent = nullptr);
private:
    QRect m_rect;
public:
    virtual void Draw(QPainter *painter);
    virtual bool SetData(QPoint pt1,QPoint pt2);
};

#endif // DWGRECTANGLE_H
