#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dwgobject.h"
#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
enum DrawType
{
    DNone,
    DLine,
    DCircle,
    DRectangle,
    DPoint
};
class MainWindow : public QMainWindow
{
    qreal m_winScale = 1.0;            	// 用于记录视图缩放的比例的变量
    QTransform m_trans;                	// 用于记录当前视图的变换矩阵的变量
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<DwgObject *> m_mainlist;     // 定义了一个数组用于保存所有屏幕上绘制的图元对象
    DrawType curDrawType = DNone;            // 定义一个变量用来记录当前鼠标正在绘制哪种图元
    QPainter *m_painter = nullptr;  	      // 为了方便绘图，我们把绘图工具定义为一个指针对象


private slots:
    void on_actionOpen_triggered();

    void on_actionLine_triggered();

    void on_actionCircle_triggered();

    void on_actionRectangle_triggered();

    void on_actionPoint_triggered();

    void on_actionNew_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QVector<DwgObject*> mObjVec;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    // QWidget interface
protected:
    virtual void wheelEvent(QWheelEvent *event);

    // QWidget interface
protected:
    virtual void mouseMoveEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
