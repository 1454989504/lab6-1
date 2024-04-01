// dwgpoint.h 文件内容
#ifndef DWGPOINT_H
#define DWGPOINT_H

#include "dwgobject.h"

class DwgPoint : public DwgObject
{
    Q_OBJECT
public:
    explicit DwgPoint(QObject *parent = nullptr);
    using DwgObject::SetData;

private:


    // DwgObject interface
public:
    virtual void Draw(QPainter *painter);
    virtual bool SetData(QPoint pt1,QPoint pt2);
    QPoint mPoint;


};

#endif // DWGPOINT_H
