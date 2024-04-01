#include "dwgline.h"

DwgLine::DwgLine(QObject *parent)
    : DwgObject{parent}
{
}

void DwgLine::Draw(QPainter *painter)
{
    painter->drawLine(mStartPt,mEndPt);
}

bool DwgLine::SetData(QPoint pt1, QPoint pt2)
{
    mStartPt = pt1,mEndPt = pt2;
}
