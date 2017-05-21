#include "gamemap.h"

GameMap::GameMap()
{
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)
        cells[i][j]=NULL;
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)
;
       //cells[i][j]=new Mapcell(i,j,i);

}\
GameMap::~GameMap(){
    for(int i=0;i<INUM;i++)
        for(int j=0;j<JNUM;j++)
           {delete cells[i][j] ;cells[i][j]=NULL;}
}

void GameMap::Display(QPainter &paint){

paint.drawImage(QRect(0,0,WIDTH,HEIGHT),QImage(":/images/background.bmp"));
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)
    {
        if(cells[i][j]!=NULL)
            cells[i][j]->Display(paint);

    }

}


void GameMap::setstyle(int i, int j, int style){
    if(i>=INUM||j>=JNUM)
    {qDebug("数组越界");return ;}
     if(cells[i][j])
         cells[i][j]->setstyle(style);
     else{
         cells[i][j]=new Mapcell(i,j,style);

     }
}


void GameMap::deletecell(int i, int j){
    if(i>=INUM||j>=JNUM)
    {qDebug("数组越界");return;}
    delete cells[i][j];
   cells[i][j]=NULL;

}
