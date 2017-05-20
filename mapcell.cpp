#include "mapcell.h"
//QImage Mapcell::blockimage=QImage(":/images/map_block.png"); linux

Mapcell::Mapcell()
{

}

void Mapcell::Display(QPainter &paint){

if(!this->IsDisappear())
paint.drawImage(m_rectSphere,blockimage,QRect(0,0,PICWIDTH,PICHEIGHT));

//paint.drawImage(m_rectSphere,QImage(":/images/map_block.png"),QRect(64,0,PICWIDTH,PICHEIGHT));//优化代码，速度飞一般

}
void Mapcell::Move(){



}
