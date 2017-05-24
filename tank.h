#ifndef TANK_H
#define TANK_H
#include"wanwu.h"
#include"main.h"
#include"gamemap.h"
class Tank : public Wanwu
{
public:
    Tank();
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
    //设置方向
    void setdir(Dir dir){m_dir=dir;}
    //坦克下一步 是否和地图块碰撞
   bool nextsiboom(){
    Tank tmp=*this;
    tmp.Move1();
    //qDebug("%d",tmp.m_rectSphere.right());
    //qDebug("%d",glo.gamemap->getcell(1,4)->m_rectSphere.left());
    for(int i=0;i<INUM;i++)
        for(int j=0;j<JNUM;j++)
            if(glo.gamemap->getcell(i,j)&&tmp.IsBoom(*glo.gamemap->getcell(i,j))){
               qDebug("-----------boom-------"); return true;
            }
    qDebug("---------------");
    return false;
   }


private:
    int style;
    bool ismove;

};

#endif // TANK_H
