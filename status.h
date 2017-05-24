#ifndef STATUS_H
#define STATUS_H

#include"wanwu.h"
class Status
{
public:
    float life;
    Status(){life=0;}
    Status(const Wanwu &wanwu);
    void Display(QPainter &paint);
};

#endif // STATUS_H
