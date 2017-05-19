#ifndef MAP_H
#define MAP_H
#include"mapcell.h"

class Map
{
private:
Mapcell *cells[30][30];
public:
    Map();
};

#endif // MAP_H
