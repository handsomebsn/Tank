#ifndef TANK_H
#define TANK_H
#include"wanwu.h"
#include"main.h"
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
    //设置移动状态为开
    void startmove(){ismove=true;}
    //设置移动状态为关
    void stopmove(){ismove=false;}
    //设置方向
    void setdir(Dir dir){m_dir=dir;}
private:
    int style;
    bool ismove;

};

#endif // TANK_H
