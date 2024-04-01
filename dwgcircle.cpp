#include "dwgcircle.h"
#include <QtMath>

DwgCircle::DwgCircle(QObject *parent)
    : DwgObject{parent}
{
}

bool DwgCircle::SetData(QPoint pt1, QPoint pt2)
{
    mCenPt = pt1;
    mRad = qSqrt((pt2.x()-pt1.x())*(pt2.x()-pt1.x())+
                 (pt2.y()-pt1.y())*(pt2.y()-pt1.y()));
}

void DwgCircle::Draw(QPainter *painter)
{
    painter->drawEllipse(mCenPt,mRad,mRad);
}
