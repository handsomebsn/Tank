#ifndef MAPCELL_H
#define MAPCELL_H

#include"wanwu.h"
#include"main.h"
class Mapcell : public Wanwu
{
public:

    Mapcell();
    Mapcell(int iIndex,int jIndex){


        this->m_pos.setX(jIndex*CELLWIDTH+CELLWIDTH/2);
        this->m_pos.setY(iIndex*CELLHEIGHT+CELLHEIGHT/2);
        this->CalculateSphere();

    }
    // 绘图
    void Display(QPainter &paint);

    // 移动
   void Move();
private:
static QImage blockimage;
void CalculateSphere(){
    this->m_rectSphere.setRect(m_pos.x()-CELLWIDTH/2,m_pos.y()-CELLHEIGHT/2,CELLWIDTH,CELLHEIGHT);

}


};

#endif // MAPCELL_H
