#include "tank.h"

Tank::Tank()
{
    this->m_pos.setX(10*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(8*CELLHEIGHT+CELLHEIGHT/2);
    this->wuli=200;
    this->group=0;//0玩家组，1敌人组
    m_step=16;
    gongjijiange=3;
    this->style=0;
    ismove=false;
    m_dir=UP;
    isfire=false;
    m_bDisappear=false;
    life=1000;
    CalculateSphere();
}


Tank::Tank(int iIndex,int jIndex,Dir dir,int style,int group){
    this->m_pos.setX(jIndex*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(iIndex*CELLHEIGHT+CELLHEIGHT/2);
    this->m_dir=dir;
    this->style=style;
    this->group=group;
    isfire=false;
    wuli=wulis[style];
    fashu=fashus[style];
    hujia=hujias[style];
    mokang=mokangs[style];
    m_step=steps[style];
    gongjijiange=gongjijianges[style];
    m_bDisappear=false;
    life=lifes[style];
    CalculateSphere();
}




void Tank::Display(QPainter &paint){
    for(int i=0;i<bullets.count();i++)
        if(bullets.at(i)&&!bullets.at(i)->IsDisappear())
    bullets.at(i)->Display(paint);
        else if(bullets.at(i)){
            delete bullets.at(i);//回收new出来的对象空间
            bullets.removeAt(i);//将对象指针从链表删除
            i--;
        }

    QRect xm_rectSphere=m_rectSphere;
    if(m_bDisappear)return;
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
    for(int i=0;i<bullets.count();i++)
    bullets.at(i)->Move();

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
if(isfire==true&&glo.framei%gongjijiange==0){
Bullet *newbullet=new Bullet(*this);
bullets.append(newbullet);
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
