#include "status.h"
#include<QColor>
Status::Status(const Wanwu &wanwu)
{
life=wanwu.life;
}

void Status::Display(QPainter &paint){

    paint.drawText(500,180,QString("life:")+QString::number(life));

}
