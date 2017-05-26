#ifndef BULLET_H
#define BULLET_H

#include"wanwu.h"
#include"tank.h"
class Bullet : public Wanwu
{
public:
    Bullet(const Tank &tank);
    // 绘图
  void Display(QPainter &paint) ;

    // 移动
    void Move() ;
    //
    void CalculateSphere();
private:
    int style;

};

#endif // BULLET_H
