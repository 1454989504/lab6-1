// dwgline.h文件内容
#ifndef DWGLINE_H
#define DWGLINE_H

#include "dwgobject.h"

class DwgLine : public DwgObject
{
    Q_OBJECT
public:
    explicit DwgLine(QObject *parent = nullptr);

private:


    // DwgObject interface
public:
    virtual void Draw(QPainter *painter);
    virtual bool SetData(QPoint pt1,QPoint pt2);
    QPointF mStartPt,mEndPt;

};

#endif // DWGLINE_H
