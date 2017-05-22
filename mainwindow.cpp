#include "mainwindow.h"
#include"QRect"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{   //初始发全局结构体
    glo.blockimage=new QImage(":/images/map_block.png");
    glo.tankimage=new QImage(":/images/player_tank.png");
    glo.gamemap=new GameMap();
    glo.player=new Tank();
    //
    gamestatus=gameing;
    laststyle=0;
    leftorright=1;
    timer=new QTimer(this);
    timer->setInterval(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(timefun()));
    timer->start();
}

MainWindow::~MainWindow()
{
timer->stop();
delete timer;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

setFixedSize(WIDTH,HEIGHT);
QPainter paint(this);
paint.begin(this);
glo.gamemap->Display(paint);
glo.player->Display(paint);
paint.end();
}




void MainWindow::keyPressEvent(QKeyEvent *event){
//当按键为M时设置游戏状态为mapedit
    if(event->key()==Qt::Key_M)
        {
            gamestatus=mapedit;
        }else if(event->key()==Qt::Key_G){
            gamestatus=gameing;
        }

    if(gamestatus==mapedit){
        if(event->key()==Qt::Key_S)
            {

                 glo.gamemap->savemap("1.dat");
             }
        else if(event->key()==Qt::Key_L)
            {

                glo.gamemap->loadmap("1.dat");
             }

     }else if(gamestatus==gameing){
          if(event->key()==Qt::Key_S)
             {

                 glo.player->setdir(DOWN);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_A)
            {

                 glo.player->setdir(LEFT);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_W)
             {
               glo.player->setdir(UP);glo.player->startmove();
             }
          else if(event->key()==Qt::Key_D)
          {
              glo.player->setdir(RIGHT);glo.player->startmove();

          }


     }
update();
}



void MainWindow::keyReleaseEvent(QKeyEvent *){
   glo.player->stopmove();
}

// 鼠标移动事件       默认情况下，触发事件需要按下鼠标，才能触发。可设置为自动触发:setMouseTracking(true);
void MainWindow::mouseMoveEvent(QMouseEvent *event){
//qDebug("left or rigth 1 or 2=》 %d",event->button() );
//qDebug("haha");
if(gamestatus==mapedit){
    int i,j;//地图块的二维编号地址
glo.gamemap->cal(event->x(),event->y(),i,j);
if(leftorright==1){//如果移动时候按下左键
glo.gamemap->setstyle(i,j,laststyle);
}
else{
 glo.gamemap->deletecell(i,j);

}

}//if(gamestatus==mapedit) end

update();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
int i,j;//地图块的二维编号地址
if(gamestatus==mapedit){
glo.gamemap->cal(event->x(),event->y(),i,j);

if(event->button()==Qt::LeftButton){

//qDebug("i %d",i);
//qDebug("j %d",j);
    leftorright=1;
laststyle=glo.gamemap->switchstyle(i,j);
}
else{
glo.gamemap->deletecell(i,j);
leftorright=2;
}
}//if(gamestatus==mapedit) end
update();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event){

//update();

}

void MainWindow::timefun(){

glo.player->Move();

qDebug("timeout");
update();
}
