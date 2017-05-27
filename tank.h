#ifndef TANK_H
#define TANK_H
#include"wanwu.h"
#include"main.h"
#include"gamemap.h"
#include"bullet.h"
class Tank : public Wanwu
{
protected:
    QList<Bullet*> bullets;
   int steps[8]={4,8,8,16,16,32,32,64};
   float wulis[8]={20,40,80,160,160,320,320,640};
   float fashus[8]={20,40,80,160,160,320,320,640};
   float hujias[8]={50,70,90,110,130,150,170,190};
   float mokangs[8]={50,70,90,110,130,150,170,190};
   int gongjijianges[8]={8,7,6,5,4,3,2,2};
public:
   friend class Bullet;
    Tank();
    Tank(int iIndex,int jIndex,int style,Dir=UP);
    Tank(int iIndex, int jIndex,Dir dir=UP,int style=0,float wuli=100,float life=200);
    // 计算势力范围
    virtual void CalculateSphere();

    // 绘图
    void Display(QPainter &paint);

    // 移动
    void Move();
    //
    void Move1();//fangzhi si xun huan
    //设置移动状态为开
    void startmove(){ismove=true;}
    //设置移动状态为关
    void stopmove(){ismove=false;}
    //
    void fire();
    void startfire();
    void stopfire();
    //设置方向
    void setdir(Dir dir){m_dir=dir;}
    //坦克下一步 是否和地图块碰撞
   bool nextsiboom(){
    Tank tmp=*this;
    tmp.Move1();
    //qDebug("%d",tmp.m_rectSphere.right());
    //qDebug("%d",glo.gamemap->getcell(1,4)->m_rectSphere.left());
    //
    for(int i=0;i<INUM;i++)
        for(int j=0;j<JNUM;j++)
            if(glo.gamemap->getcell(i,j)&&tmp.IsBoom(*glo.gamemap->getcell(i,j))){
               qDebug("-----------boom-------"); return true;
            }
    qDebug("---------------");
    //
    if(tmp.m_rectSphere.left()<0||tmp.m_rectSphere.right()>WIDTH||tmp.m_rectSphere.bottom()>HEIGHT||tmp.m_rectSphere.top()<0)
    return true;//

    return false;
   }


private:
    int style;
    bool ismove;
    bool isfire;
    int gongjijiange;

};

#endif // TANK_H
