#include "dwgrectangle.h"
#include <QPainter>

DwgRectangle::DwgRectangle(QObject *parent)
    :DwgObject{parent}
{
}
bool DwgRectangle::SetData(QPoint pt1, QPoint pt2)
{
    int left = qMin(pt1.x(), pt2.x());
    int top = qMin(pt1.y(), pt2.y());
    int right = qMax(pt1.x(), pt2.x());
    int bottom = qMax(pt1.y(), pt2.y());

    // 计算矩形的宽度和高度
    int width = right - left;
    int height = bottom - top;

    // 更新矩形的位置和大小
    m_rect.setRect(left, top, width, height);

    // 标记需要重新绘制（如果你的类中有类似的机制的话）

    // 假设这个函数总是成功的，返回true
    // 如果有必要，可以添加错误检查和返回false
    return true;
}

void DwgRectangle::Draw(QPainter *painter)
{
    painter->drawRect(m_rect);
}
