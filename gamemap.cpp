#include "gamemap.h"

GameMap::GameMap()
{
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)
        cells[i][j]=NULL;
for(int i=0;i<INUM;i++)
    for(int j=0;j<JNUM;j++)

       cells[i][j]=new Mapcell(i,j);

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

