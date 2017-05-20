#include "mainwindow.h"
#include <QApplication>
QImage blockimage=QImage(":/images/map_block.png");
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
