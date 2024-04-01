// dwgpoint.cpp 文件内容
#include "dwgpoint.h"

DwgPoint::DwgPoint(QObject *parent)
    : DwgObject(parent)
{
}

void DwgPoint::Draw(QPainter *painter)
{
    painter->drawPoint(mPoint);
}

bool DwgPoint::SetData(QPoint point,QPoint point2)
{
    mPoint = point;
}
