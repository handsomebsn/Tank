#include "tank.h"

Tank::Tank()
{
m_pos.setX(88);
m_pos.setY(99);
m_dir=UP;
ismove=false;
CalculateSphere();
}

void Tank::Display(QPainter &paint){
    switch(m_dir){
        case UP:
            paint.drawImage(m_rectSphere,tankimage,QRect(2*PICTANKWIDTH,style*2,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(m_rectSphere,tankimage,QRect(2*PICTANKWIDTH,style*2+1,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case DOWN:
            paint.drawImage(m_rectSphere,tankimage,QRect(0*PICTANKWIDTH,style*2,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(m_rectSphere,tankimage,QRect(0*PICTANKWIDTH,style*2+1,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case LEFT:
            paint.drawImage(m_rectSphere,tankimage,QRect(3*PICTANKWIDTH,style*2,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(m_rectSphere,tankimage,QRect(3*PICTANKWIDTH,style*2+1,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case RIGHT:
            paint.drawImage(m_rectSphere,tankimage,QRect(2*PICTANKWIDTH,style*2,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(m_rectSphere,tankimage,QRect(2*PICTANKWIDTH,style*2+1,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
      }

}
void Tank::Move()
{if(ismove==true){
    switch(m_dir){
        case UP:
            m_pos.setY(m_pos.y()-m_step);
            break;
        case DOWN:
            m_pos.setY(m_pos.y()+m_step);
            break;
        case LEFT:
            m_pos.setX(m_pos.x()-m_step);
            break;
        case RIGHT:
            m_pos.setX(m_pos.x()+m_step);
            break;
      }
    CalculateSphere();
 }
}
void Tank::CalculateSphere(){

this->m_rectSphere.setRect(m_pos.x()-TANKWIDTH/2,m_pos.y()-TANKHEIGHT/2,TANKWIDTH,TANKHEIGHT);

}
