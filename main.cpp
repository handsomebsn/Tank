#include "main.h"
#include "mainwindow.h"
#include <QApplication>
Glo glo;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
