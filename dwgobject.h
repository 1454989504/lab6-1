#ifndef DWGOBJECT_H
#define DWGOBJECT_H

#include <QColor>
#include <QObject>
#include <QPainter>

class DwgObject : public QObject
{
    Q_OBJECT
public:
    explicit DwgObject(QObject *parent = nullptr);
    ~DwgObject() = 0;

    virtual void Draw(QPainter * painter) = 0;				// 纯虚函数不需要在基类中实现
    virtual bool SetData(QPoint pt1,QPoint pt2) = 0;
private:
    int mLineWidth = 0;								// 我们可以后面添加对它们的操作函数
    QColor mLineColor = Qt::black;

signals:
};

#endif // DWGOBJECT_H
