#include "mainwindow.h"
#include"QRect"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

setFixedSize(WIDTH,HEIGHT);
QPainter paint(this);
paint.begin(this);
gamemap.Display(paint);
paint.end();
}




void MainWindow::keyPressEvent(QKeyEvent *event){



}
