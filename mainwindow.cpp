#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{pix=QPixmap(500,500);
}

MainWindow::~MainWindow()
{

}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);



}




void MainWindow::keyPressEvent(QKeyEvent *event){



}
