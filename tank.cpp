#include "tank.h"

Tank::Tank()
{
m_pos.setX(32);
m_pos.setY(32);
m_step=8;
style=3;
m_dir=UP;
ismove=false;
isfire=false;
CalculateSphere();
}

Tank::Tank(int iIndex, int jIndex,Dir dir,int style,float wuli,float life){
    this->m_pos.setX(jIndex*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(iIndex*CELLHEIGHT+CELLHEIGHT/2);
    this->wuli=wuli;
    m_step=16;
    this->style=style;
    this->m_dir=m_dir;
    ismove=false;
    m_dir=dir;
    isfire=false;
    CalculateSphere();
}

Tank::Tank(int iIndex, int jIndex, int style, Dir dir){
    this->m_pos.setX(jIndex*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(iIndex*CELLHEIGHT+CELLHEIGHT/2);
    this->m_dir=dir;
    this->style=style;
    isfire=false;
    wuli=wulis[style];
    fashu=fashus[style];
    hujia=hujias[style];
    mokang=mokangs[style];
    m_step=steps[style];
    CalculateSphere();
}




void Tank::Display(QPainter &paint){
    QRect xm_rectSphere=m_rectSphere;
    switch(m_dir){
        case UP:

           paint.drawImage(m_rectSphere,*glo.tankimage,QRect(2*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
           paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(2*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case DOWN:
            paint.drawImage(m_rectSphere,*glo.tankimage,QRect(0*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(0*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case LEFT:
            paint.drawImage(m_rectSphere,*glo.tankimage,QRect(1*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(1*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
        case RIGHT:
            paint.drawImage(m_rectSphere,*glo.tankimage,QRect(3*PICTANKWIDTH,style*2*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//身体
            paint.drawImage(xm_rectSphere,*glo.tankimage,QRect(3*PICTANKWIDTH,(style*2+1)*PICTANKHEIGHT,PICTANKWIDTH,PICTANKHEIGHT));//炮塔
            break;
      }

}
void Tank::Move()
{
   if(nextsiboom())return;
   if(ismove==true){
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
    qDebug("move on");
 }
qDebug("move off");
}

void Tank::Move1()
{
   if(ismove==true){
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
    qDebug("yuce ");
 }
qDebug("move off");
}

void Tank::fire(){
if(isfire==true){
Bullet *newbullet=new Bullet(*this);
glo.playerbullets.append(newbullet);
}

}


void Tank::startfire(){

    isfire=true;

}

void Tank::stopfire(){



    isfire=false;
}



void Tank::CalculateSphere(){

this->m_rectSphere.setRect(m_pos.x()-TANKWIDTH/2,m_pos.y()-TANKHEIGHT/2,TANKWIDTH,TANKHEIGHT);

}
