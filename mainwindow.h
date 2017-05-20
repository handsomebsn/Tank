#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<QPainter>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
void keyPressEvent(QKeyEvent *event);
void paintEvent(QPaintEvent *event);
private:
QPixmap pix;


};

#endif // MAINWINDOW_H
