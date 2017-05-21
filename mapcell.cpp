#include "mapcell.h"
//QImage Mapcell::blockimage=QImage(":/images/map_block.png"); linux

Mapcell::Mapcell()
{

}

void Mapcell::Display(QPainter &paint){
int i,j;
cal(style,i,j);
if(!this->IsDisappear())
paint.drawImage(m_rectSphere,blockimage,QRect(j*PICWIDTH,i*PICHEIGHT,PICWIDTH,PICHEIGHT));

//paint.drawImage(m_rectSphere,QImage(":/images/map_block.png"),QRect(64,0,PICWIDTH,PICHEIGHT));//优化代码，速度飞一般

}
void Mapcell::Move(){



}
