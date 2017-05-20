#ifndef GAMEMAP_H
#define GAMEMAP_H

#include"mapcell.h"
#include<QRect>
#include"main.h"
class GameMap
{
private:
Mapcell *cells[INUM][JNUM];
public:
    GameMap();
    ~GameMap();
    void Display(QPainter &paint);
};

#endif // GAMEMAP_H
