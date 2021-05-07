#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // initShortcuts();
    setAttribute(Qt::WA_TranslucentBackground, true);
    this->setFixedSize(QApplication::desktop()->width(),QApplication::desktop()->height());
}


//鼠标穿透事件
void MainWindow::passInputEvent(int wid)
{
    XRectangle *reponseArea = new XRectangle;
    reponseArea->x = 0;
    reponseArea->y = 0;
    reponseArea->width = 0;
    reponseArea->height = 0;

    //XShapeCombineRectangles(QX11Info::display(), wid, ShapeInput, 0, 0, reponseArea ,1 ,ShapeSet, YXBanded);
    XShapeCombineRectangles(QX11Info::display(), wid, ShapeInput, 0, 0, NULL, 0, ShapeSet, YXBanded);

    delete reponseArea;
}

//取消鼠标穿透
void MainWindow::unPassInputEvent(int wid, QSize size)
{
    XRectangle *reponseArea = new XRectangle;
    reponseArea->x = 0;
    reponseArea->y = 0;
    reponseArea->width = size.width();
    reponseArea->height = size.height();

    XShapeCombineRectangles(QX11Info::display(), wid, ShapeInput, 0, 0, reponseArea ,1 ,ShapeSet, YXBanded);

    delete reponseArea;
}

MainWindow::~MainWindow()
{
    delete ui;
}

