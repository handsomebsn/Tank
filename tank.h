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
     static int steps[8];
     static float lifes[8];
     static float wulis[8];
     static float fashus[8];
     static float hujias[8];
     static float mokangs[8];
     static int gongjijianges[8];
   int  group;//坦克所在组
   // 计算势力范围
   virtual void CalculateSphere();
public:
   friend class Bullet;
    Tank();
    Tank(int iIndex,int jIndex,Dir dir=UP,int style=0,int group=1);


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
   bool nextsiboom();


private:
    int style;
    bool ismove;
    bool isfire;
    int gongjijiange;

};

#endif // TANK_H
