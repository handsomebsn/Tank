#include "mainwindow.h"
#include"QRect"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{gamestatus=gameing;
    laststyle=0;
    leftorright=1;
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
//当按键为M时设置游戏状态为mapedit
    if(event->key()==Qt::Key_M)
        {
            gamestatus=mapedit;
        }
    else if(event->key()==Qt::Key_S&&gamestatus==mapedit)
      {

        gamemap.savemap("1.dat");
        }
    else if(event->key()==Qt::Key_L&&gamestatus==mapedit)
    {

        gamemap.loadmap("1.dat");update();
    }


}

// 鼠标移动事件       默认情况下，触发事件需要按下鼠标，才能触发。可设置为自动触发:setMouseTracking(true);
void MainWindow::mouseMoveEvent(QMouseEvent *event){
//qDebug("left or rigth 1 or 2=》 %d",event->button() );
//qDebug("haha");
if(gamestatus==mapedit){
    int i,j;//地图块的二维编号地址
gamemap.cal(event->x(),event->y(),i,j);
if(leftorright==1){//如果移动时候按下左键
gamemap.setstyle(i,j,laststyle);
}
else{
 gamemap.deletecell(i,j);

}

}//if(gamestatus==mapedit) end

update();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
int i,j;//地图块的二维编号地址
if(gamestatus==mapedit){
gamemap.cal(event->x(),event->y(),i,j);

if(event->button()==Qt::LeftButton){

//qDebug("i %d",i);
//qDebug("j %d",j);
    leftorright=1;
laststyle=gamemap.switchstyle(i,j);
}
else{
gamemap.deletecell(i,j);
leftorright=2;
}
}//if(gamestatus==mapedit) end
update();

}
void MainWindow::mouseReleaseEvent(QMouseEvent *event){

//update();
}


