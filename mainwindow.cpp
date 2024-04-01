#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "dwgline.h"
#include "dwgcircle.h"
#include "dwgrectangle.h"
#include "dwgpoint.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QMessageBox::information(this,"Open Menu Clicked!","OK");
}



void MainWindow::paintEvent(QPaintEvent *event)
{
    m_painter = new QPainter(this);
    for(auto& i : m_mainlist)
        i->Draw(m_painter);
}

void MainWindow::on_actionLine_triggered()
{
    curDrawType = DLine;
}
void MainWindow::on_actionCircle_triggered()
{
    curDrawType = DCircle;
}
void MainWindow::on_actionRectangle_triggered()
{
    curDrawType = DRectangle;
}
void MainWindow::on_actionPoint_triggered()
{
    curDrawType = DPoint;
}
void MainWindow::on_actionNew_triggered()
{
    qDeleteAll(m_mainlist);     // 删除所有的图元对象
    m_mainlist.clear();		 //  清空m_mainlist
    update();
    ui->statusbar->showMessage("开始绘制一张新的图纸：",3000);
}
void MainWindow::on_actionExit_triggered()
{
    qDeleteAll(m_mainlist);     // 删除所有的图元对象
    m_mainlist.clear();		 //  清空m_mainlist
    this->close();
}

bool isFirst=true;                  // 用于判断鼠标点击行为是第一点还是第二点
QPoint temppt;
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(curDrawType == DPoint)                    // 判断当前绘制对象为点
    {
        DwgPoint* temppt = new DwgPoint;
        temppt->mPoint = event->pos(); // 或者使用 SetData 方法
        m_mainlist.append(temppt);
    }
    if(curDrawType == DLine)					// 判断当前绘制对象为直线
    {
        if(isFirst)
        {   temppt = event->pos();
            isFirst = false;
        }
        else
        {   DwgLine * templine = new DwgLine;
            templine->mStartPt = temppt;
            templine->mEndPt = event->pos();
            m_mainlist.append(templine);
            isFirst = true;
        }
    }
    if(curDrawType == DCircle)
    {
        if(isFirst)
        {
            temppt = event->pos();
            isFirst = false;
        }
        else
        {
            DwgCircle *circle = new DwgCircle;            // 创建并初始化一个直线对象
            circle->SetData(temppt,event->pos());		// 使用SetData函数设置私有成员变量
            m_mainlist.append(circle);                     // append函数用于把对象添加到数组mLines中
            update();                                   // 该函数用于刷新窗口
            isFirst = true;
        }
    }
    if(curDrawType == DRectangle)
    {
        if(isFirst)
        {
            temppt = event->pos();
            isFirst = false;
        }
        else
        {
            DwgRectangle *Rectangle = new DwgRectangle;            // 创建并初始化一个直线对象
            Rectangle->SetData(temppt,event->pos());		// 使用SetData函数设置私有成员变量
            m_mainlist.append(Rectangle);                     // append函数用于把对象添加到数组mLines中
            update();                                   // 该函数用于刷新窗口
            isFirst = true;
        }
    }

    update();
}











