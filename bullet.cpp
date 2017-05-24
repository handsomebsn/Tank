#include "bullet.h"
#include"status.h"
Bullet::Bullet(const Tank &tank)
{
    m_dir=tank.m_dir;
    m_pos=tank.m_pos;
    style=tank.style/2;
    m_step=tank.m_step+10;
    wuli=tank.wuli;
    fashu-tank.fashu;
    m_bDisappear=false;
CalculateSphere();
}

void Bullet::Display(QPainter &paint){

    switch(m_dir){
        case UP:

           paint.drawImage(m_rectSphere,*glo.bulletimage,QRect(2*PICBULLETWIDTH,style*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
           //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(2*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
        case DOWN:
            paint.drawImage(m_rectSphere,*glo.bulletimage,QRect(0*PICBULLETWIDTH,style*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
            //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(0*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
        case LEFT:
            paint.drawImage(m_rectSphere,*glo.bulletimage,QRect(1*PICBULLETWIDTH,style*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
            //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(1*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
        case RIGHT:
            paint.drawImage(m_rectSphere,*glo.bulletimage,QRect(3*PICBULLETWIDTH,style*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//身体
            //paint.drawImage(xm_rectSphere,*glo.bulletimage,QRect(3*PICBULLETWIDTH,(style*2+1)*PICBULLETHEIGHT,PICBULLETWIDTH,PICBULLETHEIGHT));//炮塔
            break;
      }



}




void Bullet::Move(){


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


     for(int i=0;i<INUM;i++)
         for(int j=0;j<JNUM;j++)
          if(glo.gamemap->getcell(i,j))
          if(IsBoom(*glo.gamemap->getcell(i,j)))
          {glo.gamemap->getcell(i,j)->downlife(wuli,0);m_bDisappear=true;
          *glo.status=Status(*glo.gamemap->getcell(i,j));

          }




}




void Bullet::CalculateSphere(){


this->m_rectSphere.setRect(m_pos.x()-BULLETWIDTH/2,m_pos.y()-BULLETHEIGHT/2,BULLETWIDTH,BULLETHEIGHT);

}
