#include "mapcell.h"
//QImage Mapcell::blockimage=QImage(":/images/map_block.png"); linux
float Mapcell::lifes[BLOCKSNUM]={30000,3000,2000,1000,800,700,600,20000,0,0,0,0,0};
float Mapcell::hujias[BLOCKSNUM]={1000,500,400,300,200,100,50,800,0,0,0,0,0};
float Mapcell::mokangs[BLOCKSNUM]={1000,500,400,300,200,100,50,800,0,0,0,0,0};
bool Mapcell::chuantous[BLOCKSNUM]={false,false,false,false,false,false,false,false,true,true,true,true,true};
bool Mapcell::chuantous1[BLOCKSNUM]={false,false,false,false,false,false,false,false,true,true,true,true,true};
Mapcell::Mapcell()
{
    this->m_pos.setX(8*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(8*CELLHEIGHT+CELLHEIGHT/2);
    this->CalculateSphere();
    this->m_bDisappear=false;
    this->style=0;//map_block.png总共有28小块
    this->life=lifes[this->style];
    this->hujia=hujias[this->style];
    this->mokang=mokangs[this->style];
    this->chuantou=chuantous[this->style];
    this->chuantou1=chuantous1[this->style];

}

Mapcell::Mapcell(int iIndex,int jIndex,int style){//护甲魔抗物理攻击魔法攻击攻击速度移动速度暂时用不到
    this->m_pos.setX(jIndex*CELLWIDTH+CELLWIDTH/2);
    this->m_pos.setY(iIndex*CELLHEIGHT+CELLHEIGHT/2);
    this->CalculateSphere();
    this->m_bDisappear=false;
    this->style=style%BLOCKSNUM;//map_block.png总共有28小块
    this->life=lifes[this->style];
    this->hujia=hujias[this->style];
    this->mokang=mokangs[this->style];
    this->chuantou=chuantous[this->style];
    this->chuantou1=chuantous1[this->style];
}


void Mapcell::Display(QPainter &paint){
int i,j;
cal(style,i,j);
if(!this->IsDisappear())
paint.drawImage(m_rectSphere,*glo.blockimage,QRect(j*PICWIDTH,i*PICHEIGHT,PICWIDTH,PICHEIGHT));//优化代码，速度飞一般
//paint.drawImage(m_rectSphere,QImage(":/images/map_block.png"),QRect(j*PICWIDTH,i*PICHEIGHT,PICWIDTH,PICHEIGHT));


}
void Mapcell::Move(){



}
