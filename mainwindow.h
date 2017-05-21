//游戏类
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QPainter>
#include"main.h"
#include "gamemap.h"
#include"tank.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Gamestatus{mapedit=520,gameing,pause};//游戏状态,今天5 20纪念单身
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
void keyPressEvent(QKeyEvent *event);
void mouseMoveEvent(QMouseEvent *);
void mousePressEvent(QMouseEvent *);
void mouseReleaseEvent(QMouseEvent *event);
void paintEvent(QPaintEvent *event);
private:
int leftorright;//左右
int laststyle;//上一次方块样式
void setgame(Gamestatus status){gamestatus=status;}//设置游戏状态
Gamestatus gamestatus;
//
GameMap gamemap;
//

Tank player;
};

#endif // MAINWINDOW_H
